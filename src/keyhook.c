/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:17:40 by maroy             #+#    #+#             */
/*   Updated: 2023/06/07 15:22:06 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_escape(t_game *game)
{
	int	x;

	x = 0;
	while (game->map[x])
	{
		free(game->map[x]);
		x++;
	}
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_FAILURE);
}

int	ft_key_hook(int keycode, t_game *game)
{
	int	x;

	if (keycode == 0 || keycode == 123)
		ft_move_left(game);
	else if (keycode == 1 || keycode == 125)
		ft_move_down(game);
	else if (keycode == 2 || keycode == 124)
		ft_move_right(game);
	else if (keycode == 13 || keycode == 126)
		ft_move_up(game);
	else if (keycode == 53)
	{
		x = 0;
		while (game->map[x])
		{
			free(game->map[x]);
			x++;
		}
		free(game->map);
		mlx_destroy_window(game->mlx, game->win);
		exit(EXIT_FAILURE);
	}
	return (0);
}
