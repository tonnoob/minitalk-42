#include "minitalk.h"

void send_message(unsigned char	byte, __pid_t server_pid)
{
	int	byte;	

	byte = 0;
	while (byte < 7)
	{
		if (c & (byte << 7))
			kill(server_pid, SIGUSR1);
		else if
			kill(server_pid, SIGUSR2);
		byte++;
	}
	


}


int	main(int argc, char **argv)
{
	__pid_t			server_pid;
	int				i;
	char			*str;

	if (argc != 3)
	{
		ft_printf(stderr, "Invalid argument", );
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	i = 0;
	while (str[i])
	{
		send_message((unsigned char)str[i], server_pid);
		i++;
	}
}
