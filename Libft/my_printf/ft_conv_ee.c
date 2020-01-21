/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_e_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:26:35 by plogan            #+#    #+#             */
/*   Updated: 2017/06/01 13:06:57 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_ee(va_list *arg, t_flag *flag_tab)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = ft_conv_e(arg, flag_tab)))
		return (str);
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
