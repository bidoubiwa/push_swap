# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvermand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/03 21:37:06 by cvermand          #+#    #+#              #
#    Updated: 2018/01/04 00:48:31 by cvermand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# $@ -> all
# $< -> $(NAME)
# $< -> all after :

NAME = checker

SRC			=	mainchecker.c

CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra	

RM			= /bin/rm

all : $(NAME)

$(NAME) : $(BIN)
	make -C libft
	gcc $(SRC) -o $(NAME) libft/libft.a -I includes/

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I includes/

clean :
	make clean -C libft
	rm -f $(BIN)

fclean : clean
	make fclean -C libft
	rm -f $(NAME)

re : 
	make fclean
	make fclean -C libft
	make
