# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alamit <alamit@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 14:37:28 by alamit            #+#    #+#              #
#    Updated: 2019/07/12 13:06:19 by alamit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GLOBAL CONFIG -------------------------------------------------------------- #

NAME = libftprintf.a

DEBUG_EXEC = draft
DEBUG_MAIN = $(DEBUG_EXEC).c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = $(INC_DIR:%=-I%)
RM = rm -rf

# ---------------------------------------------------------------------------- #

# PROJECT STRUCTURE -----------------------------------------------------------#

SRC_DIR			=	src
INC_DIR			=	include
OBJ_DIR			=	obj

SRC				= 	$(FT_BIGINT) \
					$(FT_BUFF) \
					$(FT_CONV) \
					$(FT_CTYPE) \
					$(FT_FLOAT) \
					$(FT_FLOAT_PARAMS) \
					$(FT_FORMAT) \
					$(FT_LIST) \
					$(FT_MATH) \
					$(FT_STDIO) \
					$(FT_STRING) \
					$(FT_VPRINTF)

OBJ				=	$(SRC:%.c=$(OBJ_DIR)/%.o)

INCLUDE			=	ft_bigint.h \
					ft_buff.h \
					ft_conv.h \
					ft_ctype.h \
					ft_float.h \
					ft_float_params.h \
					ft_floattypes.h \
					ft_format.h \
					ft_list.h \
					ft_math.h \
					ft_stdio.h \
					ft_string.h \
					ft_vprintf.h

FT_BIGINT		=	ft_bigint_add.c \
					ft_bigint_cmp.c \
					ft_bigint_div.c \
					ft_bigint_divpow10.c \
					ft_bigint_lshift.c \
					ft_bigint_new.c \
					ft_bigint_mulpow10.c \
					ft_bigint_rshift.c \
					ft_bigint_sub.c
FT_BIGINT		:=	$(FT_BIGINT:%.c=ft_bigint/%.c)

FT_BUFF			=	ft_buff_init.c \
					ft_buff.c \
					ft_buffc.c \
					ft_buffs.c \
					ft_debuff.c
FT_BUFF			:=	$(FT_BUFF:%.c=ft_buff/%.c)

FT_CONV			=	ft_atoi.c \
					ft_conv_b.c \
					ft_conv_c.c \
					ft_conv_d.c \
					ft_conv_e.c \
					ft_conv_f.c \
					ft_conv_o.c \
					ft_conv_s.c \
					ft_conv_u.c \
					ft_conv_x.c \
					ft_fconv_b.c \
					ft_fconv_c.c \
					ft_fconv_d.c \
					ft_fconv_e.c \
					ft_fconv_f.c \
					ft_fconv_o.c \
					ft_fconv_s.c \
					ft_fconv_u.c \
					ft_fconv_u_base.c \
					ft_fconv_integer.c \
					ft_fconv_x.c \
					ft_vfconv_b.c \
					ft_vfconv_c.c \
					ft_vfconv_d.c \
					ft_vfconv_e.c \
					ft_vfconv_f.c \
					ft_vfconv_o.c \
					ft_vfconv_s.c \
					ft_vfconv_u.c \
					ft_vfconv_x.c \
					ft_itoa.c \
					ft_itoa_buf.c
FT_CONV			:=	$(FT_CONV:%.c=ft_conv/%.c)

FT_CTYPE		=	ft_char2num.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_isspace.c \
					ft_num2char.c \
					ft_tolower.c \
					ft_toupper.c \
					ft_isupper.c \
					ft_islower.c
FT_CTYPE		:=	$(FT_CTYPE:%.c=ft_ctype/%.c)

FT_FLOAT		=	ft_float80_b10.c \
					ft_float80_extract.c
FT_FLOAT		:=	$(FT_FLOAT:%.c=ft_float/%.c)

FT_FLOAT_PARAMS	=	ft_float_params_inf.c \
					ft_float_params_nan.c \
					ft_float_params.c
FT_FLOAT_PARAMS	:=	$(FT_FLOAT_PARAMS:%.c=ft_float_params/%.c)

FT_FORMAT		=	ft_format_add_length_mod.c \
					ft_format_has_flag.c \
					ft_format_left_padding.c \
					ft_format_parse.c \
					ft_format_precision.c \
					ft_format_right_padding.c \
					ft_format_set_flag.c \
					ft_format_set_type.c \
					ft_format_sign.c \
					ft_format_zero_padding.c \
					ft_format_prefix.c \
					ft_format_write.c \
					ft_format_lenmod.c \
					ft_format_set_precision.c
FT_FORMAT		:=	$(FT_FORMAT:%.c=ft_format/%.c)

FT_LIST			=	ft_lst_to_array.c \
					ft_lstadd.c \
					ft_lstdel.c \
					ft_lstdelone.c \
					ft_lstfoldleft.c \
					ft_lstiter.c \
					ft_lstlen.c \
					ft_lstmap.c \
					ft_lstnew.c \
					ft_lststrsplit.c
FT_LIST			:=	$(FT_LIST:%.c=ft_list/%.c)

FT_MATH			=	ft_abs.c \
					ft_ipow.c \
					ft_isprime.c \
					ft_isqrt.c \
					ft_log10.c \
					ft_lowersqrt.c \
					ft_submin0.c \
					ft_max.c \
					ft_min.c \
					ft_log.c
FT_MATH			:=	$(FT_MATH:%.c=ft_math/%.c)

FT_STDIO		=	ft_putchar_fd.c \
					ft_putchar.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_putnbr_fd.c \
					ft_putstr_fd.c \
					ft_putstr.c \
					ft_printf.c \
					ft_dprintf.c \
					ft_sprintf.c
FT_STDIO		:=	$(FT_STDIO:%.c=ft_stdio/%.c)

FT_STRING		=	ft_bzero.c \
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
					ft_strnjoin.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strsplit.c \
					ft_strstr.c \
					ft_strsub.c \
					ft_strtrim.c
FT_STRING		:=	$(FT_STRING:%.c=ft_string/%.c)

FT_VPRINTF		=	ft_vsprintf.c \
					ft_vdprintf.c \
					ft_vprintf.c \
					ft_modvprintf.c
FT_VPRINTF		:=	$(FT_VPRINTF:%.c=ft_vprintf/%.c)

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
