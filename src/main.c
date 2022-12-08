/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:56:56 by maroy             #+#    #+#             */
/*   Updated: 2022/12/08 16:28:05 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libs/so_long.h"

int	ft_key(int key, t_game *param)
{
	(void)param;
	if (key == 53)
	{
		mlx_destroy_window(param->mlx, param->win);
		exit(0);
	}
	if (key == 13)
		ft_printf("deez");
	if (key == 1)
		ft_printf("nuts");
	return (0);
}


int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 640, 480, "so_long");
	mlx_key_hook(game.win, ft_key, &game);
	mlx_loop(game.mlx);
	return (1);
}
