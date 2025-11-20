/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:32:10 by osousa-d          #+#    #+#             */
/*   Updated: 2025/11/20 13:57:00 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	accumulate_buffer(unsigned char byte)
{
	int		i;
	char	*buffer;

	buffer = NULL;
	i = 0;
	if (byte != 0)
	{
		buffer[i] = byte;
		i++;
	}
	if (byte == 0)
		ft_printf("%s\n", buffer);
}

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
	kill(pid_client, SIGUSR1);
	bit++;
	if (bit == 8)
	{
		accumulate_buffer(byte);
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
