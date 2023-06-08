/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:34:55 by maroy             #+#    #+#             */
/*   Updated: 2023/06/08 14:10:40 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define SPRITESIZE 16

# define WALL1_SPRITE "./sprite/Wall1.xpm"
# define WALL2_SPRITE "./sprite/Wall2.xpm"
# define WALL3_SPRITE "./sprite/Wall3.xpm"
# define WALL_N_SPRITE "./sprite/Nord_WALL.xpm"
# define WALL_S_SPRITE "./sprite/Sud_WALL.xpm"
# define WALL_E_SPRITE "./sprite/Est_WALL.xpm"
# define WALL_O_SPRITE "./sprite/Ouest_WALL.xpm"
# define WALL_NO_SPRITE "./sprite/NordOuest_WALL.xpm"
# define WALL_NE_SPRITE "./sprite/NordEst_WALL.xpm"
# define WALL_SO_SPRITE "./sprite/SudOuest_WALL.xpm"
# define WALL_SE_SPRITE "./sprite/SudEst_WALL.xpm"
# define EMPTY_SPRITE "./sprite/Empty.xpm"
# define COLLECTIBLE_SPRITE "./sprite/Collectible.xpm"
# define PLAYER_SPRITE "./sprite/Player.xpm"
# define ENNEMY_SPRITE "./sprite/Ennemy.xpm"
# define EXIT_SPRITE "./sprite/Coffre.xpm"
# define OPEN_EXIT_SPRITE "./sprite/CoffreOuvert.xpm"

typedef struct s_vect2i
{
	int			x;
	int			y;
}				t_vect2i;

typedef struct s_wall
{
	void		*wall1;
	void		*wall2;
	void		*wall3;
	void		*wall_n;
	void		*wall_s;
	void		*wall_e;
	void		*wall_o;
	void		*wall_no;
	void		*wall_ne;
	void		*wall_so;
	void		*wall_se;
}				t_wall;

typedef struct s_img
{
	t_wall		wall;
	void		*empty;
	void		*collectible;
	void		*player;
	void		*exit;
	void		*ennemy;
	void		*exitopen;
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

void			ft_render(t_game *game);

int				ft_escape(t_game *game);

int				ft_key_hook(int keycode, t_game *game);

int				ft_draw_wall_corners(t_game *game, t_vect2i pos);

int				ft_draw_wall_sides(t_game *game, t_vect2i pos);

#endif