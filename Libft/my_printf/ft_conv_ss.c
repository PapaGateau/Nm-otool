/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 17:26:40 by plogan            #+#    #+#             */
/*   Updated: 2017/06/01 13:48:51 by plogan           ###   ########.fr       */
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

static char	*wchar_to_str(wchar_t c)
{
	char	*str;

	if (!(str = ft_strnew(get_size(c))))
		return (str);
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

static char	*convert_to_str(wchar_t *wstr, int precision)
{
	char	*str;
	char	*free_ptr;
	char	*free_ptr2;
	int		wsize;

	wsize = ft_wstrlen(wstr);
	if (!(str = ft_strnew(0)))
		return (str);
	while (wsize > 0)
	{
		if (ft_strlen(str) + get_size(*wstr) > (size_t)precision)
			break ;
		free_ptr = str;
		free_ptr2 = wchar_to_str(*wstr);
		if (!free_ptr2 || !(str = ft_strjoin(str, free_ptr2)))
			return (NULL);
		free(free_ptr);
		free(free_ptr2);
		wsize--;
		wstr++;
	}
	return (str);
}

char		*ft_conv_ss(va_list *arg, t_flag *flag_tab)
{
	char	*str;
	wchar_t	*wstr;
	int		precision;

	precision = flag_tab->flag_precision;
	wstr = va_arg(*arg, wchar_t *);
	if (wstr == NULL)
		return (str = ft_strdup("(null)"));
	str = convert_to_str(wstr, precision);
	return (str);
}
