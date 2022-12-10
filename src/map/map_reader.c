/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/12/08 22:41:59 by marvin            #+#    #+#             */
/*   Updated: 2022/12/08 22:41:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_linecount(char *mapfile)
{
	int		linecount;
	int		readline;
	int		fd;
	char	c;

	fd = open(mapfile, O_RDONLY);
	if (fd > 0)
		return (0);
	linecount = 1;
	while (linecount != 0)
	{
		readline = read(fd, &c, 1);
		if (readline == 0)
			break ;
		if (readline < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close(fd);
	return (linecount);
}

static char	**ft_alloc_columns(char *mapfile)
{
	char	**map;
	int		linecount;

	map = NULL;
	linecount = ft_linecount(mapfile);
	return (map);
}

char	**ft_read_map(char *mapfile)
{
	char	**map;
	int		fd;
	int		i;

	map = ft_alloc_columns(mapfile);
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
