/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 15:26:41 by plogan            #+#    #+#             */
/*   Updated: 2017/06/02 16:07:44 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_x(va_list *arg, t_flag *flag_tab)
{
	char		*str;
	uintmax_t	nb;

	if (flag_tab->data_type == 1)
		nb = (unsigned char)va_arg(*arg, uintmax_t);
	else if (flag_tab->data_type == 2)
		nb = (unsigned short)va_arg(*arg, uintmax_t);
	else if (flag_tab->data_type == 3)
		nb = (unsigned long)va_arg(*arg, uintmax_t);
	else if (flag_tab->data_type == 4)
		nb = (unsigned long long)va_arg(*arg, uintmax_t);
	else if (flag_tab->data_type == 5)
		nb = (uintmax_t)va_arg(*arg, uintmax_t);
	else if (flag_tab->data_type == 6)
		nb = (size_t)va_arg(*arg, uintmax_t);
	else
		nb = (unsigned int)va_arg(*arg, uintmax_t);
	str = ft_utoa_base(nb, 16);
	return (str);
}
