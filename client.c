/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiras-s <jmiras-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:11:29 by jmiras-s          #+#    #+#             */
/*   Updated: 2023/06/08 17:30:34 by jmiras-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <stdlib.h>
int main(int ac, char **av)
{

	if (ac == 2)
	{
		kill(atoi(av[1]), SIGUSR1);
		kill(atoi(av[1]), SIGUSR2);
	}
	return(0);
}
