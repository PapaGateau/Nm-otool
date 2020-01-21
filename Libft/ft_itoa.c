/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 16:49:40 by plogan            #+#    #+#             */
/*   Updated: 2017/06/06 11:25:01 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_str(intmax_t nb, intmax_t p, int size, int is_neg)
{
	long	temp;
	char	*str;
	int		i;

	if (nb == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	i = is_neg;
	temp = nb;
	if (!(str = ft_strnew(size + is_neg)))
		return (str);
	if (is_neg && (temp = temp * -1))
		str[0] = '-';
	str[is_neg + size] = '\0';
	while (i < (size + is_neg))
	{
		str[i++] = ((temp / p) % 10) + '0';
		p = p / 10;
	}
	return (str);
}

char		*ft_itoa(intmax_t nb)
{
	char		*str;
	intmax_t	temp;
	intmax_t	p;
	int			size;
	int			is_neg;

	p = 1;
	size = 1;
	is_neg = 0;
	temp = nb;
	if (temp < 0)
	{
		temp = temp * -1;
		is_neg = 1;
	}
	while (temp > 9 && (p = p * 10))
	{
		temp = temp / 10;
		size++;
	}
	str = make_str(nb, p, size, is_neg);
	return (str);
}
