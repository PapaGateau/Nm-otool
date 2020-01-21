/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peterlog <peterlog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:38:03 by peterlog          #+#    #+#             */
/*   Updated: 2019/10/10 20:02:13 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

int			check_overflow(t_file *file, void *ptr)
{
	void *start;
	void *end;

	start = file->file_start;
	end = file->file_end;
	if (ptr + 1 > end || ptr < start)
	{
		ft_printf("ft_%s: %s truncated or malformed file\n", (file->bin == NM) ?
					"nm" : "otool", file->path);
		return (FAILURE);
	}
	return (SUCCESS);
}

int32_t		swapif_int32(t_file *file, int32_t x)
{
	if (file->swap_bits)
	{
		x = ((x << 8) & 0xFF00FF00) | ((x >> 8) & 0xFF00FF);
		return ((x << 16) | ((x >> 16) & 0xFFFF));
	}
	else
		return (x);
}

uint32_t	swapif_uint32(t_file *file, uint32_t x)
{
	if (file->swap_bits)
	{
		x = ((x << 8) & 0xFF00FF00) | ((x >> 8) & 0xFF00FF);
		return ((x << 16) | (x >> 16));
	}
	else
		return (x);
}

uint64_t	swapif_uint64(t_file *file, uint64_t x)
{
	if (file->swap_bits)
	{
		x = ((x << 8) & 0xFF00FF00FF00FF00ULL) |
			((x >> 8) & 0x00FF00FF00FF00FFULL);
		x = ((x << 16) & 0xFFFF0000FFFF0000ULL)
				| ((x >> 16) & 0x0000FFFF0000FFFFULL);
		return ((x << 32) | (x >> 32));
	}
	else
		return (x);
}
