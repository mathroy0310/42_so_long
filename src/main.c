/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:56:56 by maroy             #+#    #+#             */
/*   Updated: 2023/04/01 14:04:32 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

static int	ft_key_hook(int keycode, t_game *game)
{
	int	x;

	if (keycode == 0 || keycode == 123)
		ft_move_left(&game);
	else if (keycode == 1 || keycode == 125)
		ft_move_down(&game);
	else if (keycode == 2 || keycode == 124)
		ft_move_right(&game);
	else if (keycode == 13 || keycode == 126)
		ft_move_up(&game);
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

static	void	ft_init_game(t_game *game)
{
	game->nbcollect = 0;
	game->nbmoves = 0;
	game->wsize.x = ft_strlen(game->map[0]) * 32;
	game->wsize.y = ft_get_height(game->map) * 32;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc <= 1)
	{
		perror("\033[1;31m ERROR : Must have more than 1 argc.	\033[0m");
		exit(EXIT_FAILURE);
	}
	(void)argv;
	ft_valid_file(argv[1]);
	game.map = ft_get_map(argv[1]);
	if (game.map != NULL)
	{
		ft_valid_map(&game);
		ft_init_game(&game);
	}
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.wsize.x, game.wsize.y, "so_long");
	mlx_hook(game.win, 2, (1L << 0), ft_key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
