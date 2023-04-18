/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_possible.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:35:01 by maroy             #+#    #+#             */
/*   Updated: 2023/04/18 15:05:31 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"
#include <unistd.h>

static int	ft_c_count(t_game *game)
{
	int	x;
	int	y;
	int	n_row;
	int	l_colum;
	int	c_count;

	l_colum = ft_strlen(game->map[0]);
	c_count = 0;
	y = 0;
	n_row = ft_get_height(game->map);
	while (y < n_row)
	{
		x = 0;
		while (x < l_colum)
		{
			if (game->map[y][x] == 'C')
			{
				c_count++;
			}
			x++;
		}
		y++;
	}
	return (c_count);
}

static void	floodfill(t_game *game_backup, int y, int x, int *nb_c)
{
	if (game_backup->backup_map[y][x] == '1'
		|| game_backup->backup_map[y][x] == 'f')
		return ;
	if (game_backup->backup_map[y][x] == 'C')
		*nb_c -= 1;
	if (game_backup->backup_map[y][x] == 'E')
		game_backup->nbexit = 1;
	game_backup->backup_map[y][x] = 'f';
	floodfill(game_backup, y - 1, x, nb_c);
	floodfill(game_backup, y + 1, x, nb_c);
	floodfill(game_backup, y, x - 1, nb_c);
	floodfill(game_backup, y, x + 1, nb_c);
}

void	check_is_map_possibe(t_game *game)
{
	int	nb_c;

	nb_c = 0;
	nb_c = ft_c_count(game);
	floodfill(game, game->player_pos.y, game->player_pos.x, &nb_c);
	if (nb_c != 0)
		ft_error(game, "\033[1;31m ERROR 🛑 : Map is Impossible.	\033[0m");
}
