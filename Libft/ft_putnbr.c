/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 13:27:06 by plogan            #+#    #+#             */
/*   Updated: 2017/04/14 13:49:24 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_indiv(long nb)
{
	int		p;
	long	cpy;

	p = 1;
	cpy = nb;
	while (cpy >= 10)
	{
		p = p * 10;
		cpy = cpy / 10;
	}
	while (p >= 1)
	{
		ft_putchar((nb / p) + '0');
		nb = nb % p;
		p = p / 10;
	}
}

void		ft_putnbr(int n)
{
	long	nl;

	nl = n;
	if (nl < 0)
	{
		ft_putchar('-');
		nl = nl * -1;
	}
	ft_indiv(nl);
}
