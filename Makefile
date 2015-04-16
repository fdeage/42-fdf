#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 16:38:06 by fdeage            #+#    #+#              #
#    Updated: 2015/04/16 10:51:39 by fdeage           ###   ########.fr        #
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

INC			=	-I./include -I./libft/include
LINK		=	-Llibft -lft $(LDFLAGS) $(MLXFLAGS)

CFLAGS		=	-Wall -Wextra -Werror -g3 -pedantic
EXTRAFLAGS	=	--analyze -Weverything -Wno-missing-prototypes -Qunused-arguments
LDFLAGS		=	-L/usr/X11/lib
MLXFLAGS	=	-lmlx -lXext -lX11
FLAGS		=	$(CFLAGS) $(MLXFLAGS) $(LDFLAGS)

CC			=	/usr/bin/gcc
RM			=	/bin/rm -v

all			:	$(NAME)

$(NAME)		:	$(OBJ)
				make -C ./libft
				$(CC) $(FLAGS) $(INC) $(LINK) $(OBJ) -o $(NAME)
clean		:
				make -C ./libft clean
				$(RM) $(OBJ)

fclean		:	clean
				make -C ./libft fclean
				$(RM) $(NAME)

re			:	fclean all

extra       :   FLAGS += $(EXTRAFLAGS)
extra       :   re

%.o			:	%.c
				$(CC) $(CFLAGS) $(INC) -c $< -o $@
