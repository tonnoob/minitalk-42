/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:32:10 by osousa-d          #+#    #+#             */
/*   Updated: 2025/11/11 18:32:14 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler_signal(int sig)
{
	static int				bit;
	static unsigned char	byte;
	static __pid_t 			pid_client;

	if (!pid_client)
		pid_client = info->si_pid;
	if (sig == SIGUSR1)
		byte |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (!byte)
		{	
			pid_client = 0;
			write(1, &byte, 1);
			write(1, "\n", 1)
		}
		else
		write(1, &byte, 1);
		bit = 0;
		byte = 0;
		kill(pid_client, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = handler_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);essa part
	while (1)
	{
		pause();
	}
}
