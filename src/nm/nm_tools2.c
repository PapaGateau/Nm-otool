/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <plogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:05:07 by plogan            #+#    #+#             */
/*   Updated: 2019/10/17 11:47:59 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

char	*strdup_eol(const char *s1)
{
	int		i;
	int		size;
	char	*dup;
	int		eol;

	i = 0;
	size = 0;
	eol = 0;
	while (s1[size] && s1[size] != '\n')
	{
		size++;
		if (s1[size] == '\n')
			eol = 1;
	}
	dup = (char *)malloc(sizeof(char) * size + 1 + eol);
	if (dup == NULL)
		return (0);
	while (i < size + eol)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*strdup_indr(const char *str)
{
	char	*name;
	char	*half_str;
	char	*full_str;

	name = strdup_eol(str);
	half_str = ft_strjoin(name, " (indirect for ");
	full_str = ft_strjoin(half_str, name);
	free(name);
	free(half_str);
	return (full_str);
}

char	*strdup_overflow(t_file *file, char *str, bool *name_failed, uint8_t type)
{
	size_t	size;
	size_t	i;
	int		eol;

	eol = 0;
	size = 0;
	i = 0;
	while (((void *)str + size) > file->file_end && ((void *)str + size) <
					file->file_start && ft_isprint(str[size]) && str[size] &&
					str[size] != '\n')
	{
		size++;
		if (str[size] == '\n')
			eol = 1;
	}
	if (((void *)str + size) > file->file_end || ((void *)str + size) <
					file->file_start)
	{
		*name_failed = true;
		return (ft_strdup("bad string index"));
	}
	return ((N_TYPE & type) == N_INDR ? strdup_indr(str) : strdup_eol(str));
}

void	add_symbol_alpha(t_list *new, t_file *file, t_list *first,
				t_list *second)
{
	if ((strcmp(((t_sym *)new->content)->name,
									((t_sym *)first->content)->name)) < 0)
	{
		file->symbols = new;
		new->next = first;
	}
	while (first)
	{
		second = first->next;
		if ((strcmp(((t_sym *)new->content)->name,
				((t_sym *)first->content)->name)) >= 0
				&& (!second || (strcmp(((t_sym *)new->content)->name,
				((t_sym *)second->content)->name) < 0)))
		{
			first->next = new;
			new->next = second;
		}
		first = first->next;
	}
}
