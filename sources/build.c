/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 12:40:53 by glychest          #+#    #+#             */
/*   Updated: 2020/01/30 12:27:25 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data		*data_init(t_map *map)
{
	t_data	*data;

	if (!(data = (t_data *)ft_memalloc(sizeof(t_data))))
		ft_error("FDF initialization error");
	if (!(data->mlx = mlx_init()))
		ft_error("FDF initialization error");
	if (!(data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FDF")))
		ft_error("FDF initialization error");
	if (!(data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT)))
		ft_error("FDF initialization error");
	data->data_addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel),
										&(data->line_size), &(data->endian));
	data->map = map;
	return (data);
}

void		fill_map(t_val **val, t_map *map)
{
	t_val		*tmp;
	size_t		i;
	size_t		area;

	area = map->width * map->height * sizeof(int);
	if (!(map->position = (int *)ft_memalloc(area)))
		ft_error("Conversion to array");
	if (!(map->colors = (int *)ft_memalloc(area)))
		ft_error("Conversion to array");
	i = map->width * map->height - 1;
	while ((tmp = pop(val)))
	{
		map->position[i] = tmp->z;
		map->colors[i] = tmp->color;
		if (tmp->z > map->z_max)
			map->z_max = tmp->z;
		if (tmp->z < map->z_min)
			map->z_min = tmp->z;
		i--;
		free(tmp);
	}
	map->range = map->z_max - map->z_min;
}

t_val		*pop(t_val **val)
{
	t_val *top;

	top = NULL;
	if (val && *val)
	{
		top = *val;
		*val = (*val)->next;
	}
	return (top);
}

t_dot		project(t_dot dot, t_data *data)
{
	dot.x *= data->camera->zoom;
	dot.y *= data->camera->zoom;
	dot.z *= data->camera->zoom / data->camera->z_divisor;
	dot.x -= (data->map->width * data->camera->zoom) / 2;
	dot.y -= (data->map->height * data->camera->zoom) / 2;
	rotate_x(&dot.y, &dot.z, data->camera->alpha);
	rotate_y(&dot.x, &dot.z, data->camera->beta);
	rotate_z(&dot.x, &dot.y, data->camera->gamma);
	if (data->camera->projection == false)
		iso(&dot.x, &dot.y, dot.z);
	dot.x += WIDTH / 2 + data->camera->x_offset;
	dot.y += (HEIGHT + data->map->height * data->camera->zoom) / 2
												+ data->camera->y_offset;
	return (dot);
}

void		setup_controls(t_data *data)
{
	mlx_hook(data->win, 2, 0, key_press, data);
	mlx_hook(data->win, 17, 0, close_fdf, data);
}
