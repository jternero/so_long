# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jternero <jternero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 15:12:31 by jternero          #+#    #+#              #
#    Updated: 2023/06/21 15:19:04 by jternero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MLX42 = MLX42/libmlx42.a -I include -lglfw -L "/Users/jternero/.brew/opt/glfw/lib/"

OBJ = $(SRC:.c=.o)

LIBFT = Libft/libft.a

GNL = Getnextline/get_next_line.c Getnextline/get_next_line_utils.c

SRC = $(GNL) main.c read_map.c check_map_utils.c check_map.c \
		game_main.c draw_map.c valid_move.c game_loop.c valid_way.c
		
PRINTF = ft_printf/libftprintf.a

CC = gcc

CCFLAGS = -Wall -Wextra -Werror	

ifdef LEAKS
	CC += -fsanitize=address

endif

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C Libft -s 
	@make -C ft_printf -s
	@make -s -C MLX42
	$(CC) $(CCFLAGS) $(SRC) $(LIBFT) $(PRINTF) $(MLX42) -o $(NAME) -g

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $< -g

clean: 
	@make clean -C Libft -s
	@make clean -C ft_printf -s
	@make clean -C MLX42 -s
	$(CC) $(CCFLAGS) $(SRC) $(LIBFT) $(PRINTF) $(MLX42) -o $(NAME) -g

fclean:
	@make fclean -C Libft -s
	@make fclean -C ft_printf -s
	@make fclean -s -C MLX42
	rm -rf *.o Getnextline/*.o $(NAME)
	
re: fclean all

.PHONY: all clean fclean re