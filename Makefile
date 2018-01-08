# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvermand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/03 21:37:06 by cvermand          #+#    #+#              #
#    Updated: 2018/01/08 21:43:30 by cvermand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# $@ -> all
# $< -> $(NAME)
# $< -> all after :

NAME = checker

CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra	
_SRC		=	stack_parser.c mainchecker.c stack_error_parser.c opperations.c
#SRC 		=	$(addprefix $)
BIN			=	$(_SRC:.c=.o)
RM			= /bin/rm

all : $(NAME)

$(NAME) : $(BIN)
	make -C libft
	#$(CC) $(FLAG) $(_SRC) libft/libft.a -I includes/
	$(CC) $(FLAG) $(BIN) -o $(NAME) libft/libft.a

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
