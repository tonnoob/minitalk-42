/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:32:10 by osousa-d          #+#    #+#             */
/*   Updated: 2025/11/23 22:28:16 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void handler_signal(int sig, siginfo_t *info, void *context)
{
	static int				bit;
	static unsigned char	byte;
	static __pid_t			pid_client;

	if (pid_client == 0)
		pid_client = info->si_pid;
	if (sig == SIGUSR1)
		byte |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		bit = 0;
		if (byte == '\0')
		{
			kill(pid_client, SIGUSR2);
			pid_client = 0;
			return ;
		}
		else
		{
			write(1, &byte, 1);
			byte = 0;
		}
	}
	kill(pid_client, SIGUSR1);
}

int main(void)
{
	struct sigaction sa;

	ft_printf("%d\n", getpid());
	sa.sa_sigaction = handler_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
		pause();
}
