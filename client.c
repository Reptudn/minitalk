/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:13:04 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/29 12:26:27 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/_types/_sigset_t.h>
#include <sys/signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "./lib/libft/libft.h"

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
			usleep(250);
		}
		str++;
		usleep(250);
	}
	write(1, "Message sent!\n", 15);
}

int	main(int argc, char **argv)
{
	int					pid;

	if (argc != 3)
	{
		write(1, "Invalid arguments\n", 18);
		write(1, "Usage: ./client <pid> <message>\n", 33);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(1, "Invalid PID or failed to set signal handler\n", 45);
		return (0);
	}
	send_message(argv[2], pid);
	return (0);
}
