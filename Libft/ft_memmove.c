/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:36:23 by plogan            #+#    #+#             */
/*   Updated: 2017/04/14 14:10:49 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*temp_dst;
	char	*temp_src;

	i = 0;
	temp_dst = (char*)dst;
	temp_src = (char*)src;
	if (temp_src < temp_dst)
	{
		while (n--)
			temp_dst[n] = temp_src[n];
	}
	else
		ft_memcpy(temp_dst, temp_src, n);
	return (temp_dst);
}
