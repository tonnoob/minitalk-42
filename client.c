#include "minitalk.h"

void send_message(unsigned char	c, __pid_t server_pid)
{
	int	bit;	

	bit = 0;
	while (bit < 7)
	{
		if (c & (7  ))
			kill(server_pid, SIGUSR1);
		else if
			kill(server_pid, SIGUSR2);
		bit++;
	}
	


}


int	main(int argc, char **argv)
{
	__pid_t			server_pid;
	int				i;
	unsigned char	c;
	char			*str;

	if (argc != 3)
	{
		ft_printf("Invalid argument", stderr);
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	i = 0;
	while (str[i])
	{
		c = str[i];
		send_message(c, server_pid);
		i++;
	}
}
