/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 14:29:20 by plogan            #+#    #+#             */
/*   Updated: 2017/06/02 17:03:52 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	add_sign(char **str, int sign)
{
	char	*free_ptr;

	if (sign == -1)
	{
		free_ptr = *str;
		if (!(*str = ft_strjoin("-", *str)))
			return ;
		free(free_ptr);
	}
	else if (sign == 1)
	{
		free_ptr = *str;
		if (!(*str = ft_strjoin("+", *str)))
			return ;
		free(free_ptr);
	}
}

static int	remove_sign(char **str, char conv, int *precision)
{
	char	*free_ptr;
	int		sign;

	sign = 0;
	if (*str[0] == '-' && (conv == 'd' || conv == 'D' || conv == 'i'))
	{
		sign = -1;
		free_ptr = *str;
		if (!(*str = ft_strsub(*str, 1, ft_strlen(*str) - 1)))
			return (-42);
		free(free_ptr);
	}
	if (*str[0] == '+' && (conv == 'd' || conv == 'D' || conv == 'i'))
	{
		sign = 1;
		free_ptr = *str;
		if (!(*str = ft_strsub(*str, 1, ft_strlen(*str) - 1)))
			return (-42);
		free(free_ptr);
	}
	if (sign != 0)
		*precision = *precision + 1;
	return (sign);
}

static void	handle_str_precision(char **str, int precision,
		int len)
{
	char	*free_ptr;

	if (len > precision)
	{
		free_ptr = *str;
		if (!(*str = ft_strsub(*str, 0, precision)))
			return ;
		free(free_ptr);
	}
}

void		ft_flag_precision(char **str, t_flag *flag_tab)
{
	int		len;
	int		precision;
	char	*free_ptr;
	char	conv;
	int		sign;

	conv = flag_tab->conv;
	precision = flag_tab->flag_precision;
	len = ft_strlen(*str);
	if (conv == 's' || conv == 'S')
		handle_str_precision(str, precision, len);
	if (conv != 'd' && conv != 'i' && conv != 'o' && conv != 'u' && conv != 'x'
			&& conv != 'D' && conv != 'O' && conv != 'U' && conv != 'X')
		return ;
	sign = remove_sign(&*str, conv, &precision);
	handle_null(&*str, flag_tab);
	while (len < precision)
	{
		free_ptr = *str;
		*str = ft_strjoin("0", *str);
		free(free_ptr);
		len++;
	}
	if (sign == 1 || sign == -1)
		add_sign(&*str, sign);
}
