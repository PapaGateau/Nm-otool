/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:37:14 by plogan            #+#    #+#             */
/*   Updated: 2017/06/01 13:49:29 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_xx(va_list *arg, t_flag *flag_tab)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = ft_conv_x(arg, flag_tab)))
		return (str);
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
