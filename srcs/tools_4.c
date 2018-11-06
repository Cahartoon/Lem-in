/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 21:55:54 by edinguim          #+#    #+#             */
/*   Updated: 2018/10/24 04:04:11 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			is_valid_path(t_lem_in *e)
{
	int		i;

	i = 0;
	while (e->path[i])
	{
		if (e->path[i][way_size(e->path[i]) - 1]->index == e->index_end)
			return (1);
		i++;
	}
	return (0);
}

int			is_valid_tab(t_lem_in *e)
{
	if (!e->graph || !e->graph[e->index_start]->link ||
			!e->graph[e->index_end]->link)
		return (0);
	return (1);
}

int			way_size(t_rooms **path)
{
	int		i;

	i = 0;
	while (path[i])
		i++;
	return (i);
}

int			valid_path(t_lem_in *e)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (e->path[i])
	{
		if (e->path[i][way_size(e->path[i]) - 1]->index == e->index_end)
			res++;
		i++;
	}
	return (res);
}

int			last_path(t_lem_in *e)
{
	int		i;
	int		res;

	res = INT_MAX;
	i = path_size(e) - 1;
	while (i >= 0)
	{
		if (e->path[i][way_size(e->path[i]) - 1]->index == e->index_end)
			if (i < res)
				res = i;
		i--;
	}
	return (res);
}
