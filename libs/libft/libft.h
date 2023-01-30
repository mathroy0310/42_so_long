/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:41:20 by maroy             #+#    #+#             */
/*   Updated: 2023/01/12 14:44:24 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

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
void				ft_putstr( char *str, int *count);
void				ft_puthex(unsigned long n, int *count);
void				ft_putuphex(unsigned long n, int *count);
void				ft_putpointer(void *ptr, int *count);

int					ft_atoi( char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memchr( void *s, int c, size_t n);
int					ft_memcmp( void *s1,  void *s2, size_t n);
void				*ft_memcpy(void *dst,  void *src, size_t len);
void				*ft_memmove(void *dst,  void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				**ft_split(char  *s, char c);
char				*ft_strchr(char *s, int c);
char				*ft_strdup(char *s1);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char *s1, char *s2);
size_t				ft_strlcat(char *dst, char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t				ft_strlen(char *s);
char				*ft_strmapi(char  *s, char (*f)(unsigned int, char));

int					ft_strncmp( char *s1,  char *s2, size_t n);
char				*ft_strnstr( char *haystack,  char *needle,
						size_t len);
char				*ft_strrchr( char *s, int c);
char				*ft_strtrim(char  *s1, char  *set);
char				*ft_substr(char  *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
#endif