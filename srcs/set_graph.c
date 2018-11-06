/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_graph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 19:18:14 by edinguim          #+#    #+#             */
/*   Updated: 2018/10/24 03:59:19 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			set_graph(t_lem_in *e)
{
	int		i;

	i = 0;
	if (!(e->graph = (t_rooms**)malloc(sizeof(t_rooms*) * (e->nb_rooms + 1))))
		return ;
	while (e->rooms)
	{
		e->graph[i] = e->rooms;
		i++;
		e->rooms = e->rooms->next;
	}
	e->graph[i] = NULL;
}
