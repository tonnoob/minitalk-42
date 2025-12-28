/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:07:43 by osousa-d          #+#    #+#             */
/*   Updated: 2025/12/28 14:07:44 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler_signal(int sig, siginfo_t *info, void *context)
{
	static int				bit;
	static unsigned char	byte;
	static __pid_t			pid_client;

	(void)context;
	pid_client = info->si_pid;
	if (sig == SIGUSR1)
		byte |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (byte == '\0')
			write(1, "\n", 1);
		else
			write(1, &byte, 1);
		byte = 0;
		bit = 0;
	}
	kill(pid_client, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID Server: %d\n", getpid());
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
