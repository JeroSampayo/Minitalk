/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiras-s <jmiras-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:11:29 by jmiras-s          #+#    #+#             */
/*   Updated: 2023/08/03 16:19:32 by jmiras-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	pid;
	int len;

	if (argc != 3)
		return (0);
	if (!valid_pid(argv[1]))
		return (0);
	pid = ft_atoi(argv[1]);
	len = ft_strlen(argv[2]);
		while (len > 0)
		{
			kill (pid, SIGUSR1);
			len--;
			usleep(500);
		}		
	kill (pid, SIGUSR2);
	char_to_byte(argv[2], pid);
	ft_printf("OK\n");
	return (0);
}

int	valid_pid(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]))
			return (0);
	if (ft_strlen(s) < 3 || ft_strlen(s) > 5)
		return (0);
	return (1);
}

void	char_to_byte(char *s, pid_t pid)
{
	int	i;
	int	num_bit;

	i = -1;
	while (s[++i])
	{
		num_bit = -1;
		while (++num_bit < 8)
		{
			usleep(300);
			if ((s[i] & (128 >> num_bit)) == 0)
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
			}
		}
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR2);
		usleep(500);
	}
}

