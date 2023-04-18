/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:56:56 by maroy             #+#    #+#             */
/*   Updated: 2023/04/18 15:03:47 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

static int	ft_key_hook(int keycode, t_game *game)
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

void	ft_render(t_game *game)
{
	int		map_x;
	int		map_y;

	map_x = 0;
	while (game->wsize.x > map_x)
	{
		map_y = 0;
		while (game->wsize.y > map_y)
		{
			if (game->map[map_y][map_x] == '0')
				game->img = game->sprite.empty;
			else if (game->map[map_y][map_x] == '1')
				game->img = game->sprite.wall;
			else if (game->map[map_y][map_x] == 'E')
				game->img = game->sprite.exit;
			else if (game->map[map_y][map_x] == 'C')
				game->img = game->sprite.collectible;
			if (map_y == game->player_pos.y && map_x == game->player_pos.x)
				game->img = game->sprite.player;
			mlx_put_image_to_window(game->mlx, game->win,
				game->img, map_x * SPRITESIZE, map_y * SPRITESIZE);
			map_y++;
		}
		map_x++;
	}
}	

static	void	ft_init_game(t_game *game)
{
	int		width;
	int		height;

	game->nbmoves = 0;
	game->nbcollect = 0;
	game->wsize.x = ft_strlen(game->map[0]);
	game->wsize.y = ft_get_height(game->map);
	game->sprite.empty = mlx_xpm_file_to_image(game->mlx,
			EMPTY_SPRITE, &width, &height);
	game->sprite.wall = mlx_xpm_file_to_image(game->mlx,
			WALL_SPRITE, &width, &height);
	game->sprite.player = mlx_xpm_file_to_image(game->mlx,
			PLAYER_SPRITE, &width, &height);
	game->sprite.exit = mlx_xpm_file_to_image(game->mlx,
			EXIT_SPRITE, &width, &height);
	game->sprite.collectible = mlx_xpm_file_to_image(game->mlx,
			COLLECTIBLE_SPRITE, &width, &height);
}

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc <= 1)
	{
		ft_printf("\033[1;31m ERROR 🛑 : Must have more than 1 argc.	\033[0m");
		exit(EXIT_FAILURE);
	}
	(void)argv;
	ft_valid_file(argv[1]);
	game.map = ft_get_map(argv[1]);
	game.backup_map = ft_get_map(argv[1]);
	if (game.map != NULL)
	{
		ft_valid_map(&game);
		game.mlx = mlx_init();
		ft_init_game(&game);
		ft_collectible(&game);
		game.win = mlx_new_window(game.mlx, game.wsize.x * SPRITESIZE,
				game.wsize.y * SPRITESIZE, "so_long");
		ft_render(&game);
	}
	mlx_hook(game.win, 2, 1, ft_key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
