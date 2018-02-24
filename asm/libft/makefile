# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abassibe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 12:45:53 by abassibe          #+#    #+#              #
#    Updated: 2018/02/06 04:03:07 by abassibe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c \
	   ft_atoi_long.c \
	   ft_bzero.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_memcpy.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_strcat.c \
	   ft_strchr.c \
	   ft_strcmp.c \
	   ft_strcpy.c \
	   ft_strdup.c \
	   ft_strndup.c \
	   ft_strlcat.c \
	   ft_strlen.c \
	   ft_strncat.c \
	   ft_strncmp.c \
	   ft_strncpy.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putendl.c \
	   ft_putnbr.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_strclr.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strequ.c \
	   ft_strnequ.c \
	   ft_strsub.c \
	   ft_strsubf.c \
	   ft_strjoin.c \
	   ft_strjoinf.c \
	   ft_strjoinff.c \
	   ft_strjoinfn.c \
	   ft_strtrim.c \
	   ft_strsplit.c \
	   ft_strsplit2.c \
	   ft_itoa.c \
	   ft_itoa_long.c \
	   ft_itoa_ulong.c \
	   ft_itoa_base.c \
	   ft_itoa_base_maj.c \
	   ft_itoa_base_maj_unsigned.c \
	   ft_itoa_base_unsigned.c \
	   ft_lstnew.c \
	   ft_lstdelone.c \
	   ft_lstdel.c \
	   ft_lstadd.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_count_if.c \
	   ft_foreach.c \
	   ft_range.c \
	   ft_recursive_factorial.c \
	   ft_sqrt.c \
	   ft_swap.c \
	   ft_replace.c \
	   ft_count_char.c \
	   ft_isspace.c \
	   get_next_line.c \
	   chk_color.c \
	   concaten_result.c \
	   conv_bin.c \
	   conv_char.c \
	   conv_empty.c \
	   conv_hexa.c \
	   conv_hexa_x.c \
	   conv_n.c \
	   conv_octal.c \
	   conv_octal_next.c \
	   conv_percent.c \
	   conv_string.c \
	   conv_uint.c \
	   convert_int.c \
	   convert_int_next.c \
	   core.c \
	   field_int.c \
	   field_int_next.c \
	   field_string.c \
	   ft_printf.c \
	   preci_int.c \
	   preci_string.c \
	   recup_args_hexa.c \
	   recup_format.c \
	   set_lst.c \
	   spc_flags.c \
	   verif_format.c \
	   ft_btoi.c \
	   ft_itoa_base_unicode.c \
	   ft_putnstr.c \
	   ft_power.c \
	   ft_abs.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

DIR_OBJ = objs/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(addprefix objs/, $(OBJS))
	@ar rc $(NAME) $(addprefix objs/, $(OBJS))
	@ranlib $(NAME)

$(DIR_OBJ)%.o: ./%.c
	@mkdir -p objs
	@gcc $(FLAGS) -c $< -o $@ -I libft.h

clean:
	@rm -rf objs

fclean: clean
	@rm -rf $(NAME)

re: fclean
	@make
