/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:12:06 by maroy             #+#    #+#             */
/*   Updated: 2022/11/11 15:03:55 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*csrc;
	char	*cdst;

	csrc = (char *)src;
	cdst = (char *)dst;
	i = -1;
	if (!csrc || !cdst)
		return (NULL);
	if (csrc > cdst)
	{
		while (++i < len)
			cdst[i] = csrc[i];
	}
	else
	{
		while (++i != len)
			cdst[len - i - 1] = csrc[len - i - 1];
	}
	return (dst);
}
