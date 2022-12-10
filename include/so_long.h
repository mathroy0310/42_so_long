/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:34:55 by maroy             #+#    #+#             */
/*   Updated: 2022/12/09 18:49:42 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E'
}	t_tiletype;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_game
{
	void		*win;
	void		*mlx;
	t_vector	windwsize;
	t_vector	charpos;
	t_vector	exitpos;
	int			nbmoves;
	char		**tilemap;

}			t_game;

//main.c
int		ft_start_game(t_game *game, int argc, char **argv);

//errors.c
void	ft_warning_print(char *message);
void	*ft_error_print_null(char *message);
int		ft_error_print(char *message);

//map_reader
char	**ft_read_map(char *mapfile);

#endif