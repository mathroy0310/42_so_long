/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:28:40 by maroy             #+#    #+#             */
/*   Updated: 2022/12/09 18:47:20 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"

void	ft_warning_print(char *message)
{
	ft_printf("\033[1;33m" "Warning:\n		%s\n", message);
}

int	ft_error_print(char *message)
{
	ft_printf("\033[1;31m" "Error:\n		%s\n", message);
	return (0);
}

void	*ft_error_print_null(char *message)
{
	ft_printf("\033[1;31m" "Error:\n		%s\n", message);
	return (NULL);
}
