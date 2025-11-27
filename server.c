#include "minitalk.h"

static void	handler_signal(int sig)
{
	static int				bit;
	static unsigned char	byte;

	if (sig == SIGUSR1)
		byte |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (byte == '\0')
			write(1, "\n", 1);
		else
			write(1, &byte, 1);
		byte = 0;
		bit = 0;
	}
}

int	main(void)
{
	ft_printf("PID Server: %d\n", getpid());
	signal(SIGUSR1, handler_signal);
	signal(SIGUSR2, handler_signal);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}