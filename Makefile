# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 14:06:34 by maroy             #+#    #+#              #
#    Updated: 2022/12/15 10:18:01 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

MAKELIBFT	= $(MAKE) -C libft

INCDIR		= include/
SRCDIR		= src/

CFILES		= main.c errors.c map/map_checker.c
HFILES		= so_long.h

INCS		= $(addprefix $(INCDIR)/, $(HFILES))
SRCS		= $(addprefix $(SRCDIR)/, $(CFILES))
OBJS 		= $(SRCS:.c=.o)

CC			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

%.o:		%.c
			$(CC) $(CFLAGS) -Ilibft -I$(INCDIR) -c $< -o $@

$(NAME):	$(OBJS) 
			@echo '\033[2;37m' "	- Making libft..."$(NONE)
			$(MAKELIBFT)
			@echo '\033[2;37m' "	- Compiling $(NAME)"$(NONE)
			$(CC) $(CFLAGS) $(OBJS) libft/libft.a mlx/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)
			@echo '\033[32m' "- Compiled -"$(NONE)

all:		$(NAME)

clean:
			$(MAKELIBFT) clean
			$(RM) $(OBJS)

fclean:		clean
			$(MAKELIBFT) fclean
			$(RM) $(NAME)

re:			fclean all

norm:
			$(MAKELIBFT) norm
			norminette $(SRCS) $(INCS)

.PHONY:		all clean fclean re norm
