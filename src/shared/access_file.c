/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peterlog <peterlog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 13:31:58 by peterlog          #+#    #+#             */
/*   Updated: 2019/10/11 15:51:15 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

int		dispatch_file(t_file *file, void *file_start)
{
	if (!ft_strncmp(file_start, ARMAG, SARMAG))
		return (handle_archive(file, file_start));
	else if (file->magic == FAT_MAGIC || file->magic == FAT_CIGAM)
		return (handle_fat_file(file, file_start));
	else if (file->magic == MH_MAGIC || file->magic == MH_CIGAM ||
file->magic == MH_MAGIC_64 || file->magic == MH_CIGAM_64)
		return (handle_macho_file(file, file_start));
	else
	{
		if (file->bin == NM)
			ft_printf("ft_nm: %s The file was not recognized as a valid object\
file\n\n", file->path);
		if (file->bin == OTOOL)
			ft_printf("%s: is not an object file\n", file->path);
		return (FAILURE);
	}
}

t_file	*init_file(char *path, void *file_start, size_t len, t_bin bin)
{
	t_file	*new;

	if (!(new = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	ft_bzero(new, sizeof(t_file));
	new->magic = *(uint32_t *)(file_start);
	new->bin = bin;
	if (!(new->path = strdup(path)))
		return (NULL);
	new->file_start = file_start;
	new->file_size = len;
	new->file_end = file_start + len;
	if (new->magic == MH_CIGAM || new->magic == MH_CIGAM_64 ||
				new->magic == FAT_CIGAM)
		new->swap_bits = 1;
	if (new->magic == MH_MAGIC_64 || new->magic == MH_CIGAM_64)
		new->arch = ARCH_64;
	new->print_path = true;
	return (new);
}

int		print_wrong_path(char *path, t_bin bin)
{
	ft_printf("%s: %s: No such file or directory.\n",
				(bin == NM) ? "ft_nm" : "ft_otool", path);
	return (FAILURE);
}

int		access_file(char *path, t_bin bin, bool args)
{
	t_file		*file;
	int			fd;
	void		*file_start;
	struct stat	buf;

	if ((fd = open(path, O_RDONLY)) < 0)
		return (print_wrong_path(path, bin));
	if (fstat(fd, &buf) < 0)
		return (FAILURE);
	if (buf.st_size == 0)
		return (FAILURE);
	if ((file_start = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) ==
				MAP_FAILED)
		return (FAILURE);
	if (!(file = init_file(path, file_start, buf.st_size, bin)))
		return (FAILURE);
	if (!dispatch_file(file, file_start))
		return (free_and_fail(file));
	dispatch_print_nm(file, bin, args);
	if (munmap(file_start, file->file_size) < 0 || close(fd) < 0)
		return (free_and_fail(file));
	free_structs(file);
	return (SUCCESS);
}
