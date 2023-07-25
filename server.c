/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiras-s <jmiras-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:07:23 by jmiras-s          #+#    #+#             */
/*   Updated: 2023/07/25 18:06:12 by jmiras-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

<<<<<<< HEAD
void	byte(int sig)
{
	static int	c = 0;
	static int	num_bit = 0;
=======
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "minitalk.h"
void	byte(int sig)
{
	int	c = 0;
	int	num_bit = 0;
>>>>>>> 4cb902786160f79e0f9d5713a53883bcb768380c

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
<<<<<<< HEAD
	pid_t	pid;

	pid = getpid();
	if (ft_printf("%i\n", pid) == -1)
		exit(1);
	while (1)
	{
		signal(SIGUSR2, byte);
		signal(SIGUSR1, byte);
=======
	pid_t server_pid;
	server_pid = getpid();
    	if (printf("PID del servidor: %d\n", server_pid == -1);
	
	while (1)
	{
		signal(SIGUSR1, byte);
   		signal(SIGUSR2, byte);
>>>>>>> 4cb902786160f79e0f9d5713a53883bcb768380c
		pause();
	}
	return (0);
}
