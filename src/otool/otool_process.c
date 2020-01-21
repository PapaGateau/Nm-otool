/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <plogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:31:25 by plogan            #+#    #+#             */
/*   Updated: 2019/10/10 18:57:22 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

void	print_data(t_file *file, int64_t len, char *start)
{
	int64_t i;
	int64_t j;

	j = 1;
	i = 0;
	while (i < len)
	{
		if (file->swap_bits)
		{
			ft_printf("%02x", (uint8_t)start[i]);
			if (j == 4)
			{
				ft_printf(" ");
				j = 0;
			}
			j++;
		}
		else
			ft_printf("%02x ", (uint8_t)start[i]);
		i++;
	}
	ft_printf("\n");
}

void	process_otool(t_file *file, t_sect *section)
{
	uint64_t size;
	uint64_t end;
	uint64_t addr;
	uint64_t off;

	if (ft_strcmp(section->name, "__text"))
		return ;
	off = section->offset;
	size = section->size;
	addr = section->addr;
	end = addr + size;
	if (!check_overflow(file, file->file_start + off + size))
		return ;
	if (file->print_path == true)
		ft_printf("%s:\n", file->path);
	ft_printf("Contents of (__TEXT,__text) section\n");
	while (addr < end)
	{
		ft_printf("%0*llx\t", (file->arch == ARCH_32) ? 8 : 16, addr);
		print_data(file, size > 16 ? 16 : size, file->file_start + off);
		addr += 16;
		size -= 16;
		off += 16;
	}
}
