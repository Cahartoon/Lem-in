/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:20:01 by edinguim          #+#    #+#             */
/*   Updated: 2018/10/24 03:57:10 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		error(t_lem_in *e)
{
	free_env(&e);
	ft_putendl("ERROR");
	return (1);
}

static int		print_file(t_lem_in *e)
{
	ft_putendl(e->file);
	return (1);
}

int				main(void)
{
	t_lem_in		*e;
	int				i;

	i = 0;
	e = parse();
	if (e->rooms && e->index_start == e->index_end &&
			print_file(e) && free_env(&e))
		return (0);
	if (!is_valid_graph(*e) && error(e))
		return (0);
	set_graph(e);
	init_links(*e);
	if (!is_valid_tab(e) && error(e))
		return (0);
	b_f_s(*e, e->graph[e->index_end]->link, e->index_end, 0);
	e->graph[e->index_end]->path = 0;
	e->path = find_way(e);
	if (!is_valid_path(e) && error(e))
		return (0);
	ft_printf("%s\n\n", e->file);
	lets_go(e);
	free_env(&e);
	return (0);
}
