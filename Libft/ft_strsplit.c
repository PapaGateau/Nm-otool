/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 11:48:16 by plogan            #+#    #+#             */
/*   Updated: 2017/04/14 13:25:29 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_words(const char *str, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			count++;
		i++;
	}
	if (str[0] != '\0')
		count++;
	return (count);
}

static	char	*ft_assign(const char *str, char c, int *i)
{
	char	*out;
	int		k;

	if (!(out = (char *)malloc(sizeof(out) * (ft_strlen(str) + 1))))
		return (NULL);
	k = 0;
	while (str[*i] != c && str[*i])
	{
		out[k] = str[*i];
		k++;
		*i += 1;
	}
	out[k] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (out);
}

char			**ft_strsplit(const char *str, char c)
{
	int		i;
	int		j;
	int		word_count;
	char	**out;

	if (!str || !c)
		return (NULL);
	i = 0;
	j = 0;
	word_count = ft_count_words(str, c);
	if (!(out = (char **)malloc(sizeof(out) * (word_count + 1))))
		return (NULL);
	while (str[i] == c && str[i])
		i++;
	while (j < word_count && str[i])
	{
		out[j] = ft_assign(str, c, &i);
		j++;
	}
	out[j] = NULL;
	return (out);
}
