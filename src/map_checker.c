/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:43:56 by maroy             #+#    #+#             */
/*   Updated: 2023/06/07 14:14:04 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(t_game *g, char *err)
{
	int	x;

	x = 0;
	while (g->map[x])
	{
		free(g->map[x]);
		x++;
	}
	free(g->map);
	ft_printf("%s", err);
	exit(EXIT_FAILURE);
}

static void	check_is_rectangular(t_game *game)
{
	int	x;
	int	y;
	int	height;
	int	backup;

	y = 0;
	backup = 0;
	height = ft_get_height(game->map);
	while (y != height)
	{
		x = 0;
		while (game->map[y][x] != '\0')
			x++;
		y++;
		if (backup != 0)
		{
			if (backup != x)
				ft_error(game,
					"\033[1;31m ERROR 🛑 : map is not rectangular	\033[0m");
		}
		else
			backup = x;
	}
}

static int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static void	check_is_surrounded_by_walls(t_game *g)
{
	int		i;
	char	*err;

	err = "\033[1;31m ERROR 🛑 : map is not surrounded by walls	\033[0m";
	if (check_line(g->map[0]))
		ft_error(g, err);
	i = ft_get_height(g->map) - 1;
	while (i)
	{
		if (g->map[i][0] != '1' ||
			g->map[i][ft_strlen(g->map[i]) - 1] != '1')
		{
			ft_error(g, err);
		}
		i--;
	}
	if (check_line(g->map[ft_get_height(g->map) - 1]))
		ft_error(g, err);
}

void	ft_valid_map(t_game *game)
{
	check_is_rectangular(game);
	check_is_surrounded_by_walls(game);
	check_elements(game);
	check_is_map_possibe(game);
}
