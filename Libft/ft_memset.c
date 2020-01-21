/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <plogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:49:11 by plogan            #+#    #+#             */
/*   Updated: 2017/04/10 17:21:03 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)b;
	i = 0;
	while (i < n)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
