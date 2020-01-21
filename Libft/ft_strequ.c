/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 10:04:13 by plogan            #+#    #+#             */
/*   Updated: 2017/04/13 12:58:09 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;
	int		size1;
	int		size2;

	if (!s1 || !s2)
		return (0);
	i = 0;
	size1 = 0;
	size2 = 0;
	while (s1[size1])
		size1++;
	while (s2[size2])
		size2++;
	if (size1 != size2)
		return (0);
	while (i < size1)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
