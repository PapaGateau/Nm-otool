/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:09:42 by plogan            #+#    #+#             */
/*   Updated: 2017/06/02 16:12:25 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*make_str(uintmax_t nb, uintmax_t p, int size, int base_size)
{
	char	*str;
	char	*base;
	int		i;

	if (!(str = ft_strnew(size)))
		return (str);
	str[size] = '\0';
	i = 0;
	base = "0123456789abcdef";
	while (i < size)
	{
		str[i++] = base[(nb / p) % base_size];
		p = p / base_size;
	}
	return (str);
}

char		*ft_utoa_base(uintmax_t nb, uintmax_t base_size)
{
	uintmax_t	temp;
	uintmax_t	p;
	int			size;

	p = 1;
	size = 1;
	temp = nb;
	while (temp > (base_size - 1) && (p = p * base_size))
	{
		temp = temp / base_size;
		size++;
	}
	return (make_str(nb, p, size, base_size));
}
