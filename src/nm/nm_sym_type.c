/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_sym_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peterlog <peterlog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 18:03:12 by peterlog          #+#    #+#             */
/*   Updated: 2019/10/10 19:09:48 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

void	*find_mysection(t_list *sect_list, uint8_t n_sect)
{
	uint8_t	i;
	t_sect	*temp;

	i = 1;
	while (sect_list)
	{
		temp = (t_sect *)(sect_list->content);
		if (i == n_sect && sect_list)
			return (sect_list->content);
		i++;
		sect_list = sect_list->next;
	}
	return (NULL);
}

void	match_symbol_section(t_list *sect_list, t_sym *sym)
{
	t_sect	*sect;

	if ((sect = (t_sect *)find_mysection(sect_list, sym->n_sect)))
	{
		if (!ft_strcmp(sect->name, SECT_TEXT))
			sym->type = 'T';
		else if (!ft_strcmp(sect->name, SECT_DATA))
		{
			sym->type = 'D';
		}
		else if (!ft_strcmp(sect->name, SECT_BSS))
			sym->type = 'B';
		else
			sym->type = 'S';
		if (!(sym->n_type & N_EXT))
			sym->type -= 'A' - 'a';
	}
}

void	get_symbol_letter(t_sym *sym, t_file *file)
{
	if (N_STAB & sym->n_type)
		sym->type = '-';
	else if ((N_TYPE & sym->n_type) == N_UNDF)
	{
		if (sym->name_failed)
			sym->type = 'C';
		else if (sym->n_type & N_EXT)
			sym->type = 'U';
		else
			sym->type = '?';
	}
	else if ((N_TYPE & sym->n_type) == N_SECT)
		match_symbol_section(file->sections, sym);
	else if ((N_TYPE & sym->n_type) == N_ABS)
		sym->type = 'A';
	else if ((N_TYPE & sym->n_type) == N_INDR)
		sym->type = 'I';
}

void	match_symbol_types(t_file *file)
{
	t_list	*sym_list;
	t_list	*sect_list;
	t_sym	*current;

	if (!(sym_list = file->symbols) ||
					!(sect_list = file->sections))
		return ;
	while (sym_list)
	{
		current = (t_sym *)(sym_list->content);
		get_symbol_letter(current, file);
		sym_list = sym_list->next;
	}
}
