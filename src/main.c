/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:56:56 by maroy             #+#    #+#             */
/*   Updated: 2022/12/09 18:51:02 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	main(int argc, char **argv)
{
	t_game	game;

	(void) argv;
	(void) argc;

	// if (!ft_start_game(&game, argc, argv))
	// 	return (0);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 640, 480, "so_long");
	mlx_loop(game.mlx);
	return (1);
}
