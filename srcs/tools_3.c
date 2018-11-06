/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 19:28:32 by edinguim          #+#    #+#             */
/*   Updated: 2018/10/24 04:00:18 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			add_room(t_lem_in *env, char *line, int index)
{
	t_rooms		*new;

	new = new_room(env, line, index);
	if (env->rooms == NULL)
		env->rooms = new;
	else
		room_append(env->rooms, new);
}

void			add_pipe(t_lem_in *env, char *line)
{
	t_pipes		*new;

	new = new_pipe(line);
	if (env->pipes == NULL)
		env->pipes = new;
	else
		pipe_append(env->pipes, new);
}

void			add_s_e(t_lem_in *env, int i, int index)
{
	if (i == 1 && (index || !index))
	{
		add_valid_line(env, "##start");
		env->index_start = index;
	}
	if (i == 2)
	{
		add_valid_line(env, "##end");
		env->index_end = index;
	}
	if (i == 3)
	{
		add_valid_line(env, "##start");
		add_valid_line(env, "##end");
		env->index_start = index;
		env->index_end = index;
	}
}

void			add_valid_line(t_lem_in *env, char *s)
{
	if (is_ant(s) || is_room(s) || is_pipe(s) || is_start_or_end(s))
	{
		if (env->file == NULL)
			env->file = ft_strdup(s);
		else
		{
			env->file = ft_joinfree(env->file, ft_strdup("\n"));
			env->file = ft_joinfree(env->file, ft_strdup(s));
		}
	}
}

int				is_valid_graph(t_lem_in env)
{
	if (env.index_start == -1 || env.index_end == -1 || env.ants == 0 ||
			env.rooms == NULL || env.pipes == NULL)
		return (0);
	return (1);
}
