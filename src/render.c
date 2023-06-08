/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:56:56 by maroy             #+#    #+#             */
/*   Updated: 2023/06/07 14:14:05 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_render_walls(t_vect2i pos, t_game *game, int *b)
{
	if (ft_draw_wall_corners(game, pos))
		return ;
	else if (ft_draw_wall_sides(game, pos))
		return ;
	if (*b == 1)
		game->img = game->sprite.wall.wall1;
	else if (*b == 2)
		game->img = game->sprite.wall.wall2;
	else if (*b == 3)
		game->img = game->sprite.wall.wall3;
	else if (*b == 4)
		game->img = game->sprite.wall.wall1;
	else if (*b == 5)
		game->img = game->sprite.wall.wall2;
	else
	{
		*b = 0;
		game->img = game->sprite.wall.wall3;
	}
}

static void	ft_render_exit(t_game *game)
{
	if (game->nbcollect != 0)
		game->img = game->sprite.exit;
	if (game->nbcollect == 0)
		game->img = game->sprite.exitopen;
}

void	ft_put_image(t_game *game, t_vect2i pos, int *b)
{	
	if (game->map[pos.y][pos.x] == '0')
		game->img = game->sprite.empty;
	else if (game->map[pos.y][pos.x] == '1')
		ft_render_walls(pos, game, b);
	else if (game->map[pos.y][pos.x] == 'E')
		ft_render_exit(game);
	else if (game->map[pos.y][pos.x] == 'C')
		game->img = game->sprite.collectible;
	else if (game->map[pos.y][pos.x] == 'M')
		game->img = game->sprite.ennemy;
	if (pos.y == game->player_pos.y && pos.x == game->player_pos.x)
		game->img = game->sprite.player;
}

void	ft_render(t_game *game)
{
	t_vect2i	pos;
	int			b;

	b = 1;
	pos.x = 0;
	while (game->wsize.x > pos.x)
	{
		pos.y = 0;
		while (game->wsize.y > pos.y)
		{
			ft_put_image(game, pos, &b);
			mlx_put_image_to_window(game->mlx, game->win, game->img, pos.x
				* SPRITESIZE, pos.y * SPRITESIZE);
			pos.y++;
		b++;
		}
		pos.x++;
	}
}
