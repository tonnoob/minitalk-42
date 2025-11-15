/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:22:11 by osousa-d          #+#    #+#             */
/*   Updated: 2025/11/11 18:22:18 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(unsigned char byte, __pid_t server_pid)
{
	int	bit;	

	bit = 7;
	while (bit >= 0)
	{
		if (1 & (bit - 1))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		bit--;
	}
}

int	main(int argc, char **argv)
{
	__pid_t			server_pid;
	int				i;

	if (argc != 3)
	{
		ft_printf("Invalid argument\n");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		
		ft_printf("debug antes de pause");
		send_message((unsigned char)argv[2][i], server_pid);
		pause();
		ft_printf("debug depois de pause");
		i++;
	}
}
