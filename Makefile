# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2020/02/27 17:45:12 by mrozniec          #+#    #+#             #
#   Updated: 2020/03/06 14:48:25 by fenrir           ###   ########lyon.fr   #
#                                                                            #
# ************************************************************************** #

NAME = Wolf-3D

ifeq ($(shell uname), Linux)
TARGET = ft_printf/linux/libftprintf.a -I minilibx -L minilibx -lmlx -lXext\
		-lX11 -lm
FLAGS = -Wall -Wextra -g -O3
else
TARGET = ft_printf/mac/libftprintf.a -I minilibx -L minilibx -lmlx
FLAGS = -Wall -Wextra
endif

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
	@cc $(FLAGS) -O3 -o$(NAME) $(OBJ) $(TARGET)

%.o: %.c
	@cc -o $@ -c $< $(FLAGS)

.PHONY: clean fclean re all

clean:
	@/bin/rm $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all
