/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 18:52:22 by plogan            #+#    #+#             */
/*   Updated: 2017/06/06 12:16:36 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>
# include <wchar.h>

# define CONVERSIONS			"sSpdDioOuUxXcCfFeEn%"
# define FLAGS					"#-+ 0123456789*.jzhl"
# define FORM_FLAGS				"#-+ 0123456789*."
# define CONV_FLAGS				"jzhl"

# define PRINTF_BUFF_SIZE		1000

typedef struct	s_buffer
{
	char		*buffer;
	int			len;
}				t_buffer;

typedef struct	s_flag
{
	char		conv;
	int			flag_hash;
	int			flag_zero;
	int			flag_minus;
	int			flag_sign;
	int			flag_space;
	int			flag_width;
	int			flag_precision;
	int			flag_null;
	int			bytes;
	enum {
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}			data_type;
}				t_flag;

typedef struct	s_conv
{
	char		conv;
	char		*(*ft)(va_list *arg, t_flag *flag_tab);
}				t_conv;
/*
**				PROCESS
*/
int				ft_printf(const char *restrict format, ...);
int				raw_print(int *i, const char *format);
int				parse_conv(int *i, int *bytes, const char *format,
			va_list *arg);
void			parse_flags(int *i, const char *format, t_flag *flag_tab,
			va_list *arg);
void			init_tabs(t_flag *tab, int *bytes, t_conv *conv_tab);
void			init_conv_tab(t_conv *tab);
int				print_raw(char *ptr);
char			*ft_utoa_base(uintmax_t nb, uintmax_t base_size);
long double		ft_round_float(long double f, int precision);
int				handle_invalid(int *i, char **str, t_flag *flag_tab,
			const char *format);
void			handle_wildcard(int *i, const char *format, t_flag *flag_tab,
			va_list *arg);
void			handle_null(char **str, t_flag *flag_tab);
int				put_buffer(const char *str, int len, int end);

/*
**				FLAG
*/
void			ft_flag_hash(char **str, t_flag *flag_tab);
void			ft_flag_zero(char **str, t_flag *flag_tab);
void			ft_flag_sign(char **str, t_flag *flag_tab);
void			ft_flag_space(char **str, t_flag *flag_tab);
void			ft_flag_width(char **str, t_flag *flag_tab);
void			ft_flag_precision(char **str, t_flag *flag_tab);
int				ft_flag_null(t_flag *flag_tab);
/*
**				CONVERSION
*/
char			*ft_conv_c(va_list *arg, t_flag *flag_tab);
char			*ft_conv_cc(va_list *arg, t_flag *flag_tab);
char			*ft_conv_s(va_list *arg, t_flag *flag_tab);
char			*ft_conv_ss(va_list *arg, t_flag *flag_tab);
char			*ft_conv_p(va_list *arg, t_flag *flag_tab);
char			*ft_conv_d(va_list *arg, t_flag *flag_tab);
char			*ft_conv_dd(va_list *arg, t_flag *flag_tab);
char			*ft_conv_o(va_list *arg, t_flag *flag_tab);
char			*ft_conv_oo(va_list *arg, t_flag *flag_tab);
char			*ft_conv_u(va_list *arg, t_flag *flag_tab);
char			*ft_conv_uu(va_list *arg, t_flag *flag_tab);
char			*ft_conv_x(va_list *arg, t_flag *flag_tab);
char			*ft_conv_xx(va_list *arg, t_flag *flag_tab);
/*
**				BONUS
*/
char			*ft_conv_f(va_list *arg, t_flag *flag_tab);
char			*ft_conv_ff(va_list *arg, t_flag *flag_tab);
char			*ft_conv_e(va_list *arg, t_flag *flag_tab);
char			*ft_conv_e2(long double f, int afterpoint);
char			*ft_conv_ee(va_list *arg, t_flag *flag_tab);
char			*ft_conv_n(va_list *arg, t_flag *flag_tab);

#endif
