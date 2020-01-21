# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plogan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 21:05:23 by plogan            #+#    #+#              #
#    Updated: 2019/05/21 16:41:52 by plogan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC_NAME = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		   ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
		   ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		   ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		   ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		   ft_isprint.c ft_toupper.c ft_tolower.c \
		   ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
		   ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
		   ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
		   ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		   ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		   ft_lstmap.c get_next_line.c ft_wstrlen.c

OBJS = $(SRC_NAME:.c=.o)

PRINTF_PATH = my_printf/

INC = my_printf/ft_printf.h

CC = @gcc

all: $(NAME)

%.o: $(SRC_PATH)/%.c
	$(CC) $(FLAGS) -I $(INC) -c -o $@ $<

$(NAME): $(OBJS)
	@$(MAKE) -C $(PRINTF_PATH)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Library & Index:\033[92m OK\033[0m"

clean:
	@rm -f $(OBJS)
	@$(MAKE) clean -C $(PRINTF_PATH)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(PRINTF_PATH)
	@echo "Deleting:\033[33m $(NAME)\033[0m"

re: fclean all

.PHONY: clean fclean re
