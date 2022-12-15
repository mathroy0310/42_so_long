/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:50:26 by maroy             #+#    #+#             */
/*   Updated: 2022/11/11 15:04:59 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	void			*b;

	if (!s)
		return (NULL);
	i = 0;
	str = (unsigned char *)s;
	b = NULL;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
		{
			b = &str[i];
			break ;
		}
		i++;
	}
	return (b);
}
