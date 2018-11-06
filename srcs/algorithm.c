/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 23:19:05 by edinguim          #+#    #+#             */
/*   Updated: 2018/10/24 03:44:42 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		b_f_s(t_lem_in e, t_links *link, int i, int p)
{
	if (i < e.nb_rooms && !e.graph[i]->is_start && link)
	{
		if (!e.graph[link->index]->path ||
				p < e.graph[link->index]->path)
		{
			e.graph[link->index]->path = p + 1;
			b_f_s(e, e.graph[link->index]->link,
					e.graph[link->index]->index, p + 1);
		}
		b_f_s(e, link->next, i, p);
	}
}
