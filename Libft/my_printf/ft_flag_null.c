/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_null.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:56:50 by plogan            #+#    #+#             */
/*   Updated: 2017/05/31 17:20:56 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_minus(int *ret, int width)
{
	put_buffer("\0", 1, 0);
	*ret = *ret + 1;
	while (width - 1 > 0)
	{
		put_buffer(" ", 1, 0);
		width = width - 1;
		*ret = *ret + 1;
	}
}

static void	handle_zero(int *ret, int width)
{
	while (width - 1 > 0)
	{
		put_buffer("0", 1, 0);
		width = width - 1;
		*ret = *ret + 1;
	}
	put_buffer("\0", 1, 0);
	*ret = *ret + 1;
}

int			ft_flag_null(t_flag *flag_tab)
{
	int		width;
	int		ret;

	width = flag_tab->flag_width;
	ret = 0;
	if (flag_tab->flag_minus != -1)
		handle_minus(&ret, width);
	else if (flag_tab->flag_zero != -1)
		handle_zero(&ret, width);
	else
	{
		while (width - 1 > 0)
		{
			put_buffer(" ", 1, 0);
			width = width - 1;
			ret++;
		}
		put_buffer("\0", 1, 0);
		ret++;
	}
	return (ret);
}
