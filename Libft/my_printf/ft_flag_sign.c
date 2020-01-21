/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_sign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 15:07:59 by plogan            #+#    #+#             */
/*   Updated: 2017/05/25 20:48:28 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_sign(char **str, t_flag *flag_tab)
{
	char	*free_ptr;
	char	conv;

	conv = flag_tab->conv;
	if (conv == 'd' || conv == 'D' || conv == 'i')
	{
		free_ptr = *str;
		if (flag_tab->flag_sign == 1)
			*str = ft_strjoin("+", *str);
		else if (flag_tab->flag_sign == 2)
			*str = ft_strjoin("-", *str);
		free(free_ptr);
	}
}
