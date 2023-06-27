/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiras-s <jmiras-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:07:23 by jmiras-s          #+#    #+#             */
/*   Updated: 2023/06/08 17:30:38 by jmiras-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
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

int main() 
{
	pid_t server_pid;
	server_pid = getpid();
    	if (printf("PID del servidor: %d\n", server_pid == -1);
	
	while (1)
	{
		signal(SIGUSR1, byte);
   		signal(SIGUSR2, byte);
		pause();
	}
	return 0;
}
