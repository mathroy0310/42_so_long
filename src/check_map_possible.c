/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_possible.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:35:01 by maroy             #+#    #+#             */
/*   Updated: 2023/04/05 17:28:41 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

static void	floodfill(t_game game_backup, int y, int x)
{
	if (game_backup.map[y][x] == '1')
	{
		ft_printf("DEBUG: Floodfill test : <%c> \n", game_backup.map[y][x]);
		game_backup.map[y][x] = 'F';
		floodfill(game_backup, y++, x);
		floodfill(game_backup, y--, x);
		floodfill(game_backup, y, x++);
		floodfill(game_backup, y, x--);
		return ;
	}
	return ;
}

void	check_is_map_possibe(t_game *game)
{
	t_game	game_backup;
	int		x;
	int		y;
	char	c;

	x = 0;
	y = 0;
	game_backup = *game;
	c = game_backup.map[y][x];
	floodfill(game_backup, y, x);
}
