/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:56:56 by maroy             #+#    #+#             */
/*   Updated: 2023/01/30 15:55:52 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_read_mapfile(&game, argc, argv);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.winsize.x, game.winsize.y, "so_long");
	mlx_key_hook(game.win, ft_key_press_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
