/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 22:43:19 by edinguim          #+#    #+#             */
/*   Updated: 2018/12/07 11:40:12 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_pipes				*new_pipe(char *line)
{
	t_pipes			*pipe;

	if (!(pipe = (t_pipes*)malloc(sizeof(t_pipes))))
		return (NULL);
	pipe->room_1 = ft_strsub(line, 0, ft_strclen(line, 45));
	pipe->room_2 = ft_strsub(line, ft_strclen(line, 45) + 1, ft_strlen(line));
	pipe->next = NULL;
	return (pipe);
}

void				pipe_append(t_pipes *head, t_pipes *new)
{
	while (head->next)
		head = head->next;
	head->next = new;
}
