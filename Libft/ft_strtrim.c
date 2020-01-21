/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 11:05:43 by plogan            #+#    #+#             */
/*   Updated: 2017/04/14 13:24:41 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*new;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i++;
		len--;
	}
	if (len <= 0)
		len = 0;
	if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s = s + i;
	i = -1;
	while (++i < len)
		new[i] = *s++;
	new[i] = '\0';
	return (new);
}
