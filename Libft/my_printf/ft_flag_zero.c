/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 20:07:53 by plogan            #+#    #+#             */
/*   Updated: 2017/05/31 19:44:29 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_hex(char **str, t_flag *flag_tab, int len, int width)
{
	char	*free_ptr;

	if (flag_tab->flag_hash != -1)
		width = width - 2;
	while (len < width)
	{
		free_ptr = *str;
		*str = ft_strjoin("0", *str);
		free(free_ptr);
		len++;
	}
}

static void	handle_dec(char **str, t_flag *flag_tab, int len, int width)
{
	char	*free_ptr;

	if (flag_tab->flag_sign != -1)
		width = width - 1;
	while (len < width)
	{
		free_ptr = *str;
		*str = ft_strjoin("0", *str);
		free(free_ptr);
		len++;
	}
}

static void	handle_unsigned(char **str, int len, int width)
{
	char	*free_ptr;

	while (len < width)
	{
		free_ptr = *str;
		*str = ft_strjoin("0", *str);
		free(free_ptr);
		len++;
	}
}

static void	handle_str(char **str, int len, int width)
{
	char	*free_ptr;

	while (len < width)
	{
		free_ptr = *str;
		*str = ft_strjoin("0", *str);
		free(free_ptr);
		len++;
	}
}

void		ft_flag_zero(char **str, t_flag *flag_tab)
{
	char	conv;
	int		len;
	int		width;

	len = ft_strlen(*str);
	if (flag_tab->flag_space != -1)
		len++;
	conv = flag_tab->conv;
	width = flag_tab->flag_width;
	if ((conv == 'd' || conv == 'D' || conv == 'i')
			&& flag_tab->flag_precision == -1)
		handle_dec(str, flag_tab, len, width);
	if ((conv == 'u' || conv == 'U' || conv == 'o' || conv == 'O')
			&& flag_tab->flag_precision == -1)
		handle_unsigned(str, len, width);
	if ((conv == 'x' || conv == 'X') && flag_tab->flag_precision == -1)
		handle_hex(str, flag_tab, len, width);
	if (conv == 's' || conv == 'S')
		handle_str(str, len, width);
}
