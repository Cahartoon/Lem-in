/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 23:47:09 by edinguim          #+#    #+#             */
/*   Updated: 2018/10/24 04:04:55 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			path_size(t_lem_in *e)
{
	int		i;

	i = 0;
	while (e->path[i])
		i++;
	return (i);
}

int			find_x(char *line)
{
	char	*s;

	s = line;
	while (*s != ' ')
		s++;
	while (*s == ' ')
		s++;
	return (ft_atoi(s));
}

int			find_y(char *line)
{
	char	*s;

	s = line;
	while (*s != ' ')
		s++;
	while (*s == ' ')
		s++;
	while (*s != ' ')
		s++;
	return (ft_atoi(s));
}

int			coord_already_exist(t_lem_in e, char *s)
{
	int		x;
	int		y;

	x = find_x(s);
	y = find_y(s);
	while (e.rooms)
	{
		if (e.rooms->x == x && e.rooms->y == y)
			return (1);
		e.rooms = e.rooms->next;
	}
	return (0);
}

void		free_path(t_rooms ****path)
{
	t_rooms	***tmp;
	t_rooms	***head;

	head = *path;
	while (*path && **path)
	{
		tmp = (*path) + 1;
		free(**path);
		**path = NULL;
		*path = tmp;
	}
	free(head);
	*path = NULL;
}
