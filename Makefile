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

CC = -Wall -Wextra -Werror -I /usr/share/man/man3 -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -fsanitize=address -g

NAME = cub3D
LIB = ./libft/libft.a

SRC = drawing/map.c\
		drawing/castand3d.c\
		drawing/update_for_new_drawing.c\
		drawing/raycasting.c\
		drawing/texture.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\
		errors/putonvar.c\
		main.c


all: $(NAME)

$(NAME): $(LIB)
	@gcc $(CC) $(SRC) $(LIB) -o $(NAME)

$(LIB):
	@make -C ./libft

clean :
	@rm -rf $(NAME)
	@make -C ./libft fclean

fclean : clean
	@rm -rf $(NAME)

re : fclean all
