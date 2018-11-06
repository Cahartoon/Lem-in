/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 20:46:20 by edinguim          #+#    #+#             */
/*   Updated: 2018/10/24 03:45:23 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void			init_room(t_rooms *room, int index, char *line)
{
	if (room)
	{
		room->index = index;
		room->path = 0;
		room->lock = 0;
		room->x = find_x(line);
		room->y = find_y(line);
		room->link = NULL;
		room->next = NULL;
	}
}

t_rooms				*new_room(t_lem_in *env, char *line, int index)
{
	t_rooms			*room;

	if (!(room = (t_rooms*)malloc(sizeof(t_rooms))))
		return (NULL);
	room->name = ft_strsub(line, 0, ft_strclen(line, 32));
	if (env->index_start == index)
	{
		room->is_start = 1;
		room->ants = env->ants;
	}
	else
	{
		room->is_start = 0;
		room->ants = 0;
	}
	if (env->index_end == index)
		room->is_end = 1;
	else
		room->is_end = 0;
	init_room(room, index, line);
	return (room);
}

void				room_append(t_rooms *rooms, t_rooms *new)
{
	while (rooms->next)
		rooms = rooms->next;
	rooms->next = new;
}
