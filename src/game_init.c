/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:31:40 by maroy             #+#    #+#             */
/*   Updated: 2022/12/08 22:43:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

t_game **ft_map_init(int argc, char argv, t_game *game)
{
	char	**map;
	t_game	**tilemap;

	map = ft_read_map(argv[1]);
	if (!map)
		return (NULL);
}

int	ft_start_game(t_game *game, int argc char **argv)
{
	game->tilemap = map_init(argc, argv, game)
	if (game->tilemap == NULL)
		return (0);
	else
		return (1);
}
