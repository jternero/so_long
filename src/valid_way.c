/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jternero <jternero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:29:13 by jternero          #+#    #+#             */
/*   Updated: 2023/06/30 13:11:54 by jternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	ft_flood_fill(t_game_data *game, int y, int x)
{
	if (!(x < 1 || y < 1 || x >= game->width || y > game->heigth
			|| game->dup_map[y][x] == '1' || game->dup_map[y][x] == 'X'))
	{
		game->dup_map[y][x] = 'X';
		ft_flood_fill(game, y + 1, x);
		ft_flood_fill(game, y - 1, x);
		ft_flood_fill(game, y, x + 1);
		ft_flood_fill(game, y, x - 1);
	}
}

void	ft_print_dupmap(t_game_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->dup_map[i])
	{
		j = 0;
		while (game->dup_map[i][j])
		{
			printf("%c", game->dup_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	*ft_start(char **map)
{
	int	x;
	int	y;
	int	*pos;

	pos = (int *)malloc(sizeof(int) * 2);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == INIT)
			{
				pos[0] = y;
				pos[1] = x;
			}
			x++;
		}
		y++;
	}
	return (pos);
}

int	ft_check_path(char **map)
{
	int	i;
	int	o;

	i = 0;
	while (map[i])
	{
		o = 0;
		while (map[i][o])
		{
			if (!(map[i][o] == WALL || map[i][o] == VOID
				|| map[i][o] == 'X'))
				return (FALSE);
			o++;
		}
		i++;
	}
	return (TRUE);
}

int	ft_path(t_game_data *game, char *file)
{
	int	*pos;

	game->dup_map = ft_read_map(file);
	pos = ft_start(game->dup_map);
	ft_flood_fill(game, pos[0], pos[1]);
	if (ft_check_path(game->dup_map) == FALSE)
	{
		ft_printf("Error! There is not a valid path\n");
		ft_free(game->dup_map);
		return (FALSE);
	}
	ft_free(game->dup_map);
	free(pos);
	return (TRUE);
}
