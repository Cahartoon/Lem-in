/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 00:34:20 by edinguim          #+#    #+#             */
/*   Updated: 2018/10/24 04:04:52 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void				free_links(t_links **links)
{
	t_links			*tmp;

	if (links)
	{
		while (*links)
		{
			tmp = (*links)->next;
			free(*links);
			*links = tmp;
		}
		links = NULL;
	}
}

void				free_pipes(t_pipes **pipes)
{
	t_pipes			*tmp;

	if (pipes)
	{
		while (*pipes)
		{
			tmp = (*pipes)->next;
			ft_strdel(&((*pipes)->room_1));
			ft_strdel(&((*pipes)->room_2));
			free(*pipes);
			*pipes = tmp;
		}
		*pipes = NULL;
	}
}

void				free_rooms(t_rooms **rooms)
{
	t_rooms			*tmp;

	if (rooms)
	{
		while (*rooms)
		{
			tmp = (*rooms)->next;
			ft_strdel(&(*rooms)->name);
			free_links(&(*rooms)->link);
			free(*rooms);
			*rooms = tmp;
		}
		*rooms = NULL;
	}
}

void				free_graph(t_rooms ***graph)
{
	t_rooms			**tmp;
	t_rooms			**head;

	head = *graph;
	while (*graph && **graph)
	{
		tmp = (*graph) + 1;
		ft_strdel(&(**graph)->name);
		free_links(&(**graph)->link);
		(**graph)->next = NULL;
		free(**graph);
		**graph = NULL;
		*graph = tmp;
	}
	free(head);
	*graph = NULL;
}

int					free_env(t_lem_in **e)
{
	if (*e)
	{
		if ((*e)->rooms)
			free_rooms(&((*e)->rooms));
		if ((*e)->pipes)
			free_pipes(&((*e)->pipes));
		if ((*e)->graph)
			free_graph(&((*e)->graph));
		if ((*e)->path)
			free_path(&((*e)->path));
		ft_strdel(&((*e)->file));
		free(*e);
	}
	*e = NULL;
	return (1);
}
