/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:34:55 by maroy             #+#    #+#             */
/*   Updated: 2022/12/08 15:59:01 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <mlx.h>

typedef struct s_game
{
	int		width;
	int		height;
	int		charpos[2];
	int		exitpos[2];
	int		nbmoves;
	char	**tileset;
	void	*win;
	void	*mlx;
}			t_game;

char		*ft_file_read(t_game **tileset);

#endif