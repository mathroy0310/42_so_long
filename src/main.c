/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:56:56 by maroy             #+#    #+#             */
/*   Updated: 2022/12/08 22:36:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libs/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if(!ft_startgame(&game, argc, argv))
		return (0);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 640, 480, "so_long");
	mlx_key_hook(game.win, ft_key, &game);
	mlx_loop(game.mlx);
	return (1);
}
