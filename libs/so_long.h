/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:34:55 by maroy             #+#    #+#             */
/*   Updated: 2023/01/30 15:55:51 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include "libft/libft.h"
# include "./libft/libft.h"
# include "../mlx/mlx.h"

# define KEY_ESC 53
# define KEY_LEFT_ARROW 123
# define KEY_UP_ARROW 126
# define KEY_RIGHT_ARROW 124
# define KEY_DOWN_ARROW 125

# define WALL "./sprite/BlueSuare.xpm"
# define EMPTY "./sprite/GreenSquare.xpm"
# define COLLECTABLE "./sprite/BlueSquare.xpm"
# define PLAYER "./sprite/RedSquare.xpm"
# define EXIT "./sprite/YellowSquare.xpm"

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

// typedef enum e_tiletype
// {
// 	EMPTY = '0',
// 	WALL = '1',
// 	COLLECTABLE = 'C',
// 	PLAYER = 'P',
// 	EXIT = 'E'
// }	t_tiletype;

// typedef struct s_tile
// {
// 	t_tiletype		type;
// 	t_vector		position;
// }	t_tile;

typedef struct s_game
{
	void		*win;
	void		*mlx;
	t_vector	winsize;
	t_vector	charpos;
	t_vector	exitpos;
	int			nbmoves;
	char		**gamedata;
}			t_game;

//errors.c
void	ft_warning_print(char *message);
void	ft_error_print(char *message);

/*SRC/GAME*/
void	ft_read_mapfile(t_game *game, int argc, char **argv);

int		ft_key_press_hook(int keycode, t_game *game);

void	ft_check_map(t_game *game);

#endif