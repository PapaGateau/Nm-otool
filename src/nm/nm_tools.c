/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peterlog <peterlog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:18:21 by peterlog          #+#    #+#             */
/*   Updated: 2019/10/17 11:15:37 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

t_sect	*init_new_section(t_file *file, void *section)
{
	t_sect	*new;

	if (!(new = (t_sect *)malloc(sizeof(t_sect))))
		return (new);
	ft_bzero(new, sizeof(t_sect));
	if (file->arch == ARCH_32)
	{
		if (!(new->name = ft_strdup(((struct section *)section)->sectname)))
			return (NULL);
		new->addr = swapif_uint32(file, ((struct section *)section)->addr);
		new->size = swapif_uint32(file, ((struct section *)section)->size);
		new->offset = swapif_uint32(file, ((struct section *)section)->offset);
	}
	else if (file->arch == ARCH_64)
	{
		if (!(new->name = ft_strdup(((struct section_64 *)section)->sectname)))
			return (NULL);
		new->addr = swapif_uint64(file, ((struct section_64 *)section)->addr);
		new->size = swapif_uint64(file, ((struct section_64 *)section)->size);
		new->offset = swapif_uint32(file,
						((struct section_64 *)section)->offset);
	}
	return (new);
}

t_sym	*init_new_symbol(t_file *file, void *symtab, void *strtab, uint64_t i)
{
	t_sym	*new;
	bool	name_failed;

	name_failed = false;
	if (!(new = (t_sym *)malloc(sizeof(t_sym))))
		return (new);
	ft_bzero(new, sizeof(t_sym));
	if (file->arch == ARCH_32)
	{
		new->n_type = ((t_nlist *)symtab + i)->n_type;
		new->name = strdup_overflow(file, strtab + swapif_uint32(file,
					((t_nlist *)symtab + i)->n_un.n_strx), &name_failed, new->n_type);
		new->n_sect = ((t_nlist *)symtab + i)->n_sect;
		new->n_value = swapif_uint32(file, ((t_nlist *)symtab + i)->n_value);
	}
	if (file->arch == ARCH_64)
	{
		new->n_type = ((t_nlist64 *)symtab + i)->n_type;
		new->name = strdup_overflow(file, strtab + swapif_uint32(file,
					((t_nlist64 *)symtab + i)->n_un.n_strx), &name_failed, new->n_type);
		new->n_sect = ((t_nlist64 *)symtab + i)->n_sect;
		new->n_value = swapif_uint64(file, ((t_nlist64 *)symtab + i)->n_value);
	}
	new->name_failed = name_failed;
	return (new);
}

void	add_node_to_last(t_list *new, t_list *first, t_list *iter)
{
	while (1)
	{
		if (!iter)
		{
			first->next = new;
			return ;
		}
		iter = iter->next;
		first = first->next;
	}
}

int		add_to_list(t_file *file, int type, void *data, uint64_t size)
{
	t_list	*first;
	t_list	*iter;
	t_list	*new;

	if (!(new = ft_lstnew(data, size)))
		return (FAILURE);
	if (type == SECT_LIST)
	{
		if (!file->sections)
			return ((file->sections = new) ? SUCCESS : FAILURE);
		first = file->sections;
		iter = file->sections->next;
		add_node_to_last(new, first, iter);
	}
	if (type == SYM_LIST)
	{
		if (!file->symbols)
			return ((file->symbols = new) ? SUCCESS : FAILURE);
		first = file->symbols;
		iter = file->symbols->next;
		add_symbol_alpha(new, file, first, iter);
	}
	return (SUCCESS);
}
