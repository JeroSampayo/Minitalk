/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiras-s <jmiras-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:07:23 by jmiras-s          #+#    #+#             */
/*   Updated: 2023/09/07 13:27:16 by jmiras-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	ft_free(char **str, int *len)
{
	ft_printf("%s\n", *str);
	free(*str);
	*str = NULL;
	*len = -1;
}

char	*safe_malloc(size_t size)
{
	char	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_printf("Error: Unable to allocate memory.\n");
		exit(1);
	}
	return (ptr);
}

void	byte(int sig)
{
	static int				num_bit = 0;
	static char				*str = NULL;
	static int				len = 0;

	if (str == NULL)
	{
		if (sig == SIGUSR1)
			len++;
		else
		{
			str = safe_malloc(sizeof(char) * (len + 1));
			len = 0;
		}
		return ;
	}
	if (sig == SIGUSR1)
		str[len] = (str[len] | (128 >> num_bit));
	num_bit++;
	if (num_bit == 8)
	{
		num_bit = 0;
		if (str[len] == 0)
			ft_free(&str, &len);
		len++;
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
