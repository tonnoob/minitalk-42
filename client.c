#include "minitalk.h"

volatile sig_atomic_t	g_ack = 1;

void	send_message(unsigned char byte, __pid_t server_pid)
{
	int	bit;

	bit = 0;
	g_ack = 0;
	while (bit <= 7)
	{
		if ((byte >> bit) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		bit++;
		sleep(1000);
	}
}

int	main(int argc, char **argv)
{
	__pid_t	server_pid;
	int		i;

	server_pid = (__pid_t)ft_atoi(argv[1]);
	if (argc != 3 || server_pid <= 0 || server_pid > 4194304)
	{
		ft_printf("Error! Check arguments and PID\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (argv[2][i])
	{
		send_message((unsigned char)argv[2][i], server_pid);
		i++;
	}
	send_message((unsigned char)argv[2][i], server_pid);
	return (EXIT_SUCCESS);
}
