/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:32:13 by maroy             #+#    #+#             */
/*   Updated: 2023/04/06 11:40:43 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int	ft_collectible(t_game *game)
{
	int	map_x;
	int	map_y;

	map_x = 0;
	while (game->wsize.x > map_x)
	{
		map_y = 0;
		while (game->wsize.y > map_y)
		{
			if (game->map[map_y][map_x] == 'C')
				game->nbcollect++;
			map_y++;
		}
		map_x++;
	}
	return (game->nbcollect);
}

void	ft_you_win(t_game *game)
{
	int	x;

	ft_printf("\033[32m#################################\n");
	ft_printf("#	FILICITAITON 🎊		#\n");
	ft_printf("#################################\033[0m\n");
	x = 0;
	while (game->map[x])
	{
		free(game->map[x]);
		x++;
	}
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}
