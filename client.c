/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */o
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:41:57 by osousa-d          #+#    #+#             */
/*   Updated: 2025/12/28 14:09:16 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack = 1;

static void	ack_client(int sig)
{
	if (sig == SIGUSR1)
		g_ack = 0;
}

static void	send_message(unsigned char byte, __pid_t server_pid)
{
	int	bit;

	bit = 0;
	while (bit <= 7)
	{
		g_ack = 1;
		if ((byte >> bit) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		while (g_ack)
			pause();
		bit++;
	}
}

int	main(int argc, char **argv)
{
	__pid_t				server_pid;
	struct sigaction	sa;
	int					i;

	server_pid = (__pid_t)ft_atoi(argv[1]);
	if (argc != 3 || server_pid <= 0 || server_pid > 4194304)
	{
		ft_printf("Error! Check arguments and PID\n");
		exit(EXIT_FAILURE);
	}
	sa.sa_handler = ack_client;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	i = 0;
	while (argv[2][i])
	{
		send_message((unsigned char)argv[2][i], server_pid);
		i++;
	}
	send_message((unsigned char)argv[2][i], server_pid);
	return (EXIT_SUCCESS);
}
