/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ardurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:58:41 by ardurand          #+#    #+#             */
/*   Updated: 2017/10/24 17:58:42 by ardurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include "filler.h"
#include <stdlib.h>

void	ft_print_result(int x, int y)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

void	find_loop(t_play *play, int i, int j, int dist)
{
	if (play->map_cost[i][j] >= play->max_select && play->map_cost[i][j] > 0)
	{
		if (play->max_select == play->map_cost[i][j] && dist < play->far_ia)
		{
			play->max_select = play->map_cost[i][j];
			play->fx = j;
			play->fy = i;
			play->far_ia = dist;
		}
		else if (play->max_select < play->map_cost[i][j])
		{
			play->max_select = play->map_cost[i][j];
			play->fx = j;
			play->fy = i;
			play->far_ia = 999999;
		}
	}
}

void	find_best(t_play *play)
{
	int	i;
	int	j;
	int	dist;

	play->fx = 0;
	dist = 999999;
	play->fy = 0;
	i = -1;
	j = -1;
	while (++i < play->y)
	{
		while (++j < play->x)
		{
			dist = dist_vector(i, j, play);
			find_loop(play, i, j, dist);
		}
		j = -1;
	}
	ft_print_result(play->fx, play->fy);
}

void	free_all(t_play *play, t_token *map, t_token *token)
{
	ft_strdel(map->token);
	ft_strdel(token->token);
	free(*play->map_cost);
	*play->map_cost = NULL;
	map = NULL;
	token = NULL;
}

int		main(void)
{
	char	*line;
	char	player;
	t_token	*map;
	t_token	*token;
	t_play	*play;

	token = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (check(line, "$$$"))
			player = getplayer(line);
		if (check(line, "Plateau"))
			map = get_map(&line);
		if (check(line, "Piece"))
			token = get_token(&line);
		if (token != NULL)
		{
			play = placement_cost(map, token, player);
			find_best(play);
			free_all(play, map, token);
			token = NULL;
		}
	}
	return (0);
}
