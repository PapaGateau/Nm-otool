/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peterlog <peterlog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:55:42 by peterlog          #+#    #+#             */
/*   Updated: 2019/10/17 11:55:10 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

void	free_symbol(t_sym *symbol)
{
	if (symbol->name)
		free(symbol->name);
	free(symbol);
}

void	print_arch_64(t_sym *symbol)
{
	if (symbol->type == 'U')
		ft_printf("                 %c %s\n", symbol->type,
				symbol->name);
	else if (symbol->type == 'I')
		ft_printf("                 %c %s)\n", symbol->type,
				symbol->name);
	else if (symbol->type != '-')
		ft_printf("%016llx %c %s\n", symbol->n_value, symbol->type,
				symbol->name);
}

void	print_arch_32(t_sym *symbol)
{
	if (symbol->type == 'U')
		ft_printf("         %c %s\n", symbol->type, symbol->name);
	else if (symbol->type == 'I')
		ft_printf("         %c %s)\n", symbol->type, symbol->name);
	else if (symbol->type != '-')
		ft_printf("%08llx %c %s\n", symbol->n_value, symbol->type,
						symbol->name);
}

void	print_nm(t_list *symbols, t_arch arch)
{
	t_sym *symbol;

	while (symbols)
	{
		symbol = (t_sym *)(symbols->content);
		if (!symbol->type)
			symbol->type = ' ';
		if (arch == ARCH_64)
			print_arch_64(symbol);
		else if (arch == ARCH_32)
			print_arch_32(symbol);
		free_symbol(symbol);
		symbols->content = NULL;
		symbols = symbols->next;
	}
	return ;
}
