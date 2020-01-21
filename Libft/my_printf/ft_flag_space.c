/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 15:20:42 by plogan            #+#    #+#             */
/*   Updated: 2017/05/25 20:55:45 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_space(char **str, t_flag *flag_tab)
{
	char	*free_ptr;
	char	conv;

	conv = flag_tab->conv;
	if ((conv == 'd' || conv == 'D' || conv == 'i') && *str[0] != '-')
	{
		free_ptr = *str;
		*str = ft_strjoin(" ", *str);
		free(free_ptr);
	}
}
