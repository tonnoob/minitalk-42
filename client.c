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

volatile sig_atomic_t	g_ack = 1;

static void	ack_client(int sig)
{
	if (sig == SIGUSR1)
		g_ack = 0;
	else if (sig == SIGUSR2)
	{
		ft_printf("✅ FINISH!\n");
		exit (0);
	}
}

void	send_message(unsigned char byte, __pid_t server_pid)
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

	sa.sa_handler = ack_client;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc != 3)
	{
		ft_printf("Invalid argument\n");
		exit(EXIT_FAILURE);
	}
	server_pid = (__pid_t)ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		printf("Invalid PID\n");
		return (EXIT_FAILURE);
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
