/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 22:10:05 by glychest          #+#    #+#             */
/*   Updated: 2020/02/29 18:31:31 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map			*init_map(void)
{
	t_map	*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		ft_error("Map initialization error");
	map->width = 0;
	map->height = 0;
	map->position = NULL;
	map->colors = NULL;
	map->z_min = 0;
	map->z_max = 0;
	map->range = 0;
	return (map);
}

static void		push(t_val **val, t_val *new)
{
	if (val)
	{
		if (new)
			new->next = *val;
		*val = new;
	}
}

static t_val	*new_val(char *line)
{
	t_val	*val;
	char	**pieces;

	if (!(val = (t_val *)ft_memalloc(sizeof(t_val))))
		ft_error("Reading error");
	if (!(pieces = ft_strsplit(line, ',')))
		ft_error("Reading error");
	if (!(ft_isnumber(pieces[0], 10)))
		ft_error("Reading error");
	if (pieces[1] && !(ft_isnumber(pieces[1], 16)))
		ft_error("Reading error");
	val->z = ft_atoi(pieces[0]);
	val->color = pieces[1] ? ft_atoi_base(pieces[1], 16) : -1;
	val->next = NULL;
	ft_free_arr(pieces);
	return (val);
}

static void		create_val(char **line, t_val **val, t_map *map)
{
	int		i;

	i = 0;
	while (*line)
	{
		push(val, new_val(*(line++)));
		i++;
	}
	if (map->height == 0)
		map->width = i;
	else if (map->width != i)
		ft_error("Incorrect MAP_FILE");
}

int				read_map(int fd, t_val **val, t_map *map)
{
	char	*str;
	char	**line;
	int		res;

	while ((res = get_next_line(fd, &str)) == 1)
	{
		if (!(line = ft_strsplit(str, ' ')))
			ft_error("Reading error");
		create_val(line, val, map);
		ft_free_arr(line);
		ft_strdel(&str);
		map->height++;
	}
	if (!(*val))
		ft_error("Incorrect MAP_FILE");
	return (res);
}
