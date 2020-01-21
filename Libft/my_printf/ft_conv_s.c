/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:36:57 by plogan            #+#    #+#             */
/*   Updated: 2017/06/01 13:46:58 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_flag_zero(char **str, t_flag *flag_tab)
{
	char	*free_ptr;
	int		len;
	int		width;

	len = ft_strlen(*str);
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

char		*ft_conv_s(va_list *arg, t_flag *flag_tab)
{
	char	*str;
	char	*temp;
	char	*free_ptr;

	if (flag_tab->data_type == 3)
		str = ft_conv_ss(arg, flag_tab);
	else
	{
		temp = va_arg(*arg, char *);
		if (temp == NULL)
			str = ft_strdup("(null)");
		else
			str = ft_strdup(temp);
	}
	if (flag_tab->flag_precision != -1)
	{
		free_ptr = str;
		if (!(str = ft_strsub(str, 0, flag_tab->flag_precision)))
			return (str);
		free(free_ptr);
		flag_tab->flag_precision = -1;
	}
	if (flag_tab->flag_zero != -1)
		handle_flag_zero(&str, flag_tab);
	return (str);
}
