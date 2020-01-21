/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macho_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peterlog <peterlog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 13:56:44 by peterlog          #+#    #+#             */
/*   Updated: 2019/10/17 11:13:57 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

void	parse_symtab_command(struct symtab_command *symc, void *sym,
	t_file *file, uint32_t i)
{
	void		*strtab;
	void		*symtab;
	uint64_t	sym_size;
	t_sym		*new;

	new = NULL;
	strtab = file->file_start + swapif_uint32(file, symc->stroff);
	symtab = file->file_start + swapif_uint32(file, symc->symoff);
	sym_size = ((file->arch == ARCH_32) ? sizeof(struct nlist) :
				sizeof(struct nlist_64));
	while (i < swapif_uint32(file, symc->nsyms))
	{
		if (!check_overflow(file, strtab) || !check_overflow(file, symtab))
			return ;
		if (!(new = init_new_symbol(file, symtab, strtab, i)))
			return ;
		if (!(add_to_list(file, SYM_LIST, (void *)new, sizeof(t_sym))))
			return ;
		i++;
		free(new);
		sym += sym_size;
	}
}

void	parse_segment_command(void *segc, t_file *file)
{
	uint32_t	nsects;
	void		*section;
	uint64_t	size;
	t_sect		*new;

	section = (segc + ((file->arch == ARCH_32) ?
		sizeof(struct segment_command) : sizeof( struct segment_command_64)));
	nsects = swapif_uint32(file, ((file->arch == ARCH_32) ?
		((struct segment_command *)segc)->nsects :
		((struct segment_command_64 *)segc)->nsects));
	while (nsects-- && check_overflow(file, section))
	{
		size = ((file->arch == ARCH_32) ? sizeof((struct section *)section) :
				sizeof((struct section_64 *)section));
		if (!(new = init_new_section(file, section)))
			return ;
		if (!(add_to_list(file, SECT_LIST, (void *)new, sizeof(t_sect))))
			return ;
		else if (file->bin == OTOOL)
			process_otool(file, new);
		section += (file->arch == ARCH_32 ? sizeof(struct section) :
			sizeof(struct section_64));
	}
}

void	parse_load_command(struct load_command *lc, t_file *file)
{
	struct symtab_command	*symc;
	void					*sym;
	uint32_t				i;
	uint32_t				cmd;

	i = 0;
	sym = NULL;
	symc = NULL;
	cmd = swapif_uint32(file, lc->cmd);
	if (cmd == LC_SEGMENT || cmd == LC_SEGMENT_64)
		parse_segment_command(lc, file);
	else if (cmd == LC_SYMTAB)
	{
		symc = (struct symtab_command *)lc;
		sym = (void *)file->file_start + swapif_uint32(file, symc->symoff);
		if (!check_overflow(file, sym))
			return ;
		parse_symtab_command(symc, sym, file, i);
	}
}

int		handle_macho_file(t_file *file, void *file_start)
{
	struct load_command	*lc;
	uint32_t			ncmds;

	ncmds = 0;
	if (file->magic == MH_MAGIC || file->magic == MH_CIGAM)
	{
		ncmds = swapif_uint32(file, ((struct mach_header *)file_start)->ncmds);
		lc = (struct load_command *)(file_start + sizeof(struct mach_header));
	}
	else if (file->magic == MH_MAGIC_64 || file->magic == MH_CIGAM_64)
	{
		ncmds = swapif_uint32(file,
			((struct mach_header_64 *)file_start)->ncmds);
		lc = (struct load_command *)(file_start +
			sizeof(struct mach_header_64));
	}
	while (ncmds--)
	{
		if (!check_overflow(file, (void *)lc))
			return (FAILURE);
		parse_load_command(lc, file);
		lc = (void *)lc + swapif_uint32(file, lc->cmdsize);
	}
	return (SUCCESS);
}
