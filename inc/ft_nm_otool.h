/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm_otool.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peterlog <peterlog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:23:29 by peterlog          #+#    #+#             */
/*   Updated: 2019/10/17 11:38:53 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_OTOOL_H
# define FT_NM_OTOOL_H

# include "../Libft/libft.h"
# include <fcntl.h>
# include <sys/mman.h>
# include <unistd.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdbool.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <mach/machine.h>
# include <ar.h>

# define MY_CPU_TYPE	CPU_TYPE_X86_64
# define MY_CPU_SUBTYPE	CPU_SUBTYPE_X86_64_ALL
# define SECT_LIST		1
# define SYM_LIST		2
# define SUCCESS		1
# define FAILURE		0

typedef	enum			e_bin
{
	NM,
	OTOOL
}						t_bin;

typedef enum			e_arch
{
	ARCH_32,
	ARCH_64
}						t_arch;

typedef struct			s_arch_flag
{
	char				*name;
	cpu_type_t			cputype;
	cpu_subtype_t		cpusubtype;
}						t_arch_flag;

typedef struct			s_sym
{
	char				*name;
	char				type;
	bool				name_failed;
	uint8_t				n_type;
	uint8_t				n_sect;
	uint64_t			n_value;
}						t_sym;

typedef struct			s_sect
{
	char				*name;
	uint64_t			addr;
	uint64_t			size;
	uint32_t			offset;
}						t_sect;

typedef struct			s_file
{
	uint32_t			magic;
	t_bin				bin;
	char				*path;
	bool				print_path;
	void				*file_start;
	uint64_t			file_size;
	void				*file_end;
	int					swap_bits;
	t_arch				arch;
	uint64_t			nsects;
	t_list				*sections;
	t_list				*symbols;
}						t_file;

typedef struct nlist	t_nlist;
typedef struct nlist_64	t_nlist64;

int						access_file(char *path, t_bin bin, bool args);
int						handle_macho_file(t_file *file, void *file_start);
int						handle_archive(t_file *file, void *file_start);
int						handle_fat_file(t_file *file, void *file_start);
void					process_otool(t_file *file, t_sect *section);
void					free_structs(t_file *file);
int						free_and_fail(t_file *file);
void					dispatch_print_nm(t_file *file, t_bin bin, bool args);
char					*get_arch_name(struct fat_arch *fat_arch, t_file *file);
int						match_cpu_type(struct fat_arch *fat_arch, t_file *file);
t_file					*init_file(char *path, void *file_start, size_t len,
				t_bin bin);
int						add_to_list(t_file *file, int type, void *data,
				uint64_t size);
void					add_symbol_alpha(t_list *new,
						t_file *file, t_list *first, t_list *second);
int						check_overflow(t_file *file, void *ptr);
char					*strdup_overflow(t_file *file, char *str,
				bool *name_failed, uint8_t type);
t_sym					*init_new_symbol(t_file *file,
				void *symtab, void *strtab, uint64_t i);
t_sect					*init_new_section(t_file *file, void *section);
void					match_symbol_types(t_file *file);
void					print_nm(t_list *symbols, t_arch arch);
int32_t					swapif_int32(t_file *file, int32_t x);
uint32_t				swapif_uint32(t_file *file, uint32_t x);
uint64_t				swapif_uint64(t_file *file, uint64_t x);
int						dispatch_file(t_file *file, void *file_start);

#endif
