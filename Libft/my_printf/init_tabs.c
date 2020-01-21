/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:27:43 by plogan            #+#    #+#             */
/*   Updated: 2017/06/01 14:27:44 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_flag_tab(t_flag *tab, int *bytes)
{
	tab->conv = 0;
	tab->flag_hash = -1;
	tab->flag_zero = -1;
	tab->flag_minus = -1;
	tab->flag_sign = -1;
	tab->flag_space = -1;
	tab->flag_width = -1;
	tab->flag_precision = -1;
	tab->bytes = *bytes;
	tab->flag_null = 0;
	tab->data_type = 0;
}

void		init_tabs(t_flag *tab, int *bytes, t_conv *conv_tab)
{
	init_flag_tab(tab, bytes);
	init_conv_tab(conv_tab);
}
