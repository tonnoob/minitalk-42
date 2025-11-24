/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:22:11 by osousa-d          #+#    #+#             */
/*   Updated: 2025/11/24 01:19:29 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// static void handler_client(int sig, siginfo_t *info, void *context)
// {
// 	(void)info;
// 	(void)context;
// 	(void)sig;
// }

static void	ack_end(int sig)
{
	if (sig == SIGUSR2)
		write(1, "OK!", 3);
	else if (sig == SIGUSR1)

}

void	send_message(unsigned char byte, __pid_t server_pid)
{
	int	bit;
	
	bit = 0;
	while (bit <= 7)
	{
		if ((byte >> bit) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(2000);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	__pid_t	server_pid;
	int		i;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		signal(SIGUSR1, send_message);
		signal(SIGUSR2, ack_end);
		i = 0;
		while (argv[2][i])
		{
			send_message((unsigned char)argv[2][i], server_pid);
			i++;
		}
	}
	else
		ft_printf("Invalid argument\n");
		exit(EXIT_FAILURE);
}
