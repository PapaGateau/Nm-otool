/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <plogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:14:28 by plogan            #+#    #+#             */
/*   Updated: 2019/10/17 12:12:58 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

int		process_fat_archive(t_file *file, struct fat_arch *fat_arch,
	bool print_all)
{
	t_file		*new_file;
	char		*arch_name;
	uint32_t	offset;
	uint32_t	size;

	file->print_path = false;
	arch_name = get_arch_name(fat_arch, file);
	if (swapif_uint32(file, fat_arch->align) > 15)
		return (FAILURE);
	if (print_all && file->bin == NM)
		ft_printf("\n%s (for architecture %s):\n", file->path, arch_name);
	offset = swapif_uint32(file, fat_arch->offset);
	size = swapif_uint32(file, fat_arch->size);
	if (!check_overflow(file, file->file_start + offset + size - 1))
		return (FAILURE);
	if (!(new_file = init_file(file->path, file->file_start + offset, size,
						file->bin)))
		return (FAILURE);
	if (!dispatch_file(new_file, new_file->file_start))
		return (free_and_fail(new_file));
	dispatch_print_nm(new_file, file->bin, false);
	free_structs(new_file);
	return (SUCCESS);
}

int		handle_fat_archive(t_file *file, struct fat_arch *fat_arch,
	uint32_t n_arch)
{
	uint32_t		i;
	bool			print_all;
	struct fat_arch	*start;

	start = fat_arch;
	print_all = false;
	i = 0;
	while (i < n_arch)
	{
		if (print_all && !process_fat_archive(file, fat_arch, print_all))
			return (FAILURE);
		if (match_cpu_type(fat_arch, file) && !print_all)
			return (process_fat_archive(file, fat_arch, print_all));
		fat_arch = (void *)fat_arch + sizeof(struct fat_arch);
		if (!check_overflow(file, fat_arch))
			return (FAILURE);
		i++;
		if (i == n_arch && !print_all)
		{
			fat_arch = start;
			print_all = true;
			i = 0;
		}
	}
	return (SUCCESS);
}

int		handle_fat_file(t_file *file, void *file_start)
{
	uint32_t		n_arch;
	struct fat_arch	*fat_arch;

	n_arch = swapif_uint32(file, ((struct fat_header *)file_start)->nfat_arch);
	if (!check_overflow(file, file_start + sizeof(struct fat_header)))
		return (FAILURE);
	fat_arch = file_start + sizeof(struct fat_header);
	return (handle_fat_archive(file, fat_arch, n_arch));
}
