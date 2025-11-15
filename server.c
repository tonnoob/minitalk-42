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

static void	handler_signal(int sig, siginfo_t *info, void *context)
{
	static int				bit;
	static unsigned char	byte;
	static __pid_t			pid_client;

	(void)context;
	if (!pid_client)
		pid_client = info->si_pid;
	if (sig == SIGUSR1)
		byte |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		write(1, &byte, 1);
		kill(pid_client, SIGUSR1);
		if (byte == 0)
		{	
			write(1, "\n", 1);
			pid_client = 0;
		}
		bit = 0;
		byte = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
