/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jternero <jternero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:59:06 by jternero          #+#    #+#             */
/*   Updated: 2023/06/21 20:13:02 by jternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_rectangle(char **map)
{
	size_t	len;
	int		i;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (FALSE);
		else
			i++;
	}
	return (i);
}

int	ft_check_wall(char **map)
{
	size_t	i;
	int		j;
	int		height;

	height = 0;
	while (map[height])
		height++;
	i = 0;
	while (i < ft_strlen(map[0]))
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (FALSE);
		else
			i++;
	}
	j = 1;
	while (j < (height - 1))
	{
		if (map[j][0] != '1' || map[j][ft_strlen(map[0]) - 1] != '1')
			return (FALSE);
		else
			j++;
	}
	return (TRUE);
}

int	ft_is_tile(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] != '1') && (map[i][j] != '0') && (map[i][j] != 'C')
				&& (map[i][j] != 'E') && (map[i][j] != 'P'))
				return (FALSE);
			else
				j++;
		}
		i++;
	}
	return (TRUE);
}

int	ft_have_exit(t_game_data *game)
{
	int	i;
	int	j;

	game->exit = 0;
	game->collectible = 0;
	game->player = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				game->exit++;
			if (game->map[i][j] == 'C')
				game->collectible++;
			if (game->map[i][j] == 'P')
				game->player++;
			j++;
		}
		i++;
	}
}
