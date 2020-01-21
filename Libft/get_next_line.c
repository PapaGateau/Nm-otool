/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:04:57 by plogan            #+#    #+#             */
/*   Updated: 2017/06/06 11:13:01 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_ptr(int fd, char **rest, char **chr_ptr)
{
	char	buffer[BUFF_SIZE + 1];
	char	*free_ptr;
	int		ret;

	ret = 0;
	if (!*rest && !(*rest = ft_strnew(0)))
		return (-1);
	*chr_ptr = NULL;
	while (!(*chr_ptr = ft_strchr(*rest, '\n')) &&
			(ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		free_ptr = *rest;
		if (!(*rest = ft_strjoin(*rest, buffer)))
			return (-1);
		free(free_ptr);
	}
	if (*chr_ptr)
		return (1);
	if (**rest)
		return (1);
	return ((ret > 0) ? 1 : ret);
}

static int	ft_read_chr(char **line, t_fd *save)
{
	char		*ptr;
	char		*free_ptr;
	int			ret;

	if (save->fd < 0 || (ret = get_ptr(save->fd, &save->rest, &ptr)) == -1)
		return (-1);
	if (!save->rest)
		return (0);
	free_ptr = save->rest;
	if (ptr)
	{
		if (!(*line = ft_strsub(save->rest, 0, ptr - save->rest)) ||
				!(save->rest = ft_strdup(ptr + 1)))
			return (-1);
		free(free_ptr);
	}
	else if (!(*line = ft_strdup(save->rest)))
		return (-1);
	else if (save->rest)
	{
		free(save->rest);
		save->rest = NULL;
	}
	return (ret);
}

static t_fd	*make_new_link(int fd, t_fd *previous)
{
	t_fd		*new;

	if (!(new = (t_fd *)malloc(sizeof(t_fd))))
		return (new);
	new->rest = NULL;
	new->fd = fd;
	new->previous = previous;
	new->next = NULL;
	return (new);
}

int			get_next_line(int const fd, char **line)
{
	static t_fd	*save;
	int			ret;

	if (!save)
	{
		if (!(save = make_new_link(fd, NULL)))
			return (-1);
	}
	else
	{
		while (save->fd != fd && save->previous)
			save = save->previous;
		while (save->fd != fd && save->next)
			save = save->next;
	}
	if (save->fd == fd)
		return (ret = ft_read_chr(line, save));
	else
	{
		if (!(save->next = make_new_link(fd, save)))
			return (-1);
		save = save->next;
		return (ret = ft_read_chr(line, save));
	}
}
