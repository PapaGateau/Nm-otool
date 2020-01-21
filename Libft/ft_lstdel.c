/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:19:56 by plogan            #+#    #+#             */
/*   Updated: 2017/04/14 12:57:46 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*point;
	t_list	*remove;

	if (!*alst || !alst || !del)
		return ;
	point = *alst;
	while (point)
	{
		remove = point;
		point = point->next;
		del(remove->content, remove->content_size);
		free(point);
	}
	ft_memdel((void **)alst);
}
