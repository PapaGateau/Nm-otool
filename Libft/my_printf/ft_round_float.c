/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:32:43 by plogan            #+#    #+#             */
/*   Updated: 2017/06/02 17:28:21 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_power(long double *f, int precision, uintmax_t power)
{
	intmax_t	ipart;
	long double	temp;

	temp = *f;
	while (precision + 1)
	{
		precision--;
		temp = temp * 10;
		ipart = (intmax_t)temp;
		temp = temp - ipart;
		ipart = ipart % 10;
	}
	if (ipart > 4)
	{
		ipart = 10 - ipart;
		temp = (long double)ipart;
		while (power + 1)
		{
			power--;
			temp = temp / 10;
		}
		*f = *f + temp;
	}
}

long double	ft_round_float(long double f, int precision)
{
	int				power;
	int				is_neg;

	is_neg = 0;
	if (f < 0)
	{
		is_neg = 1;
		f = -f;
	}
	if (precision == -1)
		precision = 6;
	power = precision;
	get_power(&f, precision, power);
	if (is_neg)
		return (-f);
	return (f);
}
