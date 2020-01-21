/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 21:27:50 by plogan            #+#    #+#             */
/*   Updated: 2017/04/12 21:32:50 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	size1;
	size_t	size2;

	size1 = 0;
	size2 = 0;
	while (s1[size1])
		size1++;
	while (s2[size2] && size2 < n)
	{
		s1[size1 + size2] = s2[size2];
		size2++;
	}
	s1[size1 + size2] = '\0';
	return (s1);
}
