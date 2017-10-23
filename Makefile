# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opodolia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/03 13:55:22 by opodolia          #+#    #+#              #
#    Updated: 2017/03/20 20:16:39 by opodolia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
NAME_BASE = libftprintf

# compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# ft_printf directories
P_SRC_DIR = ./src/
P_OBJ_DIR = ./obj/
P_INC_DIR = ./includes/

# libft directories
L_SRC_DIR = ./libft/src/
L_OBJ_DIR = ./libft/obj/
L_INC_DIR = ./libft/includes/

# ft_printf source files
P_FILES = ft_printf.c parser.c parameters.c number.c symbol.c string.c \
		  no_specifier.c push_right_left.c get_size.c is_multibyte.c

P_SRC = $(addprefix $(P_SRC_DIR), $(P_FILES))
P_OBJ = $(addprefix $(P_OBJ_DIR), $(P_FILES:.c=.o))

# libft source files
L_FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		  ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c \
		  ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
		  ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		  ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_strnew.c \
		  ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
		  ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
		  ft_strjoin_free.c ft_strtrim.c ft_strsplit.c ft_strrev.c \
		  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		  ft_lstmap.c ft_atoi.c ft_itoa.c ft_uitoa_base.c ft_isalpha.c \
		  ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
		  ft_tolower.c ft_wclen.c ft_wcslen.c ft_wctomb.c ft_wcstombs.c \
		  ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
		  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

L_SRC = $(addprefix $(L_SRC_DIR), $(L_FILES))
L_OBJ = $(addprefix $(L_OBJ_DIR), $(L_FILES:.c=.o))

.SILENT:

all: $(NAME)
	echo "\n\033[38;5;44m☑    Done \033[0m\033[K"

$(P_OBJ_DIR)%.o: $(P_SRC_DIR)%.c
	printf "\r\033[38;5;11m⌛    make: please wait...\033[0m\033[K"
	mkdir -p $(P_OBJ_DIR)
	$(CC) $(CFLAGS) -I $(P_INC_DIR) -o $@ -c $<

$(L_OBJ_DIR)%.o: $(L_SRC_DIR)%.c
	printf "\r\033[38;5;11m⌛    make: please wait...\033[0m\033[K"
	mkdir -p $(L_OBJ_DIR)
	$(CC) $(CFLAGC) -I $(L_INC_DIR) -o $@ -c $<

OBJECTS = $(P_OBJ) $(L_OBJ)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	printf "\r\033[38;5;11m⌛    clean: please wait...\033[0m\033[K"
	rm -rf $(P_OBJ_DIR) $(L_OBJ_DIR)
	printf "\n\033[38;5;44m☑    Done\033[0m\033[K\n"

fclean: clean
	printf "\r\033[38;5;11m⌛    fclean: please wait...\033[0m\033[K"
	rm -f $(NAME)
	printf "\n\033[38;5;44m☑    Done\033[0m\033[K\n"

re: fclean all

.PHONY: fclean clean re
