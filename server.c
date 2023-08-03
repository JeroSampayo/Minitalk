/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiras-s <jmiras-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:07:23 by jmiras-s          #+#    #+#             */
/*   Updated: 2023/08/03 16:19:35 by jmiras-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	byte(int sig)
{
	static unsigned char c = 0;
	static int	num_bit = 0;
	static char *str = NULL;
	static int len = 0;

	ft_printf("%d\n", num_bit);
	if (str == NULL)
		{
			if (sig == SIGUSR1)
				len++;
			else 
			{
				str = malloc(sizeof(char)* len + 1);
				len = 0;
			}
			return;
		}
	if (sig == SIGUSR1)
		c = (c | (128 >> num_bit));
	num_bit++;
	if (num_bit == 8)
	{
		str[len] = c;
		len++;
		num_bit = 0;
		if (c == '\0')
		{
			ft_printf("%s", str);
			free(str);
			str = NULL;
			len = 0;
		}
		c = 0;
	}	
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	if (ft_printf("%i\n", pid) == -1)
		exit(1);
	signal(SIGUSR2, byte);
	signal(SIGUSR1, byte);
	while (1)
		pause();
	return (0);
}
