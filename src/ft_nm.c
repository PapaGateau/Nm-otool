/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peterlog <peterlog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 13:09:03 by peterlogan        #+#    #+#             */
/*   Updated: 2019/10/11 15:52:03 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_nm_otool.h"

int	main(int argc, char **argv)
{
	t_bin	bin;
	int		i;

	bin = NM;
	i = 1;
	if (argc == 1)
	{
		if (!access_file("a.out", bin, false))
			return (EXIT_FAILURE);
	}
	else
	{
		while (i < argc)
		{
			if (!access_file(argv[i], bin, (argc > 2) ? true : false))
				return (EXIT_FAILURE);
			i++;
		}
	}
	return (EXIT_SUCCESS);
}
