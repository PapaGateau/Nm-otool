/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 18:43:53 by plogan            #+#    #+#             */
/*   Updated: 2017/06/01 12:38:33 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_point(char **str)
{
	if (*str[0] == '-' || *str[0] == '+')
		ft_memmove(*str + 2, *str + 3, ft_strlen(*str + 3) + 1);
	else
		ft_memmove(*str + 1, *str + 2, ft_strlen(*str + 2) + 1);
}

char		*ft_conv_e(va_list *arg, t_flag *flag_tab)
{
	char		*str;
	double		f;
	char		*free_ptr;

	f = va_arg(*arg, double);
	if (flag_tab->flag_hash > flag_tab->flag_precision)
		str = ft_conv_e2(f, 1);
	if (flag_tab->flag_precision == -1)
		str = ft_conv_e2(f, 6);
	else
		str = ft_conv_e2(f, flag_tab->flag_precision);
	if (!str)
		return (str);
	if (flag_tab->flag_precision == 0)
		handle_point(&str);
	if (flag_tab->flag_sign == 1 && (intmax_t)f >= 0)
	{
		free_ptr = str;
		if (!(str = ft_strjoin("+", str)))
			return (str);
		free(free_ptr);
	}
	return (str);
}
