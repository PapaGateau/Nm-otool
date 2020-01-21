/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 16:19:04 by plogan            #+#    #+#             */
/*   Updated: 2017/06/01 11:38:46 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		raw_print(int *i, const char *format)
{
	int		ret;

	ret = 0;
	while (format[*i + ret] != '%' && format[*i + ret])
		ret++;
	if (!put_buffer(format + *i, ret, 0))
		return (-1);
	*i = *i + ret;
	return (ret);
}
