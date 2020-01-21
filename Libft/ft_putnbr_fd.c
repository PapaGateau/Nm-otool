/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 13:39:18 by plogan            #+#    #+#             */
/*   Updated: 2017/04/14 13:49:10 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_indiv_fd(long nb, int fd)
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
		ft_putchar_fd(((nb / p) + '0'), fd);
		nb = nb % p;
		p = p / 10;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	long	nl;

	nl = n;
	if (nl < 0)
	{
		ft_putchar_fd('-', fd);
		nl = nl * -1;
	}
	ft_indiv_fd(nl, fd);
}
