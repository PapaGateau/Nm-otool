/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_cc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 16:48:43 by plogan            #+#    #+#             */
/*   Updated: 2017/06/01 12:32:48 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x10FFFF)
		return (4);
	return (0);
}

static char	*convert_to_str(wchar_t c)
{
	char	*str;

	if (!(str = ft_strnew(get_size(c))))
		return (NULL);
	str[get_size(c)] = '\0';
	if (c <= 0x7F)
		str[0] = c;
	else if (c <= 0x7FF && (str[0] = (c >> 6) + 0xC0))
		str[1] = (c & 0x3F) + 0x80;
	else if (c <= 0xFFFF)
	{
		str[0] = (c >> 12) + 0xE0;
		str[1] = ((c >> 6) & 0x3F) + 0x80;
		str[2] = (c & 0x3F) + 0x80;
	}
	else if (c <= 0x10FFFF)
	{
		str[0] = (c >> 18) + 0xF0;
		str[1] = ((c >> 12) & 0x3F) + 0x80;
		str[2] = ((c >> 6) & 0x3F) + 0x80;
		str[3] = (c & 0x3F) + 0x80;
	}
	return (str);
}

char		*ft_conv_cc(va_list *arg, t_flag *flag_tab)
{
	char	*str;
	wchar_t	c;

	c = (wchar_t)va_arg(*arg, wint_t);
	if (c == '\0')
		flag_tab->flag_null = 1;
	str = convert_to_str(c);
	return (str);
}
