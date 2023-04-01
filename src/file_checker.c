/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:59:08 by maroy             #+#    #+#             */
/*   Updated: 2023/04/01 12:20:58 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

static	int	ft_ext_cmp(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	ft_valid_file(char *file_line)
{
	while (*file_line)
	{
		if (*file_line == '.')
		{
			if (ft_ext_cmp(file_line, ".ber"))
			{
				return ;
			}
		}
		file_line++;
	}
	printf("\033[1;31m ERROR: file is not valid.	\033[0m");
	exit(EXIT_FAILURE);
}
