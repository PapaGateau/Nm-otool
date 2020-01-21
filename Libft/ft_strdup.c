/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <plogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:40:05 by plogan            #+#    #+#             */
/*   Updated: 2019/09/06 17:05:17 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*dup;

	i = 0;
	size = 0;
	while (s1[size])
		size++;
	dup = (char *)malloc(sizeof(char) * size + 1);
	if (dup == NULL)
		return (0);
	while (i < size)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
