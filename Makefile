# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgarault <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 11:42:45 by fgarault          #+#    #+#              #
#    Updated: 2020/05/06 22:35:05 by fanny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fgarault.filler

# Compiler

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror -g3

# Links

LIBDIR	=	libft
LIBFT	=	$(LIBDIR)/libft.a

SRCDIR	=	src
SRCS 	=	main.c		\
			parsing.c	\
			solving.c	\
			strat.c		\
			tools.c

OBJDIR	=	src/obj
OBJS	=	$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

INCLUDE =	include/filler.h

# Default 

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(OBJDIR)%.o: src%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

$(LIBFT) : 
	make -C $(LIBDIR)

# Options

norme :
	@norminette $(SRCS)
	@make norme -C $(LIBDIR)

clean :
	@rm -rf $(OBJDIR) 
	@make clean -C $(LIBDIR)

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBDIR)

re : fclean all
