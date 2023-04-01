/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:26:09 by maroy             #+#    #+#             */
/*   Updated: 2023/04/01 13:01:16 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cpy(char *dst, char const *src, int n)
{
	while (n--)
		*dst++ = *src++;
	*dst = '\0';
}

static int	ft_allocate(char const *s, char **list, int word_length, int index)
{
	char	*word;

	word = (char *)malloc(sizeof(char) * (word_length + 1));
	if (!word)
	{
		while (index >= 0)
			free(list[index--]);
		free(list);
		return (0);
	}
	ft_cpy(word, (s - word_length), word_length);
	list[index++] = word;
	return (1);
}

static int	ft_create_word(char const *s, char c, char **list, int words)
{
	int	word_length;
	int	index;

	index = 0;
	while (*s != '\0')
	{
		word_length = 0;
		if (*s != c)
		{
			while (index != words)
			{
				if (*s == c || *s == '\0')
				{
					if (!ft_allocate(s, list, word_length, index))
						return (0);
					index++;
					break ;
				}
				word_length++;
				s++;
			}			
		}
		s++;
	}
	return (index);
}

static int	ft_wcount(const char *s, char c)
{
	int	i;
	int	words;

	if (!s)
		return (0);
	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			words++;
		i++;
	}
	return (words);
}

char	**ft_split(char *s, char c)
{
	int		index;
	int		words;
	char	**strs;

	if (!s || s == 0)
		return (NULL);
	words = ft_wcount(s, c);
	strs = malloc(sizeof(char *) * (words + 1));
	if (!strs)
		return (NULL);
	index = ft_create_word(s, c, strs, words);
	if (!strs)
		return (NULL);
	strs[index] = NULL;
	free(s);
	return (strs);
}
