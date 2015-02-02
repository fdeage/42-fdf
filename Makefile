#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 16:38:06 by fdeage            #+#    #+#              #
#    Updated: 2015/02/02 13:55:08 by fdeage           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fdf

SRC 		=	main.c					\
				read.c					\
				handle_tab.c			\
				compute_projection.c	\
				draw_utilities.c		\
				key_handling.c			\
				errors.c

OBJ			=	$(SRC:.c=.o)

INC			=	-I./include -I./libft/include -Llibft -lft

CFLAGS		=	-Wall -Wextra -Werror -g3
EXTRAFLAGS	=	-pedantic --analyze -Weverything
LDFLAGS		=	-L/usr/X11/lib
MLXFLAGS	=	-lmlx -lXext -lX11
FLAGS		=	$(CFLAGS) $(MLXFLAGS) $(LDFLAGS)

CC			=	gcc
RM			=	/bin/rm -v

all			:	$(NAME)

$(NAME)		:	$(OBJ)
				make -C ./libft
				$(CC) $(FLAGS) $(INC) $(OBJ) -o $(NAME)
clean		:
				make -C ./libft clean
				$(RM) $(OBJ)

fclean		:	clean
				make -C ./libft fclean
				$(RM) $(NAME)

re			:	fclean all

%.o			:	%.c
				$(CC) $(FLAGS) $(INC) -c $< -o $@
