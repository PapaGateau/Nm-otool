/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:19:41 by plogan            #+#    #+#             */
/*   Updated: 2017/05/31 16:50:04 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_n(va_list *arg, t_flag *flag_tab)
{
	char	*str;
	int		*int_ptr;

	str = NULL;
	int_ptr = va_arg(*arg, int *);
	*int_ptr = flag_tab->bytes;
	return (str);
}
