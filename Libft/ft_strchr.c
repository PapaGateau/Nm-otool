/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:59:09 by plogan            #+#    #+#             */
/*   Updated: 2017/05/03 16:26:50 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*temp_s;

	temp_s = (char *)s;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (temp_s + i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return (temp_s + i);
	return (NULL);
}
