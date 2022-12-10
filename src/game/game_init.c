/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:31:40 by maroy             #+#    #+#             */
/*   Updated: 2022/12/09 18:37:36 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/so_long.h"

t_tile	**ft_map_init(int argc, char **argv, t_game *game)
{
	char	**map;
	t_tile **tilemap;

	(void)game;
	
	if (!ft_file_checker(argc, argv[1]))
			return(NULL);
	map = ft_read_map(argv[1]);
	if (!map)
		return (NULL);
	//generate map dans le tilemap en tile et return tilemap
	//mais map checker avant ?
	tilemap = NULL;
	return (tilemap);
}

int	ft_start_game(t_game *game, int argc, char **argv)
{
	
	game->tilemap = ft_map_init(argc, argv, game);
	if (game->tilemap == NULL)
		return (0);
	else
		return (1);
}
