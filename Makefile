# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maroy <maroy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 14:06:34 by maroy             #+#    #+#              #
#    Updated: 2023/06/07 15:23:28 by maroy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

MAKELIBFT	= $(MAKE) -C libft/



CFILES		= main.c player_movement.c file_checker.c get_map.c  map_checker.c  map_checker_utils.c collect.c check_map_possible.c render.c walls.c keyhook.c

SRCDIR		= src/
INCDIR	=	include/
INCS		= include/so_long.h
SRCS		= $(addprefix $(SRCDIR)/, $(CFILES))
OBJS 		= $(SRCS:.c=.o)

CC			= clang
CFLAGS		= -Wall -Wextra -Werror  -g
RM			= rm -rf



%.o:		%.c
			$(CC) $(CFLAGS) -Ilibft -I$(INCDIR) -c $< -o $@

$(NAME):	$(OBJS) 
			@echo ""
			@echo '\033[1;37m' "- Making libft... -"$(NONE)
			@echo '\033[1;30m' ""
			$(MAKELIBFT)
			@echo ""
			@echo '\033[32m' "- Libft Compiled -"$(NONE)
			@echo ""
			@echo '\033[1;37m' "- Making $(NAME)... -"$(NONE)
			@echo '\033[1;30m' ""
			$(CC) $(CFLAGS) $(OBJS) libft/libft.a mlx/libmlx.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
			@echo ""
			@echo '\033[32m' "- Compiled -"$(NONE)
	
all:		$(NAME)

clean:
			@echo ""
			@echo '\033[1;31m' "- Libft Cleaning... -"$(NONE)
			@echo '\033[1;30m' ""
			$(MAKELIBFT) clean
			@echo ""
			@echo '\033[1;31m' "- so_long Cleaning... -"$(NONE)
			@echo '\033[1;30m' ""
			$(RM) $(OBJS)

fclean:		clean
			$(MAKELIBFT) fclean
			$(RM) $(NAME)

re:			fclean all

norm:
			$(MAKELIBFT) norm
			norminette $(SRCS) $(INCS)

.PHONY:		all clean fclean re norm
