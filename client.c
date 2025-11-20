/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:22:11 by osousa-d          #+#    #+#             */
/*   Updated: 2025/11/20 13:55:36 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(unsigned char byte, __pid_t server_pid)
{
	int	bit;	

	bit = 7;
	while (bit >= 0)
	{
		if ((byte >> bit) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		bit--;
		pause();
	}
}

static void	client_handler(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
}

int	main(int argc, char **argv)
{
	__pid_t				server_pid;
	struct sigaction	sa;
	int					i;

	sa.sa_sigaction = client_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	if (argc != 3)
	{
		ft_printf("Invalid argument\n");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_message((unsigned char)argv[2][i], server_pid);
		i++;
	}
	send_message('\0', server_pid);
}
