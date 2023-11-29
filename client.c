/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:13:04 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/29 12:06:02 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/_types/_sigset_t.h>
#include <sys/signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "./lib/ft_printf/ft_printf.h"
#include "./lib/libft/libft.h"

void	handle_receive(int signal)
{
	printf("Received signal: %d\n", signal);
}

void	send_message(char *str, int pid)
{
	int		i;

	if (!str || !pid)
		return ;
	while (*str)
	{
		i = 7;
		while (i + 1)
		{
			if (*str & (1 << i))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i--;
			usleep(100);
		}
		str++;
		usleep(100);
	}
	write(1, "Message sent!\n", 15);
}

int	main(int argc, char **argv)
{
	int					pid;

	if (argc != 3)
	{
		printf("Invalid arguments\n");
		printf("Usage: %s <pid> <message>\n", argv[0]);
		return (0);
	}
	pid = atoi(argv[1]);

	if (pid <= 0 || signal(SIGUSR2, handle_receive) == SIG_ERR)
	{
		printf("Invalid PID or failed to set signal handler\n");
		return (0);
	}
	printf("PID: %d\n", pid);
	printf("Message: %s\n", argv[2]);
	send_message(argv[2], pid);
	return (0);
}
