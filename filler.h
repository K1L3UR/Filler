/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ardurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 19:29:51 by ardurand          #+#    #+#             */
/*   Updated: 2017/10/24 19:29:53 by ardurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

typedef struct	s_token
{
	int			x;
	int			y;
	int			cx;
	int			cy;
	char		**token;
}				t_token;

typedef struct	s_play
{
	int			**map_cost;
	int			x;
	int			y;
	int			max_cost;
	int			cost;
	char		ia;
	char		player;
	int			max_select;
	int			far_ia;
	int			fx;
	int			fy;
}				t_play;

typedef t_token	t_map;

int				check(char *str, char *term);
char			getplayer(char *line);
t_token			*get_map(char **line);
t_token			*new_token(int y, int x);
t_token			*get_token(char **line);
int				out_limit(t_token *map, t_token *token);
int				*ft_strfillint(int number, int lenght);
t_play			*init_resolve(int x, int y, int max_cost, char player);
t_token			*init_map(int y, int x);
int				get_number(char *str);
int				get_token_lines(char *str);
int				get_token_cols(char *str);
char			*get_map_line(char *str);
int				dist_vector(int y, int x, t_play *play);
t_play			*placement_cost(t_token *map, t_token *token, char player);

#endif
