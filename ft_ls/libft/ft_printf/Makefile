# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/18 11:05:39 by tjuzen            #+#    #+#              #
#    Updated: 2019/01/21 12:55:49 by tjuzen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRCS= atoi_itoa.c check.c display_float.c display_i.c display_p.c\
	  display_precision_i.c display_sc.c display_x.c display.c


	 handle_flags.c handle_spec.c handle_specc.c handle_speccc.c\
	  printf.c tools.c tools_2.c atoi_itoa.c display_float2.c

O= atoi_itoa.o check.o display_float.o display_i.o display_p.o\
	display_precision_i.o display_sc.o display_x.o display.o


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
		@echo "$(GGCOLORCYAN)COMPILATION$(GGRESET)..."
		@echo "$(GGCOLORGREEN)OK $(GGRESET)[$(GGCOLORGREEN)✔$(GGRESET)]"
clean:
		@/bin/rm -rf $(O)
		@echo "$(GGCOLORCYAN)CLEAN$(GGRESET)..."
		@echo "$(GGCOLORGREEN)OK $(GGRESET)[$(GGCOLORGREEN)✔$(GGRESET)]"

fclean: clean
		@/bin/rm -rf $(NAME)
		@echo "$(GGCOLORCYAN)FCLEAN$(GGRESET)..."
		@echo "$(GGCOLORGREEN)OK $(GGRESET)[$(GGCOLORGREEN)✔$(GGRESET)]"

re: fclean all

.PHONY: all clean fclean re
