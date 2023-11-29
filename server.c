/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:10:59 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/29 12:45:59 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "./lib/libft/libft.h"
#include "./lib/ft_printf/ft_printf.h"

/*
**	1 is SIGUSR1
**	0 is SIGUSR2
*/

void	handle_recieve(int signal)
{
	static int	count = 0;
	static char	last_received = 0;

	if (signal == SIGUSR1)
	{
		last_received = last_received << 1;
		last_received = last_received | 1;
	}
	else
	{
		last_received = last_received << 1;
		last_received = last_received | 0;
	}
	count++;
	if (count == 8)
	{
		write(1, &last_received, 1);
		count = 0;
		last_received = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	if (pid <= 0)
		return (0);
	ft_printf("%d\n", pid);
	signal(SIGUSR1, handle_recieve);
	signal(SIGUSR2, handle_recieve);
	while (1)
		usleep(100);
}
