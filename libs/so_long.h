/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:34:55 by maroy             #+#    #+#             */
/*   Updated: 2022/12/15 13:50:35 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include "libft/libft.h"
# include "./libft/libft.h"
# include "../mlx/mlx.h"

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E'
}	t_tiletype;

typedef struct s_tile
{
	t_tiletype		type;
	t_vector		position;
}	t_tile;

typedef struct s_game
{
	void		*win;
	void		*mlx;
	t_vector	windwsize;
	t_vector	charpos;
	t_vector	exitpos;
	int			nbmoves;
	t_tile		**tilemap;

}			t_game;

//errors.c
void	ft_warning_print(char *message);
void	ft_error_print(char *message);

/*SRC/GAME*/
void ft_read_mapfile(t_game *game, int argc, char **argv);

#endif