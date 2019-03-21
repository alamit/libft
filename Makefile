# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alamit <alamit@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 14:37:28 by alamit            #+#    #+#              #
#    Updated: 2019/03/21 14:49:44 by alamit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GLOBAL CONFIG -------------------------------------------------------------- #

NAME = libft.a

DEBUG_EXEC = draft
DEBUG_MAIN = $(DEBUG_EXEC).c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = $(INC_DIR:%=-I%)
RM = rm -rf

# ---------------------------------------------------------------------------- #

# PROJECT STRUCTURE -----------------------------------------------------------#

SRC_DIR		=	src
INC_DIR		=	include
OBJ_DIR		=	obj

SRC			= 	$(FT_BIGINT) \
				$(FT_CONV) \
				$(FT_CTYPE) \
				$(FT_LIST) \
				$(FT_MATH) \
				$(FT_STDIO) \
				$(FT_STRING)

OBJ			=	$(SRC:%.c=$(OBJ_DIR)/%.o)

INCLUDE		=	ft_bigint.h \
				ft_conv.h \
				ft_ctype.h \
				ft_list.h \
				ft_math.h \
				ft_stdio.h \
				ft_string.h

FT_BIGINT	=	ft_bigint_add.c \
				ft_bigint_cmp.c \
				ft_bigint_div.c \
				ft_bigint_divpow10.c \
				ft_bigint_lshift.c \
				ft_bigint_new.c \
				ft_bigint_mulpow10.c \
				ft_bigint_rshift.c \
				ft_bigint_sub.c
FT_BIGINT	:=	$(FT_BIGINT:%.c=ft_bigint/%.c)

FT_CONV		=	ft_atoi.c \
				ft_itoa_buf.c \
				ft_itoa.c
FT_CONV		:=	$(FT_CONV:%.c=ft_conv/%.c)

FT_CTYPE	=	ft_char2num.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_isspace.c \
				ft_num2char.c \
				ft_tolower.c \
				ft_toupper.c
FT_CTYPE	:=	$(FT_CTYPE:%.c=ft_ctype/%.c)

FT_LIST		=	ft_lst_to_array.c \
				ft_lstadd.c \
				ft_lstdel.c \
				ft_lstdelone.c \
				ft_lstfoldleft.c \
				ft_lstiter.c \
				ft_lstlen.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lststrsplit.c
FT_LIST		:=	$(FT_LIST:%.c=ft_list/%.c)

FT_MATH		=	ft_abs.c \
				ft_ipow.c \
				ft_isprime.c \
				ft_isqrt.c \
				ft_lowersqrt.c
FT_MATH		:=	$(FT_MATH:%.c=ft_math/%.c)

FT_STDIO	=	ft_putchar_fd.c \
				ft_putchar.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_putstr.c
FT_STDIO	:=	$(FT_STDIO:%.c=ft_stdio/%.c)

FT_STRING	=	ft_bzero.c \
				ft_memalloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memdup.c \
				ft_memmove.c \
				ft_memset.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdel.c \
				ft_strdup.c \
				ft_strequ.c \
				ft_striter.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlen.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strncat.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strnequ.c \
				ft_strnew.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strsplit.c \
				ft_strstr.c \
				ft_strsub.c \
				ft_strtrim.c
FT_STRING	:=	$(FT_STRING:%.c=ft_string/%.c)

# ---------------------------------------------------------------------------- #


# COMPILATION RULES ---------------------------------------------------------- #

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compressing objects into $@"
	@ar -rcs $(NAME) $(OBJ)
	@echo "COMPILATION SUCCESSFUL"

debug: CFLAGS += -g
debug: $(NAME)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(DEBUG_EXEC) $(DEBUG_MAIN) $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(@D)
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: clean

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(DEBUG_EXEC)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

# ------------------------------------------------------------------------------ #
