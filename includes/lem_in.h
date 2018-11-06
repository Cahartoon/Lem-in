/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:14:53 by edinguim          #+#    #+#             */
/*   Updated: 2018/10/24 05:00:02 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# include <limits.h>

typedef struct				s_links
{
	int						index;
	struct s_links			*next;
}							t_links;

typedef struct				s_rooms
{
	char					*name;
	int						is_start;
	int						is_end;
	int						ants;
	int						path;
	int						index;
	int						lock;
	int						x;
	int						y;
	t_links					*link;
	struct s_rooms			*next;
}							t_rooms;

typedef struct				s_pipes
{
	char					*room_1;
	char					*room_2;
	struct s_pipes			*next;
}							t_pipes;

typedef struct				s_lem_in
{
	int						ants;
	t_rooms					*rooms;
	t_rooms					**graph;
	t_rooms					***path;
	t_pipes					*pipes;
	int						nb_rooms;
	int						index_start;
	int						index_end;
	char					*file;
}							t_lem_in;

t_lem_in					*parse(void);
int							is_ant(char *s);
int							is_room(char *s);
int							is_pipe(char *s);
int							is_start_or_end(char *s);
int							is_comment(char *s);
int							is_command(char *s);
int							is_valid_line(t_lem_in e, char *s);
int							is_valid_pipe(t_lem_in e, char *s);
int							pipe_same_room(char *s);
int							is_valid_graph(t_lem_in e);
int							is_valid_tab(t_lem_in *e);
int							is_valid_path(t_lem_in *e);
int							find_x(char *s);
int							find_y(char *s);
int							coord_already_exist(t_lem_in e, char *s);
t_rooms						*new_room(t_lem_in *e, char *s, int index);
void						room_append(t_rooms *head, t_rooms *new_room);
t_pipes						*new_pipe(char *s);
void						pipe_append(t_pipes *head, t_pipes *new_pipe);
void						add_room(t_lem_in *e, char *s, int index);
void						add_pipe(t_lem_in *e, char *s);
void						add_s_e(t_lem_in *e, int i, int index);
void						add_valid_line(t_lem_in *e, char *s);
void						init_links(t_lem_in e);
void						b_f_s(t_lem_in e, t_links *link, int i, int p);
void						set_graph(t_lem_in *e);
t_rooms						***find_way(t_lem_in *e);
int							valid_path(t_lem_in *e);
int							way_size(t_rooms **path);
int							path_size(t_lem_in *e);
int							last_path(t_lem_in *e);
void						lets_go(t_lem_in *e);
int							free_env(t_lem_in **e);
void						free_path(t_rooms ****path);

#endif
