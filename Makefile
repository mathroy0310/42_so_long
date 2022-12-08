# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maroy <maroy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 14:06:34 by maroy             #+#    #+#              #
#    Updated: 2022/12/08 15:35:06 by maroy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long


CFLAGS	=	-g -Wall -Werror -Wextra -I. -I./$(INCDIR)
CC = gcc
RM		=	rm -f
RM_F		=	rm -rf

INCDIR= libs/

SRCDIR = src/
SRCS =	src/main.c

OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

LIBFT = libft.a
LIBFTDIR = libs/libft/


all : do_libft $(NAME)
 
${NAME}: $(OBJS)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $@ $(OBJS) $(LIBFTDIR)$(LIBFT)

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $@

clean:
	@$(RM_F) $(OBJDIR)
	@$(MAKE) --no-print-directory -C $(LIBFTDIR) clean


fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) --no-print-directory -C $(LIBFTDIR) fclean


re: fclean all

do_libft:
	@$(MAKE) -C $(LIBFTDIR)

.PHONY:		all clean fclean re header