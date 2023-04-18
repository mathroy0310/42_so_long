/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:34:55 by maroy             #+#    #+#             */
/*   Updated: 2023/04/18 15:31:15 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "./libft/libft.h"

# define SPRITESIZE 32

# define WALL_SPRITE "./sprite/Walls.xpm"
# define EMPTY_SPRITE "./sprite/Empty.xpm"
# define COLLECTIBLE_SPRITE "./sprite/YellowSquare.xpm"
# define PLAYER_SPRITE "./sprite/Player.xpm"
# define EXIT_SPRITE "./sprite/ExitOpen.xpm"

typedef struct s_vect2i
{
	int			x;
	int			y;
}				t_vect2i;

typedef struct s_img
{
	void		*wall;
	void		*empty;
	void		*collectible;
	void		*player;
	void		*exit;
}				t_img;

typedef struct s_game
{
	void		*win;
	void		*img;
	t_img		sprite;
	void		*mlx;
	t_vect2i	wsize;
	t_vect2i	player_pos;
	int			nbmoves;
	char		**map;
	char		**backup_map;
	int			nbcollect;
	int			nbexit;
}				t_game;

typedef struct s_game_map
{
	int			c;
	int			p;
	int			e;
	t_vect2i	s;
}				t_game_map;

// Player Movement
void			ft_move_up(t_game *g);
void			ft_move_down(t_game *g);
void			ft_move_right(t_game *g);
void			ft_move_left(t_game *g);

// File checker
void			ft_valid_file(char *file_line);
// get map
char			**ft_get_map(char *map_file);
int				ft_get_height(char **map);

//map checker
void			ft_valid_map(t_game *game);
void			ft_error(t_game *g, char *err);
//map checker utils
void			check_elements(t_game *game);

void			ft_render(t_game *game);

int				ft_collectible(t_game *game);

void			ft_you_win(t_game *game);

void			check_is_map_possibe(t_game *game);

#endif