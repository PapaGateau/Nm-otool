/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:45:41 by plogan            #+#    #+#             */
/*   Updated: 2017/04/13 12:12:33 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = 0;
	while (needle[size])
		size++;
	if (size == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j])
		{
			if (j == size - 1)
				return ((char *)haystack + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
