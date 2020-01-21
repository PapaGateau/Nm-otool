/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <plogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:31:38 by plogan            #+#    #+#             */
/*   Updated: 2019/10/10 19:57:21 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

int		free_and_fail(t_file *file)
{
	free_structs(file);
	return (FAILURE);
}

void	free_list(t_list *start)
{
	t_list *iter;

	while (1)
	{
		iter = start->next;
		if (start->content)
			free(start->content);
		free(start);
		start = iter;
		if (!start)
			break ;
	}
}

void	free_structs(t_file *file)
{
	if (file->path)
		free(file->path);
	if (file->symbols)
		free_list(file->symbols);
	if (file->sections)
		free_list(file->sections);
	free(file);
	(void)file;
}
