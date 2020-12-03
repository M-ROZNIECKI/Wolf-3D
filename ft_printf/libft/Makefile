# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2020/12/03 17:44:23 by mrozniec          #+#    #+#             #
#   Updated: 2020/12/03 17:44:23 by mrozniec         ###   ########lyon.fr   #
#                                                                            #
# ************************************************************************** #

NAME = libft.a

SRC =	ft_atoi.c\
		ft_atof.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_llitoa.c\
		ft_itoa_base.c\
		ft_hitoa_base.c\
		ft_hhitoa_base.c\
		ft_litoa_base.c\
		ft_llitoa_base.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strjoinmod.c\
		ft_strjoinmodnbits.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c\
		get_next_line.c\
		ft_lstadd_back_bonus.c\
		ft_lstdelone_bonus.c\
		ft_lstmap_bonus.c\
		ft_lstadd_front_bonus.c\
		ft_lstiter_bonus.c\
		ft_lstnew_bonus.c\
		ft_lstclear_bonus.c\
		ft_lstlast_bonus.c\
		ft_lstsize_bonus.c

HEADER = libft.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@ar rc $(NAME) $(OBJ)

.PHONY: clean fclean re all

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
