/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jternero <jternero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:59:38 by jternero          #+#    #+#             */
/*   Updated: 2023/06/30 11:54:02 by jternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_data(t_game_data *game, char **map)
{
	int	i;

	game->width = ft_strlen(map[0]);
	i = 0;
	while (map[i])
		i++;
	game->heigth = i;
}

int	ft_count_collectables(t_game_data *game)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == COLLECTIBLE)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_set_floor_z(t_game_data *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			mlx_set_instance_depth(&game->img.floor->instances[k], 0);
			k++;
			j++;
		}
		i++;
	}
}

void	ft_set_exit_z(t_game_data *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] == EXIT)
		{
			mlx_set_instance_depth(&(*game).img.exit->instances[k], 0);
			k++;
			j++;
		}
		i++;
	}
}

int	ft_game_main(t_game_data *game)
{
	t_game_textures	textures;

	game->collect_count = 0;
	game->move_count = 0;
	game->seta_count = 0;
	ft_map_data(game, game->map);
	game->mlx = mlx_init(game->width * 64, game->heigth * 64,
			"jternero's so_long", false);
	if (!game->mlx)
		exit(EXIT_FAILURE);
	game->items = ft_count_collectables(game);
	ft_draw_map(game, &textures);
	ft_set_exit_z(game);
	ft_set_floor_z(game);
	mlx_loop_hook(game->mlx, &ft_gameplay, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}
