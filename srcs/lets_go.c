/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_go.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:19:33 by edinguim          #+#    #+#             */
/*   Updated: 2018/10/24 03:45:30 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		still_ant(t_rooms ***path)
{
	int			i;
	int			j;

	i = 0;
	while (path[i])
	{
		j = 0;
		while (j < way_size(path[i]) - 1)
		{
			if (path[i][j]->ants != 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void		avancez_feignasses(t_lem_in *e, t_rooms **path)
{
	int			i;
	int			ant;

	i = way_size(path) - 1;
	while (i >= 0)
	{
		ant = 0;
		if (path[i]->ants == 0 || path[i]->index == e->index_end)
		{
			if (i == 0 && e->graph[e->index_start]->ants != 0)
			{
				ant = e->ants - e->graph[e->index_start]->ants + 1;
				e->graph[e->index_start]->ants--;
			}
			else if (i != 0)
			{
				ant = path[i - 1]->ants;
				path[i - 1]->ants = 0;
			}
			path[i]->ants = ant;
			if (ant)
				ft_printf("L%i-%s ", ant, path[i]->name);
		}
		i--;
	}
}

static void		cassez_vous(t_lem_in *e, t_rooms **path)
{
	int			i;
	int			ant;

	i = way_size(path) - 1;
	while (i > 0)
	{
		ant = 0;
		if (path[i]->ants == 0 || path[i]->index == e->index_end)
		{
			ant = path[i - 1]->ants;
			path[i - 1]->ants = 0;
			path[i]->ants = ant;
			if (ant)
				ft_printf("L%i-%s ", ant, path[i]->name);
		}
		i--;
	}
}

static void		move(t_lem_in *e)
{
	int			i;
	int			last;

	i = path_size(e) - 1;
	last = last_path(e);
	while (i >= 0)
	{
		if (e->path[i][way_size(e->path[i]) - 1]->index == e->index_end)
		{
			if (way_size(e->path[i]) <= e->graph[e->index_start]->ants)
				avancez_feignasses(e, e->path[i]);
			else if (i == last && e->graph[e->index_start]->ants)
				avancez_feignasses(e, e->path[i]);
			else
				cassez_vous(e, e->path[i]);
		}
		i--;
	}
	ft_putendl("");
}

void			lets_go(t_lem_in *e)
{
	while (e->graph[e->index_start]->ants || still_ant(e->path))
		move(e);
}
