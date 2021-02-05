# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/30 18:49:14 by aeddaqqa          #+#    #+#              #
#    Updated: 2019/07/23 16:44:39 by cnaour           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strdel.c ft_strnew.c ft_strjoin.c ft_strlen.c ft_putstr.c
INC = libft.h
CFLAG = -Wall -Wextra -Werror

OBJ = ft_strdel.o ft_strnew.o ft_strjoin.o ft_strlen.o ft_putstr.o

all : $(NAME)

$(NAME) :
	@gcc $(CFLAG) -c $(SRC) -I $(INC) 
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
clean :
	@rm -rf $(OBJ)
fclean : clean
	@rm -rf $(NAME)
re : fclean all
