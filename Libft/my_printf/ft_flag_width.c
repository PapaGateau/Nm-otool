/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 15:34:13 by plogan            #+#    #+#             */
/*   Updated: 2017/05/31 20:04:01 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flag_minus(char **str, int width)
{
	char	*free_ptr;

	while (ft_strlen(*str) < (size_t)width)
	{
		free_ptr = *str;
		*str = ft_strjoin(*str, " ");
		free(free_ptr);
	}
}

void		ft_flag_width(char **str, t_flag *flag_tab)
{
	char	*free_ptr;
	char	conv;
	int		width;
	int		prefix;

	prefix = 0;
	width = flag_tab->flag_width;
	conv = flag_tab->conv;
	if (flag_tab->flag_minus != -1)
		flag_minus(&*str, width);
	else
	{
		while (ft_strlen(*str) < (size_t)width)
		{
			free_ptr = *str;
			*str = ft_strjoin(" ", *str);
			free(free_ptr);
		}
	}
}
