/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 14:15:08 by plogan            #+#    #+#             */
/*   Updated: 2017/06/01 14:18:09 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_x(char **str, char conv)
{
	char	*free_ptr;

	free_ptr = *str;
	if (conv == 'x')
	{
		if (!(*str = ft_strjoin("0x", *str)))
			return ;
	}
	if (conv == 'X')
	{
		if (!(*str = ft_strjoin("0X", *str)))
			return ;
	}
	free(free_ptr);
}

void		ft_flag_hash(char **str, t_flag *flag_tab)
{
	char	*free_ptr;
	char	conv;

	conv = flag_tab->conv;
	if ((conv == 'x' || conv == 'X') && flag_tab->flag_hash == 1
			&& flag_tab->flag_precision == 0 && ft_atoi(*str) == 0)
	{
		free_ptr = *str;
		*str = ft_strdup("");
		free(free_ptr);
	}
	else if (ft_atoi(*str) != 0 && (conv == 'x' || conv == 'X'))
		handle_x(str, conv);
}
