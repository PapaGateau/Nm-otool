/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_uu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:58:34 by plogan            #+#    #+#             */
/*   Updated: 2017/05/31 19:41:30 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_conv_uu(va_list *arg, t_flag *flag_tab)
{
	char			*str;
	uintmax_t		nb;

	(void)flag_tab;
	nb = (unsigned long)va_arg(*arg, uintmax_t);
	str = ft_utoa_base(nb, 10);
	return (str);
}
