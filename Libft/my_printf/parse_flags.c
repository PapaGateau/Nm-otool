/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:54:11 by plogan            #+#    #+#             */
/*   Updated: 2017/05/31 20:08:36 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_num_flag(int *i, const char *format, t_flag *flag_tab)
{
	if (format[*i - 1] == '.')
		flag_tab->flag_precision = ft_atoi(&format[*i]);
	else
		flag_tab->flag_width = ft_atoi(&format[*i]);
	while (ft_isdigit(format[*i]))
		*i = *i + 1;
}

static void	init_form_flag(int *i, const char *format, t_flag *flag_tab,
		va_list *arg)
{
	if (!ft_isdigit(format[*i]) || (format[*i] == '0' && format[*i - 1] != '.'))
	{
		if (format[*i] == '#')
			flag_tab->flag_hash = 1;
		else if (format[*i] == '0')
			flag_tab->flag_zero = 1;
		else if (format[*i] == '-')
			flag_tab->flag_minus = 1;
		else if (format[*i] == '+')
			flag_tab->flag_sign = 1;
		else if (format[*i] == ' ')
			flag_tab->flag_space = 1;
		else if (format[*i] == '.' &&
				!ft_isdigit(format[*i + 1]))
			flag_tab->flag_precision = 0;
		else if (format[*i] == '*')
			handle_wildcard(i, format, flag_tab, arg);
		*i = *i + 1;
	}
	else
		init_num_flag(i, format, flag_tab);
}

static void	init_conv_flag(int *i, const char *format, t_flag *flag_tab)
{
	if (format[*i] == 'h' && format[*i + 1] == 'h' && flag_tab->data_type < 1)
	{
		flag_tab->data_type = 1;
		*i = *i + 1;
	}
	else if (format[*i] == 'h' && format[*i + 1] != 'h'
			&& flag_tab->data_type < 2)
		flag_tab->data_type = 2;
	else if (format[*i] == 'l' && format[*i + 1] != 'l'
			&& flag_tab->data_type < 3)
		flag_tab->data_type = 3;
	else if (format[*i] == 'l' && format[*i + 1] == 'l'
			&& flag_tab->data_type < 4)
	{
		flag_tab->data_type = 4;
		*i = *i + 1;
	}
	else if (format[*i] == 'j' && flag_tab->data_type < 5)
		flag_tab->data_type = 5;
	else if (format[*i] == 'z' && flag_tab->data_type < 6)
		flag_tab->data_type = 6;
}

void		parse_flags(int *i, const char *format, t_flag *flag_tab,
		va_list *arg)
{
	while (ft_strchr(FLAGS, format[*i]) && format[*i])
	{
		if (ft_strchr(CONV_FLAGS, format[*i]))
		{
			init_conv_flag(i, format, flag_tab);
			*i = *i + 1;
		}
		else if (ft_strchr(FORM_FLAGS, format[*i]))
			init_form_flag(i, format, flag_tab, arg);
	}
	if (flag_tab->flag_zero != -1 && flag_tab->flag_minus != -1)
		flag_tab->flag_zero = -1;
	if (flag_tab->flag_space != -1 && flag_tab->flag_sign != -1)
		flag_tab->flag_space = -1;
}
