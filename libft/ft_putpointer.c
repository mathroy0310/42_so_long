/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:57:25 by maroy             #+#    #+#             */
/*   Updated: 2022/12/08 13:11:01 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putpointer(void *ptr, int *count)
{
	ft_putstr("0x", count);
	ft_puthex((unsigned long long)ptr, count);
}
