# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 20:16:09 by tjuzen            #+#    #+#              #
#    Updated: 2019/09/07 18:40:03 by hde-ghel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRCS=src/ft_atoi.c src/ft_atoi.c src/ft_isalpha.c src/ft_isprint.c src/ft_memchr.c src/ft_memmove.c src/ft_putstr.c\
	 src/ft_strcmp.c src/ft_strncmp.c src/ft_strstr.c src/ft_bzero.c src/ft_isascii.c src/ft_memalloc.c\
	 src/ft_memcmp.c src/ft_memset.c src/ft_strcat.c src/ft_strcpy.c src/ft_strlen.c src/ft_strncpy.c\
	 src/ft_tolower.c src/ft_isalnum.c src/ft_isdigit.c src/ft_memccpy.c src/ft_memcpy.c\
	 src/ft_putchar.c src/ft_strchr.c src/ft_strdup.c src/ft_strncat.c src/ft_strrchr.c\
	 src/ft_toupper.c src/ft_putendl.c src/ft_putnbr.c src/ft_strnstr.c src/ft_putnbr_fd.c\
	 src/ft_putchar_fd.c src/ft_putendl_fd.c src/ft_putstr_fd.c src/ft_strclr.c src/ft_strnew.c\
	 src/ft_memalloc.c src/ft_memdel.c src/ft_strdel.c src/ft_strclr.c src/ft_striter.c src/ft_strmap.c\
	 src/ft_strmapi.c src/ft_strequ.c src/ft_strnequ.c src/ft_strsub.c src/ft_striteri.c\
	 src/ft_strjoin.c src/ft_strtrim.c src/ft_itoa.c src/ft_strsplit.c src/ft_strlcat.c src/ft_lstnew.c\
	 src/ft_lstdelone.c src/ft_lstdel.c src/ft_lstadd.c src/ft_lstiter.c src/ft_lstmap.c\
	 src/ft_printf/atoi_itoa.c src/ft_printf/check.c src/ft_printf/display_float.c \
	 src/ft_printf/display_i.c src/ft_printf/display_p.c\
	 src/ft_printf/display_precision_i.c src/ft_printf/display_sc.c\
	  src/ft_printf/display_x.c src/ft_printf/display.c\
	 src/ft_printf/handle_flags.c src/ft_printf/handle_spec.c \
	 src/ft_printf/handle_specc.c src/ft_printf/handle_speccc.c\
	 src/ft_printf/printf.c src/ft_printf/tools.c src/ft_printf/tools_2.c \
	 src/ft_printf/atoi_itoa.c src/ft_printf/display_float2.c\
	 src/ft_strjoin_free.c

O=ft_atoi.o ft_bzero.o ft_isascii.o ft_memalloc.o ft_memcmp.o ft_memset.o\
  ft_strcat.o ft_strcpy.o ft_strlen.o ft_strncpy.o ft_tolower.o ft_isalnum.o\
  ft_isdigit.o ft_memccpy.o ft_memcpy.o ft_putchar.o ft_strchr.o ft_strdup.o\
  ft_strncat.o ft_strrchr.o ft_toupper.o ft_isalpha.o ft_isprint.o ft_memchr.o\
  ft_memmove.o ft_putstr.o ft_strcmp.o ft_strncmp.o ft_strstr.o ft_putendl.o\
  ft_putnbr.o ft_strnstr.o ft_putnbr_fd.o ft_putchar_fd.o ft_putendl_fd.o\
  ft_putstr_fd.o ft_strclr.o ft_strnew.o ft_memalloc.o ft_memdel.o ft_strdel.o\
  ft_strclr.o ft_striter.o ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o\
  ft_strsub.o ft_striteri.o ft_strjoin.o ft_strtrim.o ft_itoa.o ft_strsplit.o\
  ft_strlcat.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o\
  ft_lstmap.o atoi_itoa.o check.o display_float.o display_i.o display_p.o\
  display_precision_i.o display_sc.o display_x.o display.o\
  handle_flags.o handle_spec.o handle_specc.o handle_speccc.o\
  printf.o tools.o tools_2.o display_float2.o ft_strjoin_free.o

FLAGS= -Wall -Wextra -Werror

GGCOLORCYAN = \033[96m
GGCOLORGREEN = \033[32m
GGCOLORRED = \033[31m
GGMAG = \033[1;35m
GGRESET = \033[39m

all: $(NAME)

$(NAME):
		@gcc -c -I $(SRCS)
		@ar rc $(NAME) $(O)
clean:
		@/bin/rm -rf $(O)

fclean: clean
		@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
