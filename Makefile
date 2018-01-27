# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvermand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/13 15:04:29 by cvermand          #+#    #+#              #
#    Updated: 2018/01/27 16:12:40 by cvermand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER		=	checker
PUSH_SWAP	=	push_swap

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

_SRCS		=	tab_struct.c stack_error_parser.c opperations.c\
				opp_struct.c show_functions.c executions_fct.c \
				sorted.c

_PS_SRCS	=	pushswap.c options_swap.c simple_sort.c quick_sort.c \
				compare_fct.c merge_instructions.c
_PS_SRCS	+=	$(_SRCS)
_C_SRCS		=	mainchecker.c options_checker.c
_C_SRCS		+=	$(_SRCS)
_LIBFT		=	libft.a

SRCS_DIR	=	.
LIB_DIR		=	libft
PS_SRCS		=	$(addprefix $(SRCS_DIR)/, $(_PS_SRCS))
C_SRCS		=	$(addprefix	$(SRCS_DIR)/, $(_C_SRCS))
LIBFT		=	$(addprefix $(LIB_DIR)/, $(_LIBFT))

C_OBJS		=	$(C_SRCS:.c=.o)
PS_OBJS		=	$(PS_SRCS:.c=.o)

all:	$(CHECKER) $(PUSH_SWAP)

$(CHECKER) : $(LIBFT) $(C_OBJS)
	@$(CC) $(CFLAGS) -o $(CHECKER) $(C_OBJS) -L$(LIB_DIR) -lft 
	@echo "$(CHECKER) : $(_GREEN)Done$(_END)"

$(PUSH_SWAP): $(LIBFT) $(PS_OBJS)
	@$(CC) $(CFLAGS) -o $(PUSH_SWAP) $(PS_OBJS) -L$(LIB_DIR) -lft
	@echo "$(PUSH_SWAP) : $(_GREEN)Done$(_END)"

$(LIBFT):
	@make -C $(LIB_DIR)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I includes/

clean:
	@make fclean -C $(LIB_DIR)
	@/bin/rm -f $(C_OBJS) $(PS_OBJS)
	@echo "push_swap clean : $(_GREEN)Done$(_END)"

fclean: clean
	@/bin/rm -f $(CHECKER) $(PUSH_SWAP)
	@echo "push_swap fclean : $(_GREEN)Done$(_END)"

re:
	@make fclean
	@make

.PHONY: all clean fclean re

