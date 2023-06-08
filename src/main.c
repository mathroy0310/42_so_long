/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:56:56 by maroy             #+#    #+#             */
/*   Updated: 2023/06/07 15:22:57 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_init_walls(t_game *game, int *width, int *height)
{
	game->sprite.wall.wall_n = mlx_xpm_file_to_image(game->mlx,
			WALL_N_SPRITE, width, height);
	game->sprite.wall.wall_s = mlx_xpm_file_to_image(game->mlx,
			WALL_S_SPRITE, width, height);
	game->sprite.wall.wall_e = mlx_xpm_file_to_image(game->mlx,
			WALL_E_SPRITE, width, height);
	game->sprite.wall.wall_o = mlx_xpm_file_to_image(game->mlx,
			WALL_O_SPRITE, width, height);
	game->sprite.wall.wall_no = mlx_xpm_file_to_image(game->mlx,
			WALL_NO_SPRITE, width, height);
	game->sprite.wall.wall_ne = mlx_xpm_file_to_image(game->mlx,
			WALL_NE_SPRITE, width, height);
	game->sprite.wall.wall_so = mlx_xpm_file_to_image(game->mlx,
			WALL_SO_SPRITE, width, height);
	game->sprite.wall.wall_se = mlx_xpm_file_to_image(game->mlx,
			WALL_SE_SPRITE, width, height);
	game->sprite.wall.wall1 = mlx_xpm_file_to_image(game->mlx,
			WALL1_SPRITE, width, height);
	game->sprite.wall.wall2 = mlx_xpm_file_to_image(game->mlx,
			WALL2_SPRITE, width, height);
	game->sprite.wall.wall3 = mlx_xpm_file_to_image(game->mlx,
			WALL3_SPRITE, width, height);
}

static	void	ft_init_game(t_game *game)
{
	int		width;
	int		height;

	game->nbmoves = 0;
	game->nbcollect = 0;
	game->wsize.x = ft_strlen(game->map[0]);
	game->wsize.y = ft_get_height(game->map);
	ft_init_walls(game, &width, &height);
	game->sprite.empty = mlx_xpm_file_to_image(game->mlx,
			EMPTY_SPRITE, &width, &height);
	game->sprite.player = mlx_xpm_file_to_image(game->mlx,
			PLAYER_SPRITE, &width, &height);
	game->sprite.ennemy = mlx_xpm_file_to_image(game->mlx,
			ENNEMY_SPRITE, &width, &height);
	game->sprite.exit = mlx_xpm_file_to_image(game->mlx,
			EXIT_SPRITE, &width, &height);
	game->sprite.exitopen = mlx_xpm_file_to_image(game->mlx,
			OPEN_EXIT_SPRITE, &width, &height);
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
	mlx_hook(game.win, 17, (1L << 17), ft_escape, &game);
	mlx_loop(game.mlx);
	return (0);
}
