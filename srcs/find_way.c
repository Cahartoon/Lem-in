/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:24:51 by edinguim          #+#    #+#             */
/*   Updated: 2018/10/24 03:58:50 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		nb_exit(t_lem_in *e)
{
	t_links		*link;
	int			i;

	i = 0;
	link = e->graph[e->index_start]->link;
	while (link)
	{
		if (e->graph[link->index]->path || link->index == e->index_end)
			i++;
		link = link->next;
	}
	return (i);
}

static int		find_shortest(t_lem_in *e)
{
	int			res;
	t_links		*link;

	res = INT_MAX;
	link = e->graph[e->index_start]->link;
	while (link)
	{
		if ((e->graph[link->index]->path &&
				e->graph[link->index]->lock == 0 &&
				e->graph[link->index]->path < res) ||
				link->index == e->index_end)
			res = e->graph[link->index]->path;
		link = link->next;
	}
	return (res);
}

static int		find_next_room(t_lem_in *e, int index)
{
	int			res;
	int			count;
	t_links		*link;

	res = 0;
	count = INT_MAX;
	link = e->graph[index]->link;
	while (link)
	{
		if ((e->graph[link->index]->path && !e->graph[link->index]->lock &&
				e->graph[link->index]->path < count &&
				link->index != e->index_start) || link->index == e->index_end)
		{
			count = e->graph[link->index]->path;
			res = link->index;
		}
		link = link->next;
	}
	e->graph[res]->lock = 1;
	return (res);
}

static t_rooms	**fill_way(t_lem_in *e)
{
	int			shortest;
	int			i;
	int			index;
	t_rooms		**way;

	i = 0;
	shortest = find_shortest(e);
	index = e->index_start;
	if (!(way = (t_rooms**)malloc(sizeof(t_rooms*) * (shortest + 2))))
		return (NULL);
	while (i < shortest + 1)
	{
		index = find_next_room(e, index);
		way[i] = e->graph[index];
		i++;
	}
	way[i] = NULL;
	return (way);
}

t_rooms			***find_way(t_lem_in *e)
{
	int			i;
	int			way;
	t_rooms		***path;

	i = 0;
	way = nb_exit(e);
	if (!(path = (t_rooms***)malloc(sizeof(t_rooms**) * (way + 1))))
		return (NULL);
	while (i < way)
	{
		path[i] = fill_way(e);
		i++;
	}
	path[i] = NULL;
	return (path);
}
