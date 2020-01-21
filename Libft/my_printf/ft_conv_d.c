/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 15:06:52 by plogan            #+#    #+#             */
/*   Updated: 2017/06/01 12:36:21 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	remove_sign(char **str, t_flag *flag_tab)
{
	char	*free_ptr;

	free_ptr = *str;
	if (!(*str = ft_strdup(*str + 1)))
		return ;
	free(free_ptr);
	flag_tab->flag_sign = 2;
}

char		*ft_conv_d(va_list *arg, t_flag *flag_tab)
{
	char		*str;
	intmax_t	nb;

	if (flag_tab->data_type == 1)
		nb = (signed char)va_arg(*arg, intmax_t);
	else if (flag_tab->data_type == 2)
		nb = (short)va_arg(*arg, intmax_t);
	else if (flag_tab->data_type == 3)
		nb = (long)va_arg(*arg, intmax_t);
	else if (flag_tab->data_type == 4)
		nb = (long long)va_arg(*arg, intmax_t);
	else if (flag_tab->data_type == 5)
		nb = (intmax_t)va_arg(*arg, intmax_t);
	else if (flag_tab->data_type == 6)
		nb = (size_t)va_arg(*arg, intmax_t);
	else
		nb = (int)va_arg(*arg, intmax_t);
	if (!(str = ft_itoa(nb)))
		return (str);
	if (str[0] == '-')
		remove_sign(&str, flag_tab);
	return (str);
}
