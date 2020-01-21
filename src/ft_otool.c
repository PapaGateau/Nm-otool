/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <plogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:26:34 by plogan            #+#    #+#             */
/*   Updated: 2019/10/11 15:30:52 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_nm_otool.h"

int	main(int argc, char **argv)
{
	t_bin	bin;
	int		i;

	bin = OTOOL;
	i = 1;
	if (argc == 1)
	{
		ft_printf("error: ft_otool: at least one file must be specified\n");
		ft_printf("Usage: ft_otool <object_file> ...\n");
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
