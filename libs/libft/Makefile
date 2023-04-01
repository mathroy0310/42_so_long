# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maroy <maroy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 14:35:20 by maroy             #+#    #+#              #
#    Updated: 2023/04/01 12:44:56 by maroy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS  = ft_printf.c ft_putchar.c \
		ft_putstr.c ft_putnbr.c ft_putunnbr.c ft_puthex.c ft_putuphex.c \
		ft_putpointer.c get_next_line.c get_next_line_utils.c ft_split.c ft_strdup.c
 
OBJS   = ${SRCS:.c=.o}
 
NAME   = libft.a
 
CC     = gcc
 
CFLAGS = -Wall -Wextra -Werror
 
all    : ${NAME}

# .c.o:
# 		${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
				@ar -rcs  ${NAME} ${OBJS}
 
clean  :  
				@rm -f ${OBJS} ${OBJSB}
 
fclean : clean
				@rm -f ${NAME}
 
re     : fclean all
