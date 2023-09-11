/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jternero <jternero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:48:20 by jternero          #+#    #+#             */
/*   Updated: 2023/06/30 13:23:09 by jternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../include/Libft/libft.h"
# include "../include/ft_printf/ft_printf.h"
# include "../include/GetnextLine/get_next_line.h"
# include "../include/MLX42/include/MLX42/MLX42.h"
# include "fcntl.h"




# define MOVE 64
# define DELAY 500


//typedef 
typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}t_bool;

typedef struct s_game_img
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t	*player_1;
	mlx_image_t	*exit;
	mlx_image_t	*collectible;
	mlx_image_t	*intro;
}t_game_img;

typedef struct s_player
{
	int	x;
	int	y;
}t_player;

typedef enum e_tiles
{
	VOID = '0',
	WALL = '1',
	INIT = 'P',
	EXIT = 'E',
	COLLECTIBLE = 'C',
	VISITED = 'V'
}t_tiles;

typedef struct s_game_data
{
	int					init;
	int					collectible;
	int					exit;
	int					floor;
	char				**map;
	int					heigth;
	int					width;
	int					collect_count;
	int					seta_count;
	int					items;
	int					move_count;
	char				**dup_map;
	mlx_t				*mlx;
	struct s_player		player;
	struct s_game_img	img;

}t_game_data;

typedef struct s_game_textures
{
	mlx_texture_t	*wall_tx;
	mlx_texture_t	*floor_tx;	
	mlx_texture_t	*player_tx;
	mlx_texture_t	*player_1_tx;
	mlx_texture_t	*exit_tx;
	mlx_texture_t	*collectible_tx;
}t_game_textures;

//functions  
char	**ft_read_map(char *file);
int		ft_is_valid(char **map);
int		ft_check_wall(char **map);
int		ft_is_tile(char **map);
int		ft_have_exit(t_game_data *game);
int		ft_check_map(char **map, t_game_data *game);
int		ft_game_main(t_game_data *game);
void	ft_draw_map(t_game_data *game, t_game_textures *textures);
void	ft_move_up(t_game_data *game);
void	ft_move_down(t_game_data *game);
void	ft_move_right(t_game_data *game);
void	ft_move_left(t_game_data *game);
void	ft_gameplay(void *param);
void	ft_is_collect(t_game_data *game);
void	ft_delete_collect(t_game_data *game);
int		ft_count_collectables(t_game_data *game);
void	ft_map_data(t_game_data *game, char **map);
int		ft_path(t_game_data *game, char *file);
void	ft_free(char **map);
#endif