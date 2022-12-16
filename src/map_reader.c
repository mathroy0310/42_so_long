/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:41:59 by marvin            #+#    #+#             */
/*   Updated: 2022/12/15 17:32:58 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

static void	ft_gamedata_malloc(t_game *game, char **argv, int i)
{
	int	fd;
	int	j;

	j = 0;
	game->gamedata = malloc(sizeof(char *) * i);
	if (!game->gamedata)
		ft_error_print("Malloc failed lol skill issue 😂");
	fd = open(argv[1], O_RDONLY);
	while (j < i)
	{
		game->gamedata[j] = get_next_line(fd);
		j++;
	}
	game->windwsize.y = j - 1;
	close(fd);
}

static void	ft_save_file_content(t_game *game, char **argv)
{
	int		fd;
	int		linecount;
	char	*str;

	str = NULL;
	linecount = 0;
	fd = open(argv[1], O_RDONLY);
	while ((linecount == 0) || (str != NULL && linecount > 0))
	{
		free(str);
		str = get_next_line(fd);
		linecount++;
	}
	if (linecount == 1)
		ft_error_print("The file is missing content.");
	close(fd);
	ft_gamedata_malloc(game, argv, linecount);
}

static void	ft_argc_ext_checker(int argc, char **argv)
{
	int		fd;
	char	*s;

	if (argc == 1)
		ft_error_print("Need to specify the map in args.");
	if (argc > 2)
	{
		ft_warning_print("Only the first arg gonna be used.");
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_error_print("Map file not found.");
	}
	s = ft_strtrim(argv[1], ".ber\0");
	if (ft_strlen(s) == ft_strlen(argv[1]) - 1)
	{
		free(s);
		ft_error_print("Map should be a .ber file.");
	}
	free(s);
	close(fd);
}

void	ft_read_mapfile(t_game *game, int argc, char **argv)
{
	ft_argc_ext_checker(argc, argv);
	ft_save_file_content(game, argv);
	game->windwsize.x = (int)ft_strlen(game->gamedata[0]);
	if (game->windwsize.x == game->windwsize.y)
		ft_error_print("Map must be rectangular");
}
