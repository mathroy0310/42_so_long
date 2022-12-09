/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:41:59 by marvin            #+#    #+#             */
/*   Updated: 2022/12/08 22:41:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libs/so_long.h"

char	**ft_read_map(char *mapfile)
{
	char	**map;
	int		fd;
	int		i;

	map = alloc_columns(mapfile);
	if (map == NULL)
		return (NULL);
	fd = open(mapfile, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &map[i++]))
		;
	map[i] = NULL;
	close(fd);
	return (map);
}