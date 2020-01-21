/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 20:19:10 by plogan            #+#    #+#             */
/*   Updated: 2017/06/01 14:24:45 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_conv_tab2(t_conv *tab)
{
	tab[8].conv = 'o';
	tab[8].ft = &ft_conv_o;
	tab[9].conv = 'O';
	tab[9].ft = &ft_conv_oo;
	tab[10].conv = 'u';
	tab[10].ft = &ft_conv_u;
	tab[11].conv = 'U';
	tab[11].ft = &ft_conv_uu;
	tab[12].conv = 'x';
	tab[12].ft = &ft_conv_x;
	tab[13].conv = 'X';
	tab[13].ft = &ft_conv_xx;
	tab[14].conv = 'f';
	tab[14].ft = &ft_conv_f;
	tab[15].conv = 'F';
	tab[15].ft = &ft_conv_ff;
	tab[16].conv = 'e';
	tab[16].ft = &ft_conv_e;
	tab[17].conv = 'E';
	tab[17].ft = &ft_conv_ee;
	tab[18].conv = 'n';
	tab[18].ft = &ft_conv_n;
}

void		init_conv_tab(t_conv *tab)
{
	tab[0].conv = 'c';
	tab[0].ft = &ft_conv_c;
	tab[1].conv = 'C';
	tab[1].ft = &ft_conv_cc;
	tab[2].conv = 's';
	tab[2].ft = &ft_conv_s;
	tab[3].conv = 'S';
	tab[3].ft = &ft_conv_ss;
	tab[4].conv = 'p';
	tab[4].ft = &ft_conv_p;
	tab[5].conv = 'i';
	tab[5].ft = &ft_conv_d;
	tab[6].conv = 'd';
	tab[6].ft = &ft_conv_d;
	tab[7].conv = 'D';
	tab[7].ft = &ft_conv_dd;
	init_conv_tab2(tab);
}
