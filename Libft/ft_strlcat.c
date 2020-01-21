/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:46:35 by plogan            #+#    #+#             */
/*   Updated: 2017/04/13 18:05:19 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	sizecomb;
	size_t	i;

	i = 0;
	dst_size = 0;
	src_size = 0;
	while (dst[dst_size])
		dst_size++;
	while (src[src_size])
		src_size++;
	sizecomb = dst_size + src_size;
	if (dst_size >= size)
		return (size + src_size);
	while (dst_size + i < sizecomb && dst_size + i < size - 1)
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (sizecomb);
}
