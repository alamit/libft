# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 14:37:28 by alamit            #+#    #+#              #
#    Updated: 2019/02/18 19:32:19 by alamit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GLOBAL CONFIG #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

NAME = libft.a

# libc functions
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c ft_tolower.c ft_isspace.c
# custom functions
SRC += ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
		ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
		ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_itoa_buf.c ft_memdup.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
		ft_lstiter.c ft_lstnew.c ft_lstmap.c ft_lstlen.c ft_lstfoldleft.c \
		ft_isqrt.c ft_isprime.c ft_ipow.c ft_lststrsplit.c get_next_line.c \
		ft_abs.c ft_lowersqrt.c ft_lst_to_array.c

INCLUDE = libft.h get_next_line.h

SRC_DIR = src
INCLUDE_DIR = include
INCLUDE_DIRS = $(INCLUDE_DIR)

IFLAGS = $(INCLUDE_DIRS:%=-I%)
OBJ_DIR = obj
OBJS := $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE:%.h=$(INCLUDE_DIR)/%.h)
	@mkdir -p $(OBJ_DIR)
	@ar -rcs $(NAME) $(OBJS)

debug: CFLAGS += -g
debug: $(NAME)
	@echo $(CFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: clean

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)
