/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 04:32:19 by edinguim          #+#    #+#             */
/*   Updated: 2018/10/24 05:00:06 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			is_valid_pipe(t_lem_in e, char *s)
{
	int			i;
	int			j;
	char		*room_1;
	char		*room_2;

	i = 0;
	j = 0;
	room_1 = ft_strsub(s, 0, ft_strclen(s, 45));
	room_2 = ft_strsub(s, ft_strclen(s, 45) + 1, ft_strlen(s));
	while (e.rooms)
	{
		if (ft_strcmp(room_1, e.rooms->name) == 0)
			i = 1;
		if (ft_strcmp(room_2, e.rooms->name) == 0)
			j = 1;
		e.rooms = e.rooms->next;
	}
	ft_strdel(&room_1);
	ft_strdel(&room_2);
	if (i && j)
		return (1);
	return (0);
}

int			pipe_same_room(char *s)
{
	char		*room_1;
	char		*room_2;
	int			i;

	room_1 = ft_strsub(s, 0, ft_strclen(s, 45));
	room_2 = ft_strsub(s, ft_strclen(s, 45) + 1, ft_strlen(s));
	if (ft_strcmp(room_1, room_2) == 0)
		i = 1;
	else
		i = 0;
	ft_strdel(&room_1);
	ft_strdel(&room_2);
	return (i);
}
