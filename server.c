/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiras-s <jmiras-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:07:23 by jmiras-s          #+#    #+#             */
/*   Updated: 2023/08/02 18:47:33 by jmiras-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	byte(int sig)
{
	int	c = 0;
	int	num_bit = 0;

	if (sig == SIGUSR1)
		c = (c | (128 >> num_bit));
	num_bit++;
	if (num_bit == 8)
	{
		ft_printf("%c", c);
		num_bit = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	if (ft_printf("%i\n", pid) == -1)
		exit(1);
	while (1)
	{
		signal(SIGUSR2, byte);
		signal(SIGUSR1, byte);
		pause();
	}
	return (0);
}
