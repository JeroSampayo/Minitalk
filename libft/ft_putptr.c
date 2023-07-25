/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiras-s <jmiras-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:24:07 by jmiras-s          #+#    #+#             */
/*   Updated: 2023/07/25 17:25:55 by jmiras-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putptr(unsigned long ptr)
{
	int	i;

	if (ft_putstr("0x") < 0)
		return (-1);
	i = ft_puthex(ptr, "0123456789abcdef");
	if (i == -1)
		return (-1);
	return (i + 2);
}
