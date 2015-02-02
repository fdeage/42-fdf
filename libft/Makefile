#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 11:55:12 by fdeage            #+#    #+#              #
#    Updated: 2015/01/29 19:48:00 by fdeage           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libft.a

V =				0
SILENCE_1 :=
SILENCE_0 :=	@
SILENCE =		$(SILENCE_$(V))

CC			=	$(SILENCE)gcc

SRC			=	ft_memset.c ft_memcpy.c	\
				ft_mem_misc.c	\
				ft_strlen.c	\
				ft_strcpy.c ft_strdup.c	\
				ft_strcat.c	 ft_strjoin.c	\
				ft_strchr.c	ft_strstr.c	\
				ft_strcmp.c	\
				ft_atoi.c ft_itoa.c		\
				ft_is.c	ft_to.c\
				ft_memalloc.c	\
				ft_strnew.c ft_strdel.c ft_strclr.c	\
				ft_map_iter.c	\
				ft_strequ.c	\
				ft_strsub.c ft_strtrim.c	\
				ft_strsplit.c ft_strsplit_str.c	\
				ft_print.c ft_print_fd.c	\
				ft_gnl.c ft_color.c	\
				ft_error.c	\
				ft_list1.c ft_list2.c	\
				ft_strrev.c ft_pow_a.c ft_realloc.c	\
				ft_qsort.c ft_minmax.c

HDIR		=	./include/

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror -pedantic

SKIP_0 :=		\033[A
SKIP =			$(SKIP_$(V))
C =				\033[1;34m
U =				$(C)[$(NAME)]----->\033[0m

all			:	$(NAME)

$(NAME)		:	$(OBJ)
				@echo "$(U)$(C)[COMPILE:\033[1;32m DONE$(C)]\033[0m"
				@echo "$(U)$(C)[BUILD LIB]\033[0;32m"
				$(SILENCE)ar rc $(NAME) $(OBJ)
				$(SILENCE)ranlib $(NAME)
				chmod +x $(NAME)
				@echo "$(SKIP)$(U)$(C)[BUILD  :\033[1;32m DONE$(C)]\033[0m"

clean		:
				@echo "$(U)$(C)[CLEAN]\033[0;32m"
				rm -f $(OBJ)
				@echo "$(SKIP)$(U)$(C)[CLEAN:\033[1;32m   DONE$(C)]\033[0m"

fclean		:	clean
				@echo "$(U)$(C)[F-CLEAN]\033[1;32m"
				\rm -f $(NAME)
				\rm -f exe_test
				@echo "$(SKIP)$(U)$(C)[F-CLEAN:\033[1;32m DONE$(C)]\033[0m"

re			:	fclean all

%.o			:	%.c
				@echo "$(U)$(C)[COMPILE: \033[1;31m$<\033[A\033[0m"
				@echo "\033[0;32m"
				$(CC) $(CFLAGS) -c $< -o $@ -I $(HDIR)
				@echo "\033[1;31m [.working.]"
				@echo "$(SKIP)\033[A\033[2K$(SKIP)"

test		:
				$(CC) test/main_test.c $(NAME) -o exe_test -I $(HDIR)

test2		:
				$(CC) test/new_main.c $(NAME) -o exe_test2 -I $(HDIR)

extra		:	CFLAGS += --analyze -Weverything -Wno-missing-prototypes
extra		:	re

.PHONY		:	all clean fclean re test extra
