# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/29 14:14:29 by aeddaqqa          #+#    #+#              #
#    Updated: 2019/07/20 04:13:51 by aeddaqqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = src/check_file.c src/ft_place.c src/ft_solve.c  src/ft_strsplit_i.c src/ft_free_tab.c src/ft_stock.c src/main.c libft/libft.a

INC = includes/fillit.h

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	@cd libft && make re
	@gcc $(FLAG) -o $(NAME) $(SRC) -I $(INC)
clean :
	@cd libft && make clean
fclean : clean
		@cd libft && make fclean
		@rm -rf $(NAME)
re : fclean all
