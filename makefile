# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgarault <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/07 17:50:20 by fgarault          #+#    #+#              #
#    Updated: 2019/04/12 19:34:31 by fgarault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
		ft_strncpy.c ft_strcat.c ft_strncat.c

OBJS = $(SRCS:.c=.o)
INCLUDE = libft.h

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS) -I $(INCLUDE)

norme :
	 norminette -R CheckForbiddenSourceHeader $(SRCS) $(INLCUDE)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
