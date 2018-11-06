/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 19:09:08 by edinguim          #+#    #+#             */
/*   Updated: 2018/10/24 05:00:37 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				is_comment(char *s)
{
	if (*s && *s == '#')
	{
		s++;
		if ((*s && *s != '#') || !*s)
			return (1);
	}
	return (0);
}

int				pipe_already_exist(t_lem_in env, char *s)
{
	char		*room_1;
	char		*room_2;

	room_1 = ft_strsub(s, 0, ft_strclen(s, 45));
	room_2 = ft_strsub(s, ft_strclen(s, 45) + 1, ft_strlen(s));
	while (env.pipes)
	{
		if ((ft_strcmp(room_1, env.pipes->room_1) == 0 &&
					ft_strcmp(room_2, env.pipes->room_2) == 0) ||
				(ft_strcmp(room_1, env.pipes->room_2) == 0 &&
				ft_strcmp(room_2, env.pipes->room_1) == 0))
			return (1);
		env.pipes = env.pipes->next;
	}
	ft_strdel(&room_1);
	ft_strdel(&room_2);
	return (0);
}

int				room_already_exist(t_lem_in env, char *s)
{
	char		*room;

	room = ft_strsub(s, 0, ft_strclen(s, 32));
	while (env.rooms)
	{
		if (ft_strcmp(room, env.rooms->name) == 0)
			return (1);
		env.rooms = env.rooms->next;
	}
	ft_strdel(&room);
	return (0);
}

int				is_command(char *s)
{
	if (*s && *s == '#' && *(s + 1) && *(s + 1) == '#')
		return (1);
	return (0);
}

int				is_valid_line(t_lem_in env, char *s)
{
	if (((is_room(s) || is_pipe(s)) && env.ants == 0) ||
			(is_ant(s) && env.ants != 0) ||
			(is_ant(s) && ft_atoi(s) <= 0) ||
			(is_pipe(s) && env.rooms == NULL) ||
			(is_room(s) && env.pipes != NULL) ||
			(is_room(s) && coord_already_exist(env, s)) ||
			(is_pipe(s) && !is_valid_pipe(env, s)) ||
			(is_pipe(s) && pipe_same_room(s)) ||
			(is_pipe(s) && pipe_already_exist(env, s)) ||
			(is_room(s) && room_already_exist(env, s)) ||
			(is_start_or_end(s) == 1 && env.index_start != -1) ||
			(is_start_or_end(s) == 2 && env.index_end != -1) ||
			(ft_strcmp(s, "") == 0) ||
			(!is_comment(s) && !is_room(s) && !is_pipe(s) && !is_command(s) &&
			!is_ant(s)))
		return (0);
	return (1);
}
