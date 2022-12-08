# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maroy <maroy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 14:35:20 by maroy             #+#    #+#              #
#    Updated: 2022/12/08 14:15:37 by maroy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS  = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_lstadd_front.c ft_lstclear.c ft_lstmap.c ft_lstlast.c ft_lstsize.c \
		ft_lstnew.c ft_lstadd_back.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c ft_putchar.c \
		ft_strlen.c ft_putstr.c ft_putnbr.c ft_putunnbr.c ft_puthex.c ft_putuphex.c \
		ft_putpointer.c get_next_line.c 
 
OBJS   = ${SRCS:.c=.o}
 
NAME   = libft.a
 
CC     = gcc
 
CFLAGS = -Wall -Wextra -Werror
 
all    : ${NAME}
 
${NAME}: ${OBJS}
				@ar -rcs  ${NAME} ${OBJS}
 
clean  :  
				@rm -f ${OBJS} ${OBJSB}
 
fclean : clean
				@rm -f ${NAME}
 
re     : fclean all
