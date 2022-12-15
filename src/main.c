/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:56:56 by maroy             #+#    #+#             */
/*   Updated: 2022/12/15 10:22:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	main(int argc, char **argv)
{
	t_game	game;

	ft_read_mapfile(&game, argc, argv)
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 640, 480, "so_long");
	mlx_loop(game.mlx);
	return (0);
}
