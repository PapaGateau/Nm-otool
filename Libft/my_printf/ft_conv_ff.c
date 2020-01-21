/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 18:32:28 by plogan            #+#    #+#             */
/*   Updated: 2017/06/01 14:26:16 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*dpart_to_str(long double dpart, int afterpoint)
{
	char		*str;
	int			i;
	intmax_t	temp;

	i = 1;
	if (!(str = ft_strnew(afterpoint + 1)))
		return (str);
	str[0] = '.';
	str[afterpoint + 1] = '\0';
	while (i < afterpoint + 1)
	{
		temp = (intmax_t)(dpart * 10) % 10;
		str[i] = temp + '0';
		dpart = dpart * 10 - temp;
		i++;
	}
	return (str);
}

static char	*dtoa(long double d, int afterpoint)
{
	char		*str;
	intmax_t	ipart;
	char		*free_ptr1;
	char		*free_ptr2;

	if (afterpoint == 0)
		return (ft_itoa((intmax_t)d));
	if (d < 0)
	{
		ipart = (intmax_t)d * -1;
		d = d * -1;
	}
	else
		ipart = (intmax_t)d;
	str = ft_itoa((intmax_t)d);
	free_ptr1 = dpart_to_str(d - ipart, afterpoint);
	free_ptr2 = str;
	str = ft_strjoin(str, free_ptr1);
	if (!str)
		return (str);
	free(free_ptr1);
	free(free_ptr2);
	return (str);
}

char		*ft_conv_ff(va_list *arg, t_flag *flag_tab)
{
	char		*str;
	double		d;
	char		*free_ptr;

	d = (double)va_arg(*arg, double);
	d = ft_round_float(d, flag_tab->flag_precision);
	if (flag_tab->flag_hash > flag_tab->flag_precision)
		str = dtoa(d, 1);
	if (flag_tab->flag_precision == -1)
		str = dtoa(d, 6);
	else
		str = dtoa(d, flag_tab->flag_precision);
	if (!str)
		return (str);
	if (d < 0 && str[0] != '-' && (free_ptr = str))
		str = ft_strjoin("-", str);
	if (flag_tab->flag_sign == 1 && d >= 0 && (free_ptr = str))
		str = ft_strjoin("+", str);
	if (d < 0 || (flag_tab->flag_sign == 1 && d >= 0))
		free(free_ptr);
	return (str);
}
