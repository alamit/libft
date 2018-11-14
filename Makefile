# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alamit <alamit@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 14:37:28 by alamit            #+#    #+#              #
#    Updated: 2018/11/13 17:31:03 by alamit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GLOBAL CONFIG #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# TARGET CONFIG #

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
		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_streq.c \
		ft_strneq.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
		ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRC_DIR = src
INCLUDE_DIRS = include
#LIB_DIRS = #YOUR_LIB_DIRS#
#LIBS = #YOUR_LIBS#

IFLAGS = $(INCLUDE_DIRS:%=-I%)
LFLAGS = $(LIB_DIRS:%=-L%) $(LIBS:%=-l%)

OUT := $(SRC:%.c=%.o)

# TEST CONFIG #

TEST_NAME = run_tests
TEST_DIR = test
TEST_MAIN = $(TEST_DIR)/$(TEST_NAME).c
TEST_LIBS = test42f
TEST_SRC = $(SRC:%=test_%)

all: $(NAME)

$(NAME): $(SRC:%.c=$(SRC_DIR)/%.c)
	@$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) -c $(SRC:%.c=$(SRC_DIR)/%.c)
	@ar -rcs $(NAME) $(OUT)

test: INCLUDE_DIRS += $(TEST_LIBS:%=$(TEST_DIR)/lib/%/include) $(TEST_DIR)
test: LIB_DIRS += $(TEST_LIBS:%=$(TEST_DIR)/lib/%)
test: LIBS += $(TEST_LIBS)
test: MAKE_LIBS := $(LIB_DIRS:%=$(MAKE) -C %)
test: CLEAN_LIBS := $(LIB_DIRS:%=$(MAKE) -C % fclean)
test: clean
	@echo Building test42f lib...
	@$(MAKE_LIBS)
	@echo Done.
	@echo Building $(NAME) with tests...
	@$(CC) -g $(CFLAGS) $(IFLAGS) $(LFLAGS) -o $(TEST_NAME) $(TEST_MAIN) \
		$(SRC:%.c=$(SRC_DIR)/%.c) $(TEST_SRC:%.c=$(TEST_DIR)/%.c)
	@echo Done.
	@echo Running tests...
	@./$(TEST_NAME)
	@echo Done.
	@echo Cleaning up...
	@$(CLEAN_LIBS)
	@echo Done.

create:
	@touch $(SRC:%.c=$(SRC_DIR)/%.c)
	@touch $(TEST_SRC:%.c=$(TEST_DIR)/%.c)

clean:
	@$(RM) $(OUT)
	@$(RM) $(TEST_NAME)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)
