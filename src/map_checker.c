/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:41:47 by maroy             #+#    #+#             */
/*   Updated: 2022/12/15 17:37:14 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int	ft_tilechecker(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}

void	ft_check_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->gamedata[++i])
	{
		j = -1;
		while (game->gamedata[i][++j])
		{
			if (ft_tilechecker(game->gamedata[i][j]) == 0)
				ft_error_print("error Reading the map file");
		}
	}
}
