/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 23:54:36 by edinguim          #+#    #+#             */
/*   Updated: 2018/10/24 03:45:09 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		find_index(char *name, t_lem_in env)
{
	int			i;

	i = 0;
	while (i < env.nb_rooms)
	{
		if (!(ft_strcmp(name, env.graph[i]->name)))
			return (i);
		i++;
	}
	return (-1);
}

static t_links	*ft_new_link(int index)
{
	t_links		*new;

	if (!(new = (t_links*)malloc(sizeof(t_links))))
		return (NULL);
	new->index = index;
	new->next = NULL;
	return (new);
}

static void		ft_link_append(t_links *head, t_links *new)
{
	while (head->next)
		head = head->next;
	head->next = new;
}

static void		add_links(t_rooms *room, t_lem_in env)
{
	while (env.pipes)
	{
		if (!ft_strcmp(room->name, env.pipes->room_1))
		{
			if (room->link == NULL)
				room->link = ft_new_link(find_index(env.pipes->room_2, env));
			else
				ft_link_append(room->link,
						ft_new_link(find_index(env.pipes->room_2, env)));
		}
		if (!ft_strcmp(room->name, env.pipes->room_2))
		{
			if (room->link == NULL)
				room->link = ft_new_link(find_index(env.pipes->room_1, env));
			else
				ft_link_append(room->link,
						ft_new_link(find_index(env.pipes->room_1, env)));
		}
		env.pipes = env.pipes->next;
	}
}

void			init_links(t_lem_in env)
{
	int			i;

	i = 0;
	while (i < env.nb_rooms)
		add_links(env.graph[i++], env);
}
