# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alamit <alamit@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 15:56:07 by alamit            #+#    #+#              #
#    Updated: 2018/11/12 12:36:21 by alamit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libtest42f.a

SRC = test42f_bool.c test42f_char.c test42f_double.c test42f_int.c \
		test42f_intarr.c test42f_io.c test42f_new.c test42f_ptr.c \
		test42f_runtime.c test42f_str.c test42f_strarr.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
INCLUDE_DIRS = include

IFLAGS = $(INCLUDE_DIRS:%=-I%)
LFLAGS = $(LIB_DIRS:%=-L%) $(LIBS:%=-l%)

OUT := $(SRC:%.c=%.o)
SRC := $(SRC:%.c=$(SRC_DIR)/%.c)

RM = rm -rf

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) -c -g $(SRC)
	@ar -rcs $(NAME) $(OUT)

clean:
	@$(RM) $(OUT)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)
