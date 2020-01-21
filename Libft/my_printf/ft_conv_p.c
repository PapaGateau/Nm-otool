/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:29:01 by plogan            #+#    #+#             */
/*   Updated: 2017/06/01 13:46:02 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_precision(char **str, t_flag *flag_tab)
{
	int		len;
	int		width;
	char	*free_ptr;

	len = ft_strlen(*str);
	width = flag_tab->flag_precision;
	while (len < width)
	{
		free_ptr = *str;
		if (!(*str = ft_strjoin("0", *str)))
			return ;
		free(free_ptr);
		len++;
	}
}

static void	handle_zero(char **str, t_flag *flag_tab)
{
	int		len;
	int		width;
	char	*free_ptr;

	len = ft_strlen(*str) + 2;
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

char		*ft_conv_p(va_list *arg, t_flag *flag_tab)
{
	char			*str;
	void			*ptr;
	uintmax_t		nb;
	char			*free_ptr;

	ptr = va_arg(*arg, void *);
	nb = (uintmax_t)ptr;
	if (nb == 0 && flag_tab->flag_precision == 0)
		str = ft_strdup("");
	else
	{
		str = ft_utoa_base(nb, 16);
		handle_precision(&str, flag_tab);
	}
	if (flag_tab->flag_zero != -1)
		handle_zero(&str, flag_tab);
	free_ptr = str;
	if (!(str = ft_strjoin("0x", str)))
		return (str);
	free(free_ptr);
	return (str);
}
