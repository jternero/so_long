/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jternero <jternero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:14:23 by jternero          #+#    #+#             */
/*   Updated: 2023/06/28 15:24:50 by jternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_textures(t_game_textures *textures)
{
	textures->wall_tx = mlx_load_png("./textures/wall.png");
	textures->floor_tx = mlx_load_png("./textures/floor.png");
	textures->exit_tx = mlx_load_png("./textures/exit.png");
	textures->player_tx = mlx_load_png("./textures/player.png");
	textures->player_1_tx = mlx_load_png("./textures/player_1.png");
	textures->collectible_tx = mlx_load_png("./textures/collectible.png");
}

void	ft_get_img(t_game_textures *texture, t_game_img *img, mlx_t *mlx)
{
	img->wall = mlx_texture_to_image(mlx, texture->wall_tx);
	img->floor = mlx_texture_to_image(mlx, texture->floor_tx);
	img->exit = mlx_texture_to_image(mlx, texture->exit_tx);
	img->player = mlx_texture_to_image(mlx, texture->player_tx);
	img->player_1 = mlx_texture_to_image(mlx, texture->player_1_tx);
	img->collectible = mlx_texture_to_image(mlx, texture->collectible_tx);
	mlx_delete_texture(texture->wall_tx);
	mlx_delete_texture(texture->floor_tx);
	mlx_delete_texture(texture->exit_tx);
	mlx_delete_texture(texture->player_tx);
	mlx_delete_texture(texture->player_1_tx);
	mlx_delete_texture(texture->collectible_tx);
}

void	ft_put_images(t_game_data *game, t_game_img *img, int i, int j)
{
	mlx_image_to_window(game->mlx, img->floor, j * 64, i * 64);
	if (game->map[i][j] == WALL)
		mlx_image_to_window(game->mlx, img->wall, j * 64, i * 64);
	if (game->map[i][j] == INIT)
	{
		mlx_image_to_window(game->mlx, img->player, j * 64, i * 64);
		mlx_image_to_window(game->mlx, img->player_1, j * 64, i * 64);
		img->player->instances[0].enabled = false;
	}
	if (game->map[i][j] == EXIT)
		mlx_image_to_window(game->mlx, img->exit, j * 64, i * 64);
	if (game->map[i][j] == COLLECTIBLE)
		mlx_image_to_window(game->mlx,
			img->collectible, j * 64, i * 64);
}

void	ft_put_tiles(t_game_data *game, t_game_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			ft_put_images(game, img, i, j);
			j++;
		}
		i++;
	}
}

void	ft_draw_map(t_game_data *game, t_game_textures *textures)
{
	ft_get_textures(textures);
	ft_get_img(textures, &(*game).img, game->mlx);
	ft_put_tiles(game, &(*game).img);
}
