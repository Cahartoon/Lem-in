/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:19:35 by edinguim          #+#    #+#             */
/*   Updated: 2018/10/24 03:45:48 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_lem_in		*init_env(void)
{
	t_lem_in	*env;

	if (!(env = (t_lem_in*)malloc(sizeof(t_lem_in))))
		return (NULL);
	if (env)
	{
		env->ants = 0;
		env->nb_rooms = 0;
		env->rooms = NULL;
		env->pipes = NULL;
		env->index_start = -1;
		env->index_end = -1;
		env->file = NULL;
		env->graph = NULL;
		env->path = NULL;
	}
	return (env);
}

static void			add_element(t_lem_in *env, char *line)
{
	add_valid_line(env, line);
	if (is_room(line))
	{
		add_room(env, line, env->nb_rooms);
		env->nb_rooms++;
	}
	if (is_pipe(line))
		add_pipe(env, line);
	if (is_ant(line))
		env->ants = ft_atoi(line);
}

static void			set_env(t_lem_in *env, char *l, int i)
{
	while (get_next_line(0, &l) && l && is_valid_line(*env, l))
	{
		if (ft_strlen(l) && is_start_or_end(l))
		{
			i = is_start_or_end(l);
			ft_strdel(&l);
			get_next_line(0, &l);
			if (is_room(l) && is_valid_line(*env, l))
				add_s_e(env, i, env->nb_rooms);
			else if (is_start_or_end(l) && i != is_start_or_end(l))
			{
				ft_strdel(&l);
				get_next_line(0, &l);
				if (is_room(l) && is_valid_line(*env, l))
					add_s_e(env, 3, env->nb_rooms);
				else
					break ;
			}
			else
				break ;
		}
		add_element(env, l);
		ft_strdel(&l);
	}
	ft_strdel(&l);
}

t_lem_in			*parse(void)
{
	t_lem_in	*env;
	char		*line;
	int			i;

	i = 0;
	line = NULL;
	env = init_env();
	set_env(env, line, i);
	if (line)
		ft_strdel(&line);
	return (env);
}
