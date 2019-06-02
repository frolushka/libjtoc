/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libjtoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:28:19 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/02 20:48:17 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBJTOC_H
# define LIBJTOC_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

# define FUNCTION_SUCCESS	0
# define FUNCTION_FAILURE	-1

# define BUF_SIZE			(1 << 16)

# define F_RIGHT			(1 << 0)
# define F_ONLY_SPACES		(1 << 1)

enum						e_type
{
	none,
	number,
	string,
	object,
	array
};

typedef struct				s_jnode
{
	enum e_type				type;
	int						hash;
	void					*data;
	struct s_jnode			*right;
	struct s_jnode			*down;
}							t_jnode;

t_jnode						*jtoc_node_create(enum e_type type, char *name,
void *data);

void						jtoc_node_add_child(t_jnode *parent,
t_jnode *child);

t_jnode						*jtoc_node_get_by_path(t_jnode *root,
const char *path);

void						jtoc_node_clear(t_jnode *parent);

int							jtoc_remove_spaces(char **str);

int							jtoc_find(const char *str, const char s, int i,
int d);
int							jtoc_find_comma(const char *str, int i);

int							jtoc_read_file(const char *path, char **res);

int							jtoc_validate(const char *str);

int							jtoc_validate_field(const char *str, int b,
int e);

int							jtoc_validate_value(const char *str, int c,
int e);

int							jtoc_validate_number(const char *str, int b,
int e);
int							jtoc_validate_string(const char *str, int b,
int e);
int							jtoc_validate_object(const char *str, int b,
int e);
int							jtoc_validate_array(const char *str, int b,
int e);

t_jnode						*jtoc_parse(const char *str);

enum e_type					jtoc_get_field_type(const char f);

int							jtoc_parse_field(t_jnode *p, const char *str,
int b, int e);

int							jtoc_parse_value(t_jnode *p, const char *str,
int b, int e);

int							jtoc_parse_number(t_jnode *p, const char *str,
int b, int e);
int							jtoc_parse_string(t_jnode *p, const char *str,
int b, int e);
int							jtoc_parse_object(t_jnode *p, const char *str,
int b, int e);
int							jtoc_parse_array(t_jnode *p, const char *str,
int b, int e);

t_jnode						*jtoc_read(const char *str);

#endif
