/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:13:04 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/29 10:29:42 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "./lib/ft_printf/ft_printf.h"
#include "./lib/libft/libft.h"

void	handle_receive()
{
	// basically same as in server
}

void	send_message(char *str, int pid)
{
	if (!str || !pid)
		return ;
	while (*str)
	{
		if (kill(pid, *str) == -1)
		{
			ft_printf("Error sending signal\nExiting...\n");
			exit(1);
		}
		ft_printf("Sent signal: %d\n", *str);
		str++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (0);
	signal(SIGUSR2, handle_receive);
	send_message(argv[2], pid);
	return (0);
}
