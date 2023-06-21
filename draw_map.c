/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jternero <jternero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:14:23 by jternero          #+#    #+#             */
/*   Updated: 2023/06/21 20:34:42 by jternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_textures(t_game_textures *textures)
{
	texture->wall_tx = mlx_load_png(".assets/wall.png");
	texture->floor_tx = mlx_load_png(".assets/floor.png");
	texture->exit_tx = mlx_load_png(".assets/exit.png");
	texture->player_tx = mlx_load_png(".assets/player.png");
	texture->player_1_tx = mlx_load_png(".assets/player_1.png");
	texture->collect_tx = mlx_load_png(".assets/collect.png");
}

void	ft_get_img(t_game_textures *texture, t_game_img *img, mlx_t *mlx)
{
	img->wall_img = mlx_texture_to_image(mlx, texture->wall_tx);
	img->floor_img = mlx_texture_to_image(mlx, texture->floor_tx);
	img->exit_img = mlx_texture_to_image(mlx, texture->exit_tx);
	img->player_img = mlx_texture_to_image(mlx, texture->player_tx);
	img->player_1_img = mlx_texture_to_image(mlx, texture->player_1_tx);
	img->collect_img = mlx_texture_to_image(mlx, texture->collect_tx);
	mlx_delete_texture(texture->wall_tx);
	mlx_delete_texture(texture->floor_tx);
	mlx_delete_texture(texture->exit_tx);
	mlx_delete_texture(texture->player_tx);
	mlx_delete_texture(texture->player_1_tx);
	mlx_delete_texture(texture->collect_tx);
}

void	ft_put_images(t_game_game *game, t_game_img *img, int i, int j)
{
	mlx_image_to_window(game->mlx, img->floor_img, i * 64, j * 64);
	if (gmae->map[i][j] == WALL)
		mlx_image_to_window(game->mlx, img->wall_img, i * 64, j * 64);
	if (game->map[i][j] == EXIT)
		mlx_image_to_window(game->mlx, img->exit_img, i * 64, j * 64);
	if (game->map[i][j] == COLLECTIBLE)
		mlx_image_to_window(game->mlx, img->collect_img, i * 64, j * 64);
	if (game->map[i][j] == INIT)
	{
		if (game->player->x == i && game->player->y == j)
			mlx_image_to_window(game->mlx, img->player_img, i * 64, j * 64);
		else
			mlx_image_to_window(game->mlx, img->player_1_img, i * 64, j * 64);
	}
}

void	ft_put_tile(t_game_data *game, t_game_img *img)
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
	t_game_img	*img;

	img = malloc(sizeof(t_game_img));
	ft_get_img(texture, img, game->mlx);
	ft_put_tile(game, img);
	ft_get_textures(textures);
	free(img);
}
