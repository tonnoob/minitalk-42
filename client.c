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
	int	byte;	

	byte = 7;
	while (byte > 0)
	{
		if (1 & (byte << 7))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		byte--;
	}
}

int	main(int argc, char **argv)
{
	__pid_t			server_pid;
	int				i;
	char			*str;

	if (argc != 3)
	{
		ft_printf(stderr, "Invalid argument\n");
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
