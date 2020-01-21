/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:57:31 by plogan            #+#    #+#             */
/*   Updated: 2017/04/13 12:26:46 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	size = 0;
	while (needle[size])
		size++;
	if (size == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] == needle[j])
		{
			if (j == size - 1 && (i + j) < len)
				return ((char *)haystack + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
