/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 16:56:24 by plogan            #+#    #+#             */
/*   Updated: 2017/06/02 17:08:06 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_hex(char **str)
{
	int		i;

	i = 65;
	while (i < 71)
	{
		if (ft_strchr(*str, i))
			return (0);
		if (ft_strchr(*str, i + 32))
			return (0);
		i++;
	}
	return (1);
}

void		handle_null(char **str, t_flag *flag_tab)
{
	char	conv;
	char	*free_ptr;

	conv = flag_tab->conv;
	if ((conv == 'x' || conv == 'X') && !handle_hex(str))
		return ;
	if ((conv == 'o' || conv == 'O') && flag_tab->flag_hash == 1)
		return ;
	if ((conv == 'x' || conv == 'X' || conv == 'u' || conv == 'U' || conv == 'i'
				|| conv == 'd' || conv == 'D' || conv == 'o' || conv == 'O') &&
			ft_atoi(*str) == 0 && flag_tab->flag_precision == 0)
	{
		free_ptr = *str;
		if (!(*str = ft_strdup("")))
			return ;
		free(free_ptr);
	}
}
