# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 10:47:39 by pcluchet          #+#    #+#              #
#    Updated: 2018/03/01 20:42:42 by abassibe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRC_DIR = ./srcs/

CC = gcc

EXTRAFLAGS = -Wall -Wextra -Werror

CFLAGS =  -I$(LIBFT_DIR)includes/  -I$(H_DIR) $(EXTRAFLAGS)


	C_FILES = main.c \
	access_tools.c \
	apply_init.c \
	apply_init2.c \
	apply_init_champs.c \
	convert_tool.c \
	exec_engine.c \
	graph_tools.c \
	init.c \
	initers.c \
	more_access_tools.c \
	more_graph_tools.c \
	more_initers.c \
	op.c \
	debug.c \
	init_debug.c \
	manip_tools.c \
	ops_1.c \
	ops_2.c \
	ops_3.c \
	ops_4.c \
	ops_5.c \
	ops_6.c \
	ops_7.c \
	ops_8.c \
	parse_memory.c \
	endgame.c \
	how_use.c

	LIBFT_DIR = ./libft/
	O_FILES = $(C_WITH_PATH:.c=.o)

	H_DIR = ./includes/

	LINKS =  -L $(LIBFT_DIR) -lft -lncurses

C_WITH_PATH = $(addprefix $(SRC_DIR),$(C_FILES))

all : $(NAME)

$(NAME) : libs $(O_FILES)
	$(CC) -o $(NAME) $(O_FILES) $(CFLAGS) $(LINKS)
	make -C asm_folder

clean :
	rm -f $(O_FILES) 
	make -C $(LIBFT_DIR) clean
	make -C asm_folder clean

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)libft.a
	rm -f $(MLX_DIR)libmlx.a
	make -C asm_folder fclean

re : 
	$(MAKE) fclean
	$(MAKE) all

libs:
	make -C $(LIBFT_DIR)

.PHONY: all re clean fclean libs
