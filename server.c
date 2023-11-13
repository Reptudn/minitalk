#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <./lib/libftprintf.h>


/*
**	Server uses SIGUSR1
**	Client uses SIGUSR2
*/

char	*last_received = 0;

void	send_message(char *str)
{
	int	pid;
	int	c;
	int	i;

	//pid ==  signal of client
	i = 0;
	while (str[i])
	{
		c = str[i]; // convert this to bits starting from the bit on the left;
		kill(pid, SIGUSR2); // now find out how to send right signal like 0 or 1?
		i++;
	}
}

void	handle_recieve(int signal)
{
	static int	count = 0;
	static int	byte = 0;
	int			len;

	len = 0;
	if (signal != SIGUSR1)
		return ;
	if (count == 8)
	{
		write(1, &byte, 1);
		if (!last_received)
		{
			last_received = malloc(2 * sizeof(char));
			last_received[0] = byte;
			last_received[1] = 0;
		}
		len = ft_strlen(last_received);
		last_received = realloc(last_received, (len + 2) * sizeof(char));
		last_received[len] = byte;
		last_received[len + 1] = 0;
		count = 0;
		byte = 0;
	}
	byte += 1;
	byte = byte << 1; // ckeck if this is correct?
}

int	stop_programm(int signal)
{
	// maybe use terminate signal to free everything and then quit
}

int main(void)
{
	int	pid;

	pid = getpid();
	if (pid <= 0)
		return (0);
	printf("%d", pid);
	signal(SIGUSR1, handle_recieve);
}