/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:25:12 by maroy             #+#    #+#             */
/*   Updated: 2023/04/03 18:48:45 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

static void	ft_print_error(void)
{
	perror("\033[1;31m ERROR ");
	exit(EXIT_FAILURE);
}

int	ft_get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	**ft_get_map(char *map_file)
{
	char		*line;
	char		*all_lines;
	int			fd;

	line = "";
	all_lines = ft_strdup("");
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_print_error();
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
	}
	free(line);
	close(fd);
	if (all_lines[0] == '\0')
		ft_print_error();
	return (ft_split(all_lines, '\n'));
}
