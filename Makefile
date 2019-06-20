# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgarault <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 11:42:45 by fgarault          #+#    #+#              #
#    Updated: 2019/06/20 16:37:25 by fgarault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fgarault.filler

# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Links
SRCDIR = ./srcs/
LIBDIR = ./libft/

SRCS = $(addprefix src/, \
	   main.c parsing.c)
OBJS = $(SRCS:.c=.o)
INC = ./include/filler.h


LIBFT = ./libft/libft.a

# Default 
all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $@

%.o:%.c $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(LIBFT) :
	@make -C libft

norme :
	norminette $(SRCS)
	@make norme -C libft

clean :
	rm -f $(OBJS) 
	@make clean -C libft

fclean : clean

re : fclean all

play : $(NAME) 
	@mv $(NAME) resources/players && cd resources && ./filler_vm -f maps/map00 -p1 ./players/superjeannot.filler -p2 ./players/fgarault.filler 

