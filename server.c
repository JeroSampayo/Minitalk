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

void handle_signal(int signum) 
{
    if (signum == SIGUSR1) {
        printf("Servidor recibió una señal SIGUSR1\n");
    }
    else if (signum == SIGUSR2) {
        printf("Servidor recibió una señal SIGUSR2\n");
    }
}

int main() 
{
	pid_t server_pid;
	server_pid = getpid();
    printf("PID del servidor: %d\n", server_pid);
	
	while (1)
	{
		signal(SIGUSR1, handle_signal);
   		signal(SIGUSR2, handle_signal);
	}
	return 0;
}
