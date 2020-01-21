/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <plogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:18:39 by plogan            #+#    #+#             */
/*   Updated: 2019/10/10 20:04:09 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, uint64_t n)
{
	uint64_t		i;
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	temp_dest = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		temp_dest[i] = temp_src[i];
		i++;
	}
	return (dst);
}
