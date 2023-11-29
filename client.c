/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:13:04 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/29 10:13:21 by jkauker          ###   ########.fr       */
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

void	send_message(char *str)
{
	// bascially same as in server
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
	send_message(argv[2]);
	return (0);
}