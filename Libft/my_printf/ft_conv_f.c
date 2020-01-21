/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 17:44:39 by plogan            #+#    #+#             */
/*   Updated: 2017/06/01 21:01:21 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*fpart_to_str(long double fpart, int afterpoint)
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
		temp = (intmax_t)(fpart * 10) % 10;
		str[i] = temp + '0';
		fpart = fpart * 10 - temp;
		i++;
	}
	return (str);
}

static char	*ftoa(long double f, int afterpoint)
{
	char		*str;
	intmax_t	ipart;
	char		*free_ptr1;
	char		*free_ptr2;

	if (afterpoint == 0)
		return (ft_itoa((intmax_t)f));
	if (f < 0)
	{
		ipart = (intmax_t)f * -1;
		f = f * -1;
	}
	else
		ipart = (intmax_t)f;
	if (!(str = ft_itoa((intmax_t)f)))
		return (str);
	if (!(free_ptr1 = fpart_to_str(f - ipart, afterpoint)))
		return (free_ptr1);
	free_ptr2 = str;
	if (!(str = ft_strjoin(str, free_ptr1)))
		return (str);
	free(free_ptr1);
	free(free_ptr2);
	return (str);
}

char		*ft_conv_f(va_list *arg, t_flag *flag_tab)
{
	char		*str;
	double		f;
	char		*free_ptr;

	f = va_arg(*arg, double);
	f = ft_round_float(f, flag_tab->flag_precision);
	if (flag_tab->flag_hash > flag_tab->flag_precision)
		str = ftoa(f, 1);
	if (flag_tab->flag_precision == -1)
		str = ftoa(f, 6);
	else
		str = ftoa(f, flag_tab->flag_precision);
	if (!str)
		return (str);
	if (f < 0 && str[0] != '-' && (free_ptr = str))
		str = ft_strjoin("-", str);
	if (flag_tab->flag_sign == 1 && f >= 0 && (free_ptr = str))
		str = ft_strjoin("+", str);
	if (f < 0 || (flag_tab->flag_sign == 1 && f >= 0))
		free(free_ptr);
	return (str);
}
