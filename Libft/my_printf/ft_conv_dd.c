/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_dd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:20:47 by plogan            #+#    #+#             */
/*   Updated: 2017/05/31 19:33:56 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_conv_dd(va_list *arg, t_flag *flag_tab)
{
	char		*str;
	intmax_t	nb;

	(void)flag_tab;
	nb = (long)va_arg(*arg, intmax_t);
	str = ft_itoa(nb);
	return (str);
}
