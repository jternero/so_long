/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jternero <jternero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:56:16 by jternero          #+#    #+#             */
/*   Updated: 2023/06/28 15:24:52 by jternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map(char **map, t_game_data *game)
{
	if (ft_is_valid(map) == FALSE)
	{
		ft_printf("Error! The map is not a rectangle.\n");
		return (FALSE);
	}
	else if (ft_check_wall(map) == FALSE)
	{
		ft_printf("Error! The map is not closed by walls.\n");
		return (FALSE);
	}
	else if (ft_is_tile(map) == FALSE)
	{
		ft_printf("Error! The map have a wrong tile.\n");
		return (FALSE);
	}
	else if (ft_have_exit(game) == FALSE)
	{
		ft_printf("Error! The map do not have ONE exit ");
		ft_printf("or ONE init position or at least one collectable.\n");
		return (FALSE);
	}
	else
		return (TRUE);
}
