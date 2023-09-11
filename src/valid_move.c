/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jternero <jternero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:21:14 by jternero          #+#    #+#             */
/*   Updated: 2023/06/28 15:24:43 by jternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_game_data *game)
{
	if (game->map[(*game).img.player->instances[0].y / 64 - 1]
		[(*game).img.player->instances[0].x / 64] != WALL)
	{
		usleep(150000);
		(*game).img.player->instances[0].y -= MOVE;
		(*game).img.player_1->instances[0].y -= MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	ft_move_down(t_game_data *game)
{
	if (game->map[(*game).img.player->instances[0].y / 64 + 1]
		[(*game).img.player->instances[0].x / 64] != WALL)
	{
		usleep(150000);
		(*game).img.player->instances[0].y += MOVE;
		(*game).img.player_1->instances[0].y += MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	ft_move_left(t_game_data *game)
{
	if (game->map[(*game).img.player->instances[0].y / 64]
		[(*game).img.player->instances[0].x / 64 - 1] != WALL)
	{
		usleep(150000);
		(*game).img.player_1->instances[0].enabled = false;
		(*game).img.player->instances[0].enabled = true;
		(*game).img.player->instances[0].x -= MOVE;
		(*game).img.player_1->instances[0].x -= MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	ft_move_right(t_game_data *game)
{
	if (game->map[(*game).img.player->instances[0].y / 64]
		[(*game).img.player->instances[0].x / 64 + 1] != WALL)
	{
		usleep(150000);
		(*game).img.player->instances[0].enabled = false;
		(*game).img.player_1->instances[0].enabled = true;
		(*game).img.player->instances[0].x += MOVE;
		(*game).img.player_1->instances[0].x += MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}
