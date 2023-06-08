/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:04:10 by maroy             #+#    #+#             */
/*   Updated: 2023/06/07 15:11:00 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_draw_wall_corners(t_game *game, t_vect2i pos)
{
	if (pos.x == 0 && pos.y == 0)
		game->img = game->sprite.wall.wall_no;
	else if (pos.x == 0 && pos.y == game->wsize.y - 1)
		game->img = game->sprite.wall.wall_so;
	else if (pos.x == game->wsize.x - 1 && pos.y == 0)
		game->img = game->sprite.wall.wall_ne;
	else if (pos.x == game->wsize.x - 1 && pos.y == game->wsize.y - 1)
		game->img = game->sprite.wall.wall_se;
	else
		return (0);
	return (1);
}

int	ft_draw_wall_sides(t_game *game, t_vect2i pos)
{
	if (pos.x == 0)
		game->img = game->sprite.wall.wall_o;
	else if (pos.x == game->wsize.x - 1)
		game->img = game->sprite.wall.wall_e;
	else if (pos.y == 0)
		game->img = game->sprite.wall.wall_n;
	else if (pos.y == game->wsize.y - 1)
		game->img = game->sprite.wall.wall_s;
	else
		return (0);
	return (1);
}
