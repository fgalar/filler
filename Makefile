# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgarault <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 11:42:45 by fgarault          #+#    #+#              #
#    Updated: 2020/03/05 14:24:08 by fgarault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fgarault.filler

# Compiler
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

# Links

LIBDIR	=	libft/
LIBFT	=	$(LIBDIR)libft.a

SRCDIR	=	src
SRCS 	=	$(addprefix $(SRCDIR)/, main.c		\
									parsing.c	\
									solving.c	\
									strat.c		)

OBJDIR	=	src/obj
OBJS	=	$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

INCLUDE =	./include/filler.h

# Default 
all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $@

$(OBJS): | $(OBJDIR)

$(OBJDIR)%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJDIR) :
	@mkdir $@

$(LIBFT) :
	@make -C $(LIBDIR)

norme :
	@norminette $(SRCS)
	@make norme -C $(LIBDIR)

clean :
	@rm -f $(OBJS) 
	@make clean -C $(LIBDIR)

fclean : clean
	@rm -f $(NAME)
	@make fclean -C $(LIBDIR)

re : fclean all

player : $(NAME) 
	@mv $(NAME) resources/players

