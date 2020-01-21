/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:17:08 by plogan            #+#    #+#             */
/*   Updated: 2017/04/14 13:46:38 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*temp_s;

	i = 0;
	temp_s = NULL;
	if (c != '\0' && s[0] == '\0')
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			temp_s = (char *)(s + i);
		i++;
	}
	if (c == 0 && s[i] == 0)
		temp_s = (char *)(s + i);
	return (temp_s);
}
