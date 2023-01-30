/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:41:47 by maroy             #+#    #+#             */
/*   Updated: 2023/01/30 17:04:56 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

static int	ft_tilechecker(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}

static int	ft_wallchecker(int x, int y, char c, t_game *game)
{
	if (x == 0 || y == 0 || game->winsize.x - 1 == x || game->winsize.y
		- 1 == y)
	{
		if (c == '1')
			return (0);
		else
			return (1);
	}
	return (-1);
}

static int	ft_exitplayernb(char c)
{
	static int	playernb;
	static int	exitnb;

	if (c == 'P')
	{
		playernb++;
		return (playernb);
	}
	if (c == 'E')
	{
		exitnb++;
		return (exitnb);
	}
	return (0);
}

void	ft_check_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->gamedata[++y])
	{
		x = -1;
		while (game->gamedata[y][++x])
		{
			if (game->winsize.x > x && game->winsize.y > y
				&& ft_tilechecker(game->gamedata[y][x]) == 0)
				ft_error_print("Reading the map file");
			if (game->winsize.x > x && game->winsize.y > y && ft_wallchecker(x,
					y, game->gamedata[y][x], game) > 0)
				ft_error_print("The Map limit border should be walls");
			if (game->winsize.x > x && game->winsize.y > y
				&& ft_exitplayernb(game->gamedata[y][x]) == 2 && ft_exitplayernb(game->gamedata[y][x]) != 1)
				ft_error_print("Must only be one and Exit and Player");
		}
	}
}
