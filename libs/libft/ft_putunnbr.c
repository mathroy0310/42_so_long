/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:00:54 by marvin            #+#    #+#             */
/*   Updated: 2022/12/08 13:16:32 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr(unsigned int n, int *count)
{
	if (n >= 10)
	{
		ft_putunbr((n / 10), count);
		ft_putunbr((n % 10), count);
	}
	else
		ft_putchar((n + 48), count);
}
