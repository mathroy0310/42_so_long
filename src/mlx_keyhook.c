/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keyhook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:55:30 by maroy             #+#    #+#             */
/*   Updated: 2023/01/19 12:46:49 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

static int	ft_exit_canvas(int exit_code)
{
	exit(exit_code);
}

static void	ft_move_arrow_key(t_game *game)
{
	game->nbmoves += 1;
	ft_printf("Number of Moves : %d\n", game->nbmoves);
}

int	ft_key_press_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		ft_exit_canvas(0);
	if (keycode == KEY_UP_ARROW || keycode == KEY_DOWN_ARROW
		|| keycode == KEY_LEFT_ARROW || keycode == KEY_RIGHT_ARROW)
		ft_move_arrow_key(game);
	return (0);
}
