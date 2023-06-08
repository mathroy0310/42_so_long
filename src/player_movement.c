/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:49:12 by maroy             #+#    #+#             */
/*   Updated: 2023/06/07 14:14:04 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_move_up(t_game *g)
{
	if (('1' != g->map[g->player_pos.y - 1][g->player_pos.x])
		|| ('E' == g->map[g->player_pos.y - 1][g->player_pos.x]
			&& g->nbcollect == 0))
	{
		if ('C' == g->map[g->player_pos.y - 1][g->player_pos.x])
		{
			g->map[g->player_pos.y - 1][g->player_pos.x] = '0';
			g->nbcollect -= 1;
		}
		if ('E' == g->map[g->player_pos.y - 1][g->player_pos.x])
		{
			if (g->nbcollect == 0)
				ft_you_win(g);
			else
				ft_render(g);
		}
		else
		{
			g->player_pos.y -= 1;
			g->nbmoves += 1;
			ft_printf("Nombre de Mouvement : <%d> \n", g->nbmoves);
		}
	}
	ft_render(g);
}

void	ft_move_down(t_game *g)
{
	if (('1' != g->map[g->player_pos.y + 1][g->player_pos.x])
		|| ('E' == g->map[g->player_pos.y + 1][g->player_pos.x]
			&& g->nbcollect != 0))
	{
		if ('C' == g->map[g->player_pos.y + 1][g->player_pos.x])
		{
			g->map[g->player_pos.y + 1][g->player_pos.x] = '0';
			g->nbcollect -= 1;
		}
		if ('E' == g->map[g->player_pos.y + 1][g->player_pos.x])
		{
			if (g->nbcollect == 0)
				ft_you_win(g);
			else
				ft_render(g);
		}
		else
		{
			g->player_pos.y += 1;
			g->nbmoves += 1;
			ft_printf("Nombre de Mouvement : <%d> \n", g->nbmoves);
		}
	}
	ft_render(g);
}

void	ft_move_right(t_game *g)
{
	if (('1' != g->map[g->player_pos.y][g->player_pos.x + 1])
		|| ('E' == g->map[g->player_pos.y][g->player_pos.x + 1]
			&& g->nbcollect != 0))
	{
		if ('C' == g->map[g->player_pos.y][g->player_pos.x + 1])
		{
			g->map[g->player_pos.y][g->player_pos.x + 1] = '0';
			g->nbcollect -= 1;
		}
		if ('E' == g->map[g->player_pos.y][g->player_pos.x + 1])
		{
			if (g->nbcollect == 0)
				ft_you_win(g);
			else
				ft_render(g);
		}
		else
		{
			g->player_pos.x += 1;
			g->nbmoves += 1;
			ft_printf("Nombre de Mouvement : <%d> \n", g->nbmoves);
		}
	}
	ft_render(g);
}

void	ft_move_left(t_game *g)
{
	if (('1' != g->map[g->player_pos.y][g->player_pos.x - 1])
		|| ('E' == g->map[g->player_pos.y][g->player_pos.x - 1]
			&& g->nbcollect != 0))
	{
		if ('C' == g->map[g->player_pos.y][g->player_pos.x - 1])
		{
			g->map[g->player_pos.y][g->player_pos.x - 1] = '0';
			g->nbcollect -= 1;
		}
		if ('E' == g->map[g->player_pos.y][g->player_pos.x - 1])
		{
			if (g->nbcollect == 0)
				ft_you_win(g);
			else
				ft_render(g);
		}
		else
		{
			g->player_pos.x -= 1;
			g->nbmoves += 1;
			ft_printf("Nombre de Mouvement : <%d> \n", g->nbmoves);
		}
	}
	ft_render(g);
}
