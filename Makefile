# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/14 12:45:05 by mrozniec     #+#   ##    ##    #+#        #
#    Updated: 2020/01/07 13:02:55 by mrozniec    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #
NAME = Wolf-3D

ifeq ($(shell uname), Linux)
TARGET = ft_printf/linux/libftprintf.a
else
TARGET = ft_printf/mac/libftprintf.a
endif

SRC =	srcs/ft_error.c\
		srcs/ft_texture.c\
		srcs/init_map.c\
		libft/ft_atoi.c\
        libft/ft_atof.c\
        libft/ft_bzero.c\
        libft/ft_calloc.c\
        libft/ft_isalnum.c\
        libft/ft_isalpha.c\
        libft/ft_isascii.c\
        libft/ft_isdigit.c\
        libft/ft_isprint.c\
        libft/ft_itoa.c\
        libft/ft_llitoa.c\
        libft/ft_itoa_base.c\
        libft/ft_hitoa_base.c\
        libft/ft_hhitoa_base.c\
        libft/ft_litoa_base.c\
        libft/ft_llitoa_base.c\
        libft/ft_memccpy.c\
        libft/ft_memchr.c\
        libft/ft_memcmp.c\
        libft/ft_memcpy.c\
        libft/ft_memmove.c\
        libft/ft_memset.c\
        libft/ft_putchar_fd.c\
		libft/ft_putendl_fd.c\
        libft/ft_putnbr_fd.c\
        libft/ft_putstr_fd.c\
        libft/ft_split.c\
        libft/ft_strchr.c\
        libft/ft_strdup.c\
        libft/ft_strjoin.c\
        libft/ft_strjoinmod.c\
        libft/ft_strjoinmodnbits.c\
        libft/ft_strlcat.c\
        libft/ft_strlcpy.c\
        libft/ft_strlen.c\
        libft/ft_strmapi.c\
        libft/ft_strncmp.c\
        libft/ft_strnstr.c\
        libft/ft_strrchr.c\
        libft/ft_strtrim.c\
        libft/ft_substr.c\
        libft/ft_tolower.c\
        libft/ft_toupper.c\
		libft/ft_lstadd_back_bonus.c\
        libft/ft_lstdelone_bonus.c\
        libft/ft_lstmap_bonus.c\
        libft/ft_lstadd_front_bonus.c\
        libft/ft_lstiter_bonus.c\
        libft/ft_lstnew_bonus.c\
        libft/ft_lstclear_bonus.c\
        libft/ft_lstlast_bonus.c\
        libft/ft_lstsize_bonus.c\
        libft/get_next_line.c\
        main-test.c

HEADER =	header/$(wildcard *.h)

OBJ =	$(SRC:.c=.o)

FLAGS = -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@cc $(FLAGS) $(OBJ) $(TARGET)

%.o: %.c
	@cc -o $@ -c $< $(FLAGS)

.PHONY: clean fclean re all

clean:
	@/bin/rm $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all
