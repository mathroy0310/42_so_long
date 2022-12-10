

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

int ft_extension_cmp(char *name, char *ext)
{
	int namelen;
	int extlen;
	int i;

	i = -1;
	namelen = ft_strlen(name);
	extlen = ft_strlen(ext);
	name += namelen - extlen;
	while (name[++i])
	{
		if (name[i] != ext[i])
			return(0);
	}
	return (1);
}


int ft_file_checker(int argc, char *mapfile)
{
	if (argc == 1)
		return(ft_error_print("Need to specify the map in args"));
	if (argc > 2)
	{
		ft_warning_print("Only the first arg gonna be used");
		return(0);
	}
	if (!ft_extension_cmp(mapfile, ".ber"))
		return (ft_error_print("Map should be a .ber file"));
	return (1);
}
