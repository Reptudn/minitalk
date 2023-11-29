/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:10:59 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/29 10:37:57 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/_types/_pid_t.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "./lib/ft_printf/ft_printf.h"
#include "./lib/libft/libft.h"


/*
**	Server uses SIGUSR1
**	Client uses SIGUSR2
*/

char	*g_last_received = 0;

// void	send_message(char *str)
// {
// 	int	pid;
// 	int	c;
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		c = str[i];
// 		kill(pid, SIGUSR2);
// 		i++;
// 	}
// }

void	handle_recieve(int signal)
{
	static int	count = 0;
	static int	byte = 0;
	int			len;

	len = 0;
	if (signal != SIGUSR1)
		return ;
	ft_printf("Received signal: %d\n", signal);
	if (count == 8)
	{
		write(1, &byte, 1);
		if (!g_last_received)
		{
			g_last_received = malloc(2 * sizeof(char));
			g_last_received[0] = byte;
			g_last_received[1] = 0;
		}
		len = ft_strlen(g_last_received);
		g_last_received = realloc(g_last_received, (len + 2) * sizeof(char));
		g_last_received[len] = byte;
		g_last_received[len + 1] = 0;
		count = 0;
		byte = 0;
	}
	byte += 1;
	byte = byte << 1; // ckeck if this is correct?
}

int	main(void)
{
	int	pid;

	pid = getpid();
	if (pid <= 0)
		return (0);
	ft_printf("%d\n", pid);
	if (signal(SIGUSR1, handle_recieve) == SIG_ERR)
	{
		ft_printf("Error: Could not register signal handler\n");
		return (0);
	}
	while (1)
	{
		usleep(100);
	}
}
