/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:41:20 by maroy             #+#    #+#             */
/*   Updated: 2023/06/08 14:11:50 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//GNL
char				*get_next_line(int fd);

//ft_printf
int					ft_printf(char *format, ...);

void				ft_putchar(int c, int *count);
void				ft_putnbr(int n, int *count);
void				ft_putunbr(unsigned int n, int *count);
void				ft_putstr(char *str, int *count);
void				ft_puthex(unsigned long n, int *count);
void				ft_putuphex(unsigned long n, int *count);
void				ft_putpointer(void *ptr, int *count);

char				*ft_itoa(int n);
char				**ft_split(char *s, char c);
char				*ft_strchr(char *s, int c);
char				*ft_strdup(char *s1);
size_t				ft_strlen(char *s);
char				*ft_strjoin(char *s1, char *s2);

#endif