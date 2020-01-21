/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_invalid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:37:29 by plogan            #+#    #+#             */
/*   Updated: 2017/05/31 19:46:59 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	make_str(t_flag *flag_tab, char **str)
{
	char	*free_ptr;

	free_ptr = *str;
	if (flag_tab->flag_minus != -1)
		*str = ft_strjoin(*str, " ");
	else if (flag_tab->flag_zero != -1)
		*str = ft_strjoin("0", *str);
	else
		*str = ft_strjoin(" ", *str);
	free(free_ptr);
}

int			handle_invalid(int *i, char **str, t_flag *flag_tab,
		const char *format)
{
	int		width;
	int		len;

	len = 1;
	width = flag_tab->flag_width;
	if (format[*i] == '%')
		*str = ft_strdup("%");
	else
		*str = ft_strsub(format, *i, 1);
	while (len < width)
	{
		make_str(flag_tab, str);
		len++;
	}
	*i = *i + 1;
	put_buffer(*str, len, 0);
	free(*str);
	return (len);
}
