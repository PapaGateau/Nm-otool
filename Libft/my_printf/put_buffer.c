/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 19:00:48 by plogan            #+#    #+#             */
/*   Updated: 2017/06/06 11:47:23 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_buffer	*make_new_buffer(void)
{
	t_buffer	*new;

	if (!(new = (t_buffer *)malloc(sizeof(t_buffer))))
		return (new);
	new->buffer = ft_strnew(PRINTF_BUFF_SIZE);
	new->len = 0;
	return (new);
}

int				put_buffer(const char *str, int len, int end)
{
	static t_buffer	*save;
	int				temp_index;

	temp_index = 0;
	if (!save)
		save = make_new_buffer();
	if (save == NULL)
		return (0);
	if (end == 1)
	{
		write(1, save->buffer, save->len);
		save->len = 0;
		return (1);
	}
	while (temp_index < len)
	{
		if (save->len == PRINTF_BUFF_SIZE - 1)
		{
			write(1, save->buffer, save->len);
			save->len = 0;
		}
		save->buffer[save->len++] = str[temp_index++];
	}
	return (1);
}
