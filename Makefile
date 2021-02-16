# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/06 13:42:04 by ael-kass          #+#    #+#              #
#    Updated: 2020/12/31 09:28:39 by ael-kass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = -Wall -Wextra -Werror -I /usr/share/man/man3 -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -g

NAME = cub3D
LIB = ./libft/libft.a

SRC = drawing/castand3d.c\
		drawing/update_for_new_drawing.c\
		drawing/raycasting.c\
		drawing/texture.c\
		drawing/ft_sprite.c\
		drawing/bmp.c\
		get_next_line/get_next_line.c\
		parsing/putonvar.c\
		parsing/stock_utils.c\
		parsing/map.c\
		parsing/map1.c\
		parsing/parsing_help.c\
		parsing/print_errors.c\
		parsing/stock_utils_help.c\
		main.c


all: $(NAME)

$(NAME): $(LIB) $(SRC)
	@gcc $(CC) $(SRC) $(LIB) -o $(NAME)

$(LIB):
	@make -C ./libft

clean :
	@rm -rf $(NAME)
	@make -C ./libft fclean

fclean : clean
	@rm -rf $(NAME)

re : fclean all
