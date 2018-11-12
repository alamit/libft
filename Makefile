# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alamit <alamit@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 14:37:28 by alamit            #+#    #+#              #
#    Updated: 2018/11/12 10:57:52 by alamit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GLOBAL CONFIG #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# TARGET CONFIG #

NAME = libft.a
SRC = ft_memset.c ft_bzero.c

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
	@$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) -o $(TEST_NAME) $(TEST_MAIN) \
		$(SRC:%.c=$(SRC_DIR)/%.c) $(TEST_SRC:%.c=$(TEST_DIR)/%.c)
	@echo Done.
	@echo Running tests...
	@./$(TEST_NAME)
	@echo Done.
	@echo Cleaning up...
	@$(CLEAN_LIBS)
	@echo Done.

clean:
	@$(RM) $(OUT)
	@$(RM) $(TEST_NAME)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)
