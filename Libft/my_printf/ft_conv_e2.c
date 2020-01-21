/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_e2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 18:37:32 by plogan            #+#    #+#             */
/*   Updated: 2017/06/01 15:37:43 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	add_sign(char **exp, int is_neg)
{
	char	*free_ptr;

	free_ptr = *exp;
	if (is_neg)
	{
		if (!(*exp = ft_strjoin("-", *exp)))
			return ;
	}
	else
	{
		if (!(*exp = ft_strjoin("+", *exp)))
			return ;
	}
	free(free_ptr);
}

static char	*compile_nb_e(char *str, int e)
{
	char	*exp;
	int		is_neg;
	char	*free_ptr;

	is_neg = 0;
	if (e < 0)
	{
		e = e * -1;
		is_neg = 1;
	}
	if (!(exp = ft_itoa(e)))
		return (exp);
	if (ft_strlen(exp) < 2)
	{
		free_ptr = exp;
		if (!(exp = ft_strjoin("0", exp)))
			return (exp);
		free(free_ptr);
	}
	add_sign(&exp, is_neg);
	if (!(str = ft_strjoin(str, exp)))
		return (str);
	free(exp);
	return (str);
}

static int	negative_e(long double f, char *str, int is_neg, int afterpoint)
{
	intmax_t	i;
	int			e;
	intmax_t	temp;

	e = 0;
	i = is_neg;
	while (f < 1)
	{
		f = f * 10;
		e--;
	}
	f = ft_round_float(f, afterpoint);
	str[i] = (intmax_t)f + '0';
	f = f - (intmax_t)f;
	i += 2;
	while (i < afterpoint + is_neg + 2)
	{
		temp = (intmax_t)(f * 10) % 10;
		str[i] = temp + '0';
		f = f * 10 - temp;
		i++;
	}
	return (e);
}

static int	positive_e(long double f, char *str, int is_neg, int afterpoint)
{
	intmax_t	i;
	int			e;
	intmax_t	temp;

	e = 0;
	i = is_neg;
	while (f > 9)
	{
		f = f / 10;
		e++;
	}
	f = ft_round_float(f, afterpoint);
	str[i] = (intmax_t)f + '0';
	f = f - (intmax_t)f;
	i += 2;
	while (i < afterpoint + is_neg + 2)
	{
		temp = (intmax_t)(f * 10) % 10;
		if (i == afterpoint + is_neg + 1 && (f * 10 - temp) > 4)
			temp = (intmax_t)(f * 10) % 10 + 1;
		str[i] = temp + '0';
		f = f * 10 - temp;
		i++;
	}
	return (e);
}

char		*ft_conv_e2(long double f, int afterpoint)
{
	char	*str;
	int		is_neg;
	int		e;
	char	*free_ptr;

	is_neg = 0;
	if (f < 0)
		is_neg = 1;
	if (!(str = ft_strnew(2 + afterpoint + 1 + is_neg)))
		return (str);
	str[afterpoint + 3 + is_neg] = '\0';
	if (is_neg && (f = f * -1))
		str[0] = '-';
	str[1 + is_neg] = '.';
	str[is_neg + 2 + afterpoint] = 'e';
	if (f >= 1 || f == 0)
		e = positive_e(f, str, is_neg, afterpoint);
	else
		e = negative_e(f, str, is_neg, afterpoint);
	free_ptr = str;
	if (!(str = compile_nb_e(str, e)))
		return (str);
	free(free_ptr);
	return (str);
}
