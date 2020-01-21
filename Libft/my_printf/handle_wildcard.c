/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 16:48:25 by plogan            #+#    #+#             */
/*   Updated: 2017/05/31 17:13:00 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_wildcard(int *i, const char *format, t_flag *flag_tab,
		va_list *arg)
{
	int		nb;

	nb = va_arg(*arg, int);
	if (format[*i - 1] == '.')
	{
		if (nb < 0)
			flag_tab->flag_precision = -1;
		else
			flag_tab->flag_precision = nb;
	}
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			flag_tab->flag_minus = 1;
		}
		flag_tab->flag_width = nb;
	}
}
