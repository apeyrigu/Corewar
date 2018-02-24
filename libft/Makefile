# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 10:47:39 by pcluchet          #+#    #+#              #
#    Updated: 2017/03/28 17:08:28 by pcluchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR = ./

CC = gcc

CFLAGS =  -I$(H_DIR) -Wall -Wextra -Werror

C_FILES = ft_atoi.c \
ft_bzero.c \
get_next_line.c \
ft_count_c.c \
ft_digits.c \
ft_digits_un.c \
ft_is_in.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isupper.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_iwstrlen.c \
ft_lstadd.c \
ft_lstdel.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstmap.c \
ft_lstnew.c \
ft_memalloc.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memdel.c \
ft_memmove.c \
ft_memset.c \
ft_next_c.c \
ft_not_in_number.c \
ft_print_color.c \
ft_print_r_int.c \
ft_print_r_str.c \
ft_printf.c \
ft_putchar.c \
ft_putchar_fd.c \
ft_putendl.c \
ft_putendl_fd.c \
ft_putnbr.c \
ft_putnbr_fd.c \
ft_putstr.c \
ft_putstr_fd.c \
ft_putwchar.c \
ft_putwstr.c \
ft_sort_tab_str.c \
ft_strcat.c \
ft_strchr.c \
ft_strclr.c \
ft_strcmp.c \
ft_strcpy.c \
ft_strdel.c \
ft_strdup.c \
ft_strequ.c \
ft_string_color.c \
ft_striter.c \
ft_striteri.c \
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
ft_strtrim.c \
ft_to_hx.c \
ft_tolower.c \
ft_toupper.c \
ft_wlen.c \
ft_wstrlen.c \

C_PRINTF_FILES = c_handler.c \
d_handler.c \
fmt_management.c \
mdf_management.c \
o_handler.c \
p_handler.c \
percent_handler.c \
s_handler.c \
u_handler.c \
inv_handler.c \
utils.c \
x_handler.c \

C_PRINTF_DIR = ./printf/

O_FILES = $(C_WITH_PATH:.c=.o)

H_DIR = ./includes/

C_WITH_PATH = $(addprefix $(SRC_DIR),$(C_FILES))

C_PRINTF_PATH = $(addprefix $(C_PRINTF_DIR),$(C_PRINTF_FILES))

O_PRINTF_FILES = $(C_PRINTF_PATH:.c=.o)

all : $(NAME)

$(NAME) : $(O_FILES) $(O_PRINTF_FILES)
	ar rcs $(NAME) $(O_FILES) $(O_PRINTF_FILES)

clean :
	rm -f $(O_FILES) $(O_PRINTF_FILES)

fclean : clean
	rm -f $(NAME)

re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all re clean fclean
