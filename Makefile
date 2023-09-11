# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jternero <jternero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 15:39:29 by jternero          #+#    #+#              #
#    Updated: 2023/06/29 23:44:31 by jternero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

MLX42 = include/MLX42/libmlx42.a -I include -lglfw -L "/Users/jternero/.brew/opt/glfw/lib/"

OBJ = $(SRC:.c=.o)

LIBFT = include/Libft/libft.a

GNL = include/GetnextLine/get_next_line.c include/GetnextLine/get_next_line_utils.c

SRC = $(GNL) src/main.c src/read_map.c src/check_map_utils.c src/check_map.c \
		src/game_main.c src/draw_map.c src/valid_move.c src/game_loop.c src/valid_way.c

PRINTF = include/ft_printf/libftprintf.a

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

ifdef LEAKS
	CC += -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJ)
	@make -C include/Libft -s 
	@make -C include/ft_printf -s
	@make -s -C include/MLX42
	$(CC) $(CCFLAGS) $(SRC) $(LIBFT) $(PRINTF) $(MLX42) -o $(NAME) -g

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $< -g

clean:
	@make clean -C include/Libft -s
	@make clean -C include/ft_printf -s
	@make clean -C include/MLX42 -s
	rm -rf src/*.o include/GetnextLine/*.o $(NAME)

fclean:
	@make fclean -C include/Libft -s
	@make fclean -C include/ft_printf -s
	@make fclean -s -C include/MLX42
	rm -rf src/*.o include/GetnextLine/*.o *.o $(NAME)

re: fclean all

.PHONY: all clean fclean re
