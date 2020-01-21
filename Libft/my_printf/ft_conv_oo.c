/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_oo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:12:40 by plogan            #+#    #+#             */
/*   Updated: 2017/06/01 13:44:37 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_conv_oo(va_list *arg, t_flag *flag_tab)
{
	char		*str;
	uintmax_t	nb;
	char		*free_ptr;

	nb = (unsigned long)va_arg(*arg, uintmax_t);
	str = ft_utoa_base(nb, 8);
	if (flag_tab->flag_hash == 1 && nb != 0)
	{
		free_ptr = str;
		if (!(str = ft_strjoin("0", str)))
			return (str);
		free(free_ptr);
	}
	return (str);
}
