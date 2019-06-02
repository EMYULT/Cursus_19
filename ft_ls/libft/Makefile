# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 20:16:09 by tjuzen            #+#    #+#              #
#    Updated: 2018/11/09 16:55:52 by tjuzen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRCS=ft_atoi.c ft_atoi.c ft_isalpha.c ft_isprint.c ft_memchr.c ft_memmove.c ft_putstr.c\
	 ft_strcmp.c ft_strncmp.c ft_strstr.c ft_bzero.c ft_isascii.c ft_memalloc.c\
	 ft_memcmp.c ft_memset.c ft_strcat.c ft_strcpy.c ft_strlen.c ft_strncpy.c\
	 ft_tolower.c ft_isalnum.c ft_isdigit.c ft_memccpy.c ft_memcpy.c\
	 ft_putchar.c ft_strchr.c ft_strdup.c ft_strncat.c ft_strrchr.c\
	 ft_toupper.c ft_putendl.c ft_putnbr.c ft_strnstr.c ft_putnbr_fd.c\
	 ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_strclr.c ft_strnew.c\
	 ft_memalloc.c ft_memdel.c ft_strdel.c ft_strclr.c ft_striter.c ft_strmap.c\
	 ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_striteri.c\
	 ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strsplit.c ft_strlcat.c ft_lstnew.c\
	 ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
	 ./ft_printf/atoi_itoa.c ./ft_printf/check.c ./ft_printf/display_float.c ./ft_printf/display_i.c ./ft_printf/display_p.c\
	 ./ft_printf/display_precision_i.c ./ft_printf/display_sc.c ./ft_printf/display_x.c ./ft_printf/display.c\
	 ./ft_printf/handle_flags.c ./ft_printf/handle_spec.c ./ft_printf/handle_specc.c ./ft_printf/handle_speccc.c\
	 ./ft_printf/printf.c ./ft_printf/tools.c ./ft_printf/tools_2.c ./ft_printf/atoi_itoa.c ./ft_printf/display_float2.c\

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
  printf.o tools.o tools_2.o display_float2.o

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
