/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 13:31:08 by plogan            #+#    #+#             */
/*   Updated: 2017/06/01 12:20:44 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_flag_zero(char **str, t_flag *flag_tab)
{
	char	*free_ptr;
	int		len;
	int		width;

	len = ft_strlen(*str) + flag_tab->flag_null;
	width = flag_tab->flag_width;
	while (len < width)
	{
		free_ptr = *str;
		if (!(*str = ft_strjoin("0", *str)))
			return ;
		free(free_ptr);
		len++;
	}
}

char		*ft_conv_c(va_list *arg, t_flag *flag_tab)
{
	char	*str;
	char	c;

	if (flag_tab->data_type == 3)
	{
		if (!(str = ft_conv_cc(arg, flag_tab)))
			return (str);
	}
	else
	{
		c = va_arg(*arg, int);
		if (c == '\0')
			flag_tab->flag_null = 1;
		if (!(str = ft_strnew(1)))
			return (str);
		str[0] = c;
		str[1] = '\0';
	}
	if (flag_tab->flag_width != -1 && flag_tab->flag_zero != -1)
		handle_flag_zero(&str, flag_tab);
	return (str);
}
