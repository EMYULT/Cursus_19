# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 13:36:34 by tjuzen            #+#    #+#              #
#    Updated: 2019/05/14 13:36:35 by tjuzen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC = *.c
CC = gcc
CFLAG =
O = *.o
LIB = libft/libftprintf.a

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@$(CC) $(CFLAG) $(LIB) -o $(NAME) $(SRC) -Ift_ls/

clean:
	@make -C libft/ fclean
	@/bin/rm -f $(O)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
