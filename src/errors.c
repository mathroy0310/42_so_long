/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:28:40 by maroy             #+#    #+#             */
/*   Updated: 2023/01/12 12:56:32 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	ft_warning_print(char *message)
{
	ft_printf("\033[1;33m" "Warning:\n%s\n", message);
}

void	ft_error_print(char *message)
{
	ft_printf("\033[1;31m" "Error:\n%s\n", message);
	exit(1);
}
