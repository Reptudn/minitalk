#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <./lib/libftprintf.h>

void	handle_receive()
{
	// basically same as in server
}

void	send_message(char *str)
{
	// bascially same as in server
}

int main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (0);
	pid = atoi(argv[1]); /// replace with ft_atoi
	if (pid <= 0)
		return (0);
	signal(SIGUSR2, handle_receive);
	send_message(argv[2]);
	return (0);
}