/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:22:11 by osousa-d          #+#    #+#             */
/*   Updated: 2025/11/20 18:47:10 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		bit++;
		pause();
	}
}

static void	client_handler(int sig)
{
	(void)sig;
}

int	main(int argc, char **argv)
{
	__pid_t				server_pid;
	int					i;


	signal(SIGUSR1, client_handler);
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
	pause();
	return (0);
}
