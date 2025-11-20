/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:32:10 by osousa-d          #+#    #+#             */
/*   Updated: 2025/11/20 18:28:27 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// static void	accumulate_buffer(unsigned char byte)
// {
// 	static int		i;
// 	static char		buffer[100000];

// 	if (byte != 0)
// 	{
// 		buffer[i] = byte;
// 		i++;
// 	}
// 	if (byte == 0)
// 	{
// 		buffer[i] = '\0';
// 		ft_printf("%s\n", buffer);
// 		i = 0;
// 	}
// }

static void	handler_signal(int sig)
{
	static int				bit;
	static unsigned char	byte;

	if (sig == SIGUSR1)
		byte |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &byte, 1);
		if (byte == 0)
		{	
			ft_printf("\n");
		}
		bit = 0;
		byte = 0;
	}
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, handler_signal);
	signal(SIGUSR2, handler_signal);
	while (1)
	{
		pause();
	}
}
