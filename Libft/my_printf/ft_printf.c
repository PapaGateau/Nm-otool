/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 20:15:21 by plogan            #+#    #+#             */
/*   Updated: 2017/06/01 13:05:22 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *restrict format, ...)
{
	int		i;
	va_list	arg;
	int		bytes;
	int		ret;

	va_start(arg, format);
	bytes = 0;
	i = 0;
	while (format[i] && ret != -1)
	{
		if (format[i] == '%' && !format[i + 1])
			break ;
		if (format[i] == '%' && (i = i + 1))
		{
			if (ft_strchr(CONVERSIONS, format[i]) ||
					(ft_strchr(FLAGS, format[i])))
				ret = parse_conv(&i, &bytes, format, &arg);
		}
		else if ((ret = raw_print(&i, format)) != -1)
			bytes += ret;
	}
	if (!put_buffer(NULL, 0, 1) || ret < 0)
		return (-1);
	va_end(arg);
	return (bytes);
}
