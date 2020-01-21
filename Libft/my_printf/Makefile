# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plogan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/25 20:54:36 by plogan            #+#    #+#              #
#    Updated: 2019/05/21 16:42:17 by plogan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC_NAME = ft_conv_c.c ft_conv_cc.c ft_conv_d.c ft_conv_dd.c \
		   ft_conv_e.c ft_conv_ee.c ft_conv_e2.c ft_conv_f.c ft_conv_ff.c \
		   ft_conv_n.c ft_conv_o.c ft_conv_oo.c ft_conv_p.c ft_conv_s.c \
		   ft_conv_ss.c ft_conv_u.c ft_conv_uu.c ft_conv_x.c ft_conv_xx.c \
		   ft_flag_hash.c ft_flag_null.c ft_flag_precision.c ft_flag_sign.c \
		   ft_flag_space.c ft_flag_width.c ft_flag_zero.c ft_printf.c \
		   ft_round_float.c ft_utoa_base.c handle_invalid.c handle_wildcard.c \
		   init_conv_tab.c init_tabs.c parse_conv.c parse_flags.c put_buffer.c \
		   raw_print.c handle_null.c

OBJS = $(SRC_NAME:.c=.o)

CC = @gcc 

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo "My_Printf:\033[92m OK\033[0m"

all: $(NAME) $(OBJS)
%.o: %.c
	$(CC) -c $< -o $@ $(FLAGS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@echo "Deleting:\033[33m $(NAME)\033[0m"

re: fclean all

.PHONY: clean fclean re
