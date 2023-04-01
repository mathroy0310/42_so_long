/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:34:55 by maroy             #+#    #+#             */
/*   Updated: 2023/04/01 14:44:39 by maroy            ###   ########.fr       */
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

typedef struct s_game
{
	void		*win;
	void		*img;
	void		*mlx;
	t_vector	wsize;
	t_vector	p;
	int			nbmoves;
	char		**map;
	int			nbcollect;
}				t_game;

typedef struct s_game_map
{
	int			c;
	int			p;
	int			e;
	t_vector	size;
}				t_game_map;

// Player Movement
void	ft_move_up(t_game **g);
void	ft_move_down(t_game **g);
void	ft_move_right(t_game **g);
void	ft_move_left(t_game **g);

// File checker
void	ft_valid_file(char *file_line);
// get map
char	**ft_get_map(char *map_file);
int		ft_get_height(char **map);

//map checker
void	ft_valid_map(t_game *game);
void	ft_error(t_game ***g, char *err);
//map checker utils
void	check_elements(t_game **game);

#endif