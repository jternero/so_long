/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jternero <jternero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:27:34 by jternero          #+#    #+#             */
/*   Updated: 2023/06/21 18:57:05 by jternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_argv(char *argv)
{
	int	i;

	i = ft_strlen(argv) -1;
	if (argv[i] == 'r' && argv[i -1] == 'e'
		&& argv[i - 2] == 'b'
		&& argv[i - 3] == '.')
		return (TRUE);
	ft_printf("ERROR, INVALID MAP!!\n");
	return (FALSE);
}

void	ft_free(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	ft_l(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_game_data	game;

	if (argc == 2)
	{
		if (ft_argv(argv[1]) == FALSE)
			return (-1);
		game.map = ft_read_map(argv[1]);
		if (game.map == NULL)
		{
			free(game.map);
			return (ft_printf("ERROR, INVALID MAP!!\n"));
		}
		if (ft_check_map(game.map, &game) == FALSE
			|| ft_path(&game, argv[1]) == FALSE)
		{
			ft_free(game.map);
			return (-1);
		}
		ft_path(&game, argv[1]);
		ft_game_main(&game);
		ft_free(game.map);
	}
	else
		return (ft_printf("ERROR, INVALID ARGUMENTS!!\n"));
	return (0);
}
