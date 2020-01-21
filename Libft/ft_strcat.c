/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:28:25 by plogan            #+#    #+#             */
/*   Updated: 2017/04/11 17:39:54 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		size1;
	int		size2;

	size1 = 0;
	size2 = 0;
	while (s1[size1])
		size1++;
	while (s2[size2])
	{
		s1[size1 + size2] = s2[size2];
		size2++;
	}
	s1[size1 + size2] = '\0';
	return (s1);
}
