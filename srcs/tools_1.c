/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 22:35:44 by edinguim          #+#    #+#             */
/*   Updated: 2018/10/24 03:46:02 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				is_ant(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

static int		is_coord(char *s)
{
	if (*s == '-')
		s++;
	while (*s && *s != ' ')
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	if (!*s)
		return (0);
	s++;
	if (*s == '-')
		s++;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	if (!*s)
		return (1);
	return (0);
}

int				is_room(char *s)
{
	if (*s == 'L' || *s == '#')
		return (0);
	while (*s != ' ' && *s != '-' && *s)
		s++;
	if (!*s || *s == '-')
		return (0);
	while (*s == ' ')
		s++;
	if (is_coord(s))
		return (1);
	return (0);
}

int				is_pipe(char *s)
{
	while (*s && *s != '-' && *s != ' ')
		s++;
	if (!*s || *s == ' ')
		return (0);
	s++;
	while (*s && *s != '-' && *s != ' ')
		s++;
	if (*s == '-' || *s == ' ')
		return (0);
	return (1);
}

int				is_start_or_end(char *s)
{
	if (s && ft_strcmp(s, "##start") == 0)
		return (1);
	if (s && ft_strcmp(s, "##end") == 0)
		return (2);
	return (0);
}
