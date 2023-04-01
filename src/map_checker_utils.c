/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:26:03 by maroy             #+#    #+#             */
/*   Updated: 2023/04/01 14:49:11 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"


static char	*ft_err_message(t_game_map *map)
{
	if (map->c == 0)
		return (
			"\033[1;31m ERROR : Element 'C' is missing	\033[0m");
	if (map->p == 0)
		return (
			"\033[1;31m ERROR : Element 'P' is missing	\033[0m");
	if (map->e == 0)
		return (
			"\033[1;31m ERROR : Element 'E' is missing	\033[0m");
	if (map->p > 1)
		return (
			"\033[1;31m ERROR : There is more than one element 'P' \033[0m");
	return ("\033[1;31m ERROR : Element is missing in the map \033[0m");
}

static char* ft_unknown_elements(t_game ***g, char c)
{
	int	x;

	x = 0;
	while ((**g)->map[x])
	{
		free((**g)->map[x]);
		x++;
	}
	free((**g)->map);
	ft_printf("\033[1;31m ERROR : Unknown Element %c \033[0m", c);
	exit(EXIT_FAILURE);
}

void	check_elements(t_game **game)
{
	t_game_map	map;

	map.c = 0;
	map.p = 0;
	map.size.y = ft_get_height((*game)->map) - 1;
	while (map.size.y--)
	{
		map.size.x = 0;
		while ((*game)->map[map.size.y][map.size.x] != '\0')
		{
			if ((*game)->map[map.size.y][map.size.x] == 'P')
				map.p++;
			else if ((*game)->map[map.size.y][map.size.x] == 'C')
				map.c++;
			else if ((*game)->map[map.size.y][map.size.x] == 'E')
				map.e++;
			else if ((*game)->map[map.size.y][map.size.x] != '1' &&
					(*game)->map[map.size.y][map.size.x] != '0')
				ft_unknown_elements(&game,
					(*game)->map[map.size.y][map.size.x]);	
			map.size.x++;
		}
	}
	if (map.c == 0 || map.p == 0 || map.e == 0 || map.p > 1)
		ft_error(&game, ft_err_message(&map));
}