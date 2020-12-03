# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2020/12/03 17:21:57 by mrozniec          #+#    #+#             #
#   Updated: 2020/12/03 17:21:57 by mrozniec         ###   ########lyon.fr   #
#                                                                            #
# ************************************************************************** #

NAME = Wolf-3D

TARGET = ft_printf/libftprintf.a -I minilibx -L./minilibx-linux -lmlx -lXext\
		-lX11 -lm
FLAGS = -Wall -Wextra -g -O3

SRC =	srcs/ft_error.c\
		srcs/ft_init.c\
		srcs/ft_init_tex.c\
		srcs/ft_texture.c\
		srcs/init_map.c\
		srcs/ft_utils_map.c\
		srcs/ft_lst.c\
		srcs/ft_draw.c\
		srcs/ft_raycast.c\
		srcs/ft_detec.c\
		srcs/ft_key_event.c\
		srcs/ft_move.c\
		srcs/ft_bmp_save.c\
		srcs/ft_sprite.c\
		srcs/ft_free.c\
		srcs/main.c

HEADER =	header/$(wildcard *.h)

OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@make -C minilibx-linux re
	@make -C ft_printf re
	@cc $(FLAGS) -O3 -o$(NAME) $(OBJ) $(TARGET)

%.o: %.c
	@cc -o $@ -c $< $(FLAGS)

.PHONY: clean fclean re all

clean:
	@/bin/rm $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C ft_printf fclean
	@make -C minilibx-linux clean
	@/bin/rm -rf minilibx-linux/Makefile.gen

re: fclean all
