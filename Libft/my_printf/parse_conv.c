/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:45:01 by plogan            #+#    #+#             */
/*   Updated: 2017/06/02 16:51:57 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conv_print(char **str, t_flag *flag_tab)
{
	int		ret;

	if (flag_tab->flag_precision != -1)
		ft_flag_precision(str, flag_tab);
	if (flag_tab->flag_zero != -1)
		ft_flag_zero(str, flag_tab);
	if (flag_tab->flag_hash != -1)
		ft_flag_hash(str, flag_tab);
	if (flag_tab->flag_sign != -1)
		ft_flag_sign(str, flag_tab);
	if (flag_tab->flag_space != -1 && flag_tab->flag_sign == -1)
		ft_flag_space(str, flag_tab);
	if (flag_tab->flag_width != -1 && flag_tab->flag_null == 0)
		ft_flag_width(str, flag_tab);
	ret = ft_strlen(*str);
	if (flag_tab->flag_null != 0)
		ret = ft_flag_null(flag_tab);
	else
		put_buffer(*str, ret, 0);
	if (!str)
		return (-1);
	free(*str);
	return (ret);
}

int			parse_conv(int *i, int *bytes, const char *format, va_list *arg)
{
	t_conv	conv_tab[19];
	t_flag	flag_tab;
	char	*str;
	int		j;

	j = 0;
	init_tabs(&flag_tab, bytes, &*conv_tab);
	parse_flags(i, format, &flag_tab, arg);
	while (j < 19)
	{
		if (conv_tab[j].conv == format[*i] && (*i = *i + 1))
		{
			flag_tab.conv = conv_tab[j].conv;
			str = conv_tab[j].ft(arg, &flag_tab);
			if (format[*i - 1] == 'n')
				return (0);
			if (!str || *bytes > (*bytes += conv_print(&str, &flag_tab)))
				return (-1);
			break ;
		}
		j++;
	}
	if ((format[*i] && j > 18) || (format[*i] == '%' && j > 18))
		*bytes += handle_invalid(i, &str, &flag_tab, format);
	return (0);
}
