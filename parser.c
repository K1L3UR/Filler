/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ardurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:58:45 by ardurand          #+#    #+#             */
/*   Updated: 2017/10/24 17:58:46 by ardurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft/libft.h"
#include <stdlib.h>

t_token	*init_map(int y, int x)
{
	t_token	*smap;
	int		i;

	i = 0;
	smap = (t_token *)malloc(sizeof(t_token));
	smap->y = y;
	smap->x = x;
	smap->cx = 0;
	smap->cy = 0;
	smap->token = (char **)malloc(sizeof(char *) * (y + 1));
	while (i < y)
	{
		smap->token[i] = ft_strnew(x);
		i++;
	}
	smap->token[i] = NULL;
	return (smap);
}

int		get_number(char *str)
{
	int	result;

	result = 0;
	while (*str > 47 && *str < 58)
	{
		result = result * 10;
		result = result + (*str - '0');
		str++;
	}
	return (result);
}

int		get_token_lines(char *str)
{
	while (*str != ' ')
		str++;
	str++;
	return (get_number(str));
}

int		get_token_cols(char *str)
{
	while (*str != ' ')
		str++;
	str++;
	while (*str != ' ')
		str++;
	str++;
	return (get_number(str));
}

char	*get_map_line(char *str)
{
	while (*str != ' ')
		str++;
	str++;
	return (str);
}
