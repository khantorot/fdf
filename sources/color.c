/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 13:58:05 by glychest          #+#    #+#             */
/*   Updated: 2020/01/30 18:04:26 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int				get_color(t_dot current, t_dot start, t_dot end, t_dot delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF,
					(end.color >> 16) & 0xFF,
					percentage);
	green = get_light((start.color >> 8) & 0xFF,
					(end.color >> 8) & 0xFF,
					percentage);
	blue = get_light(start.color & 0xFF,
					end.color & 0xFF,
					percentage);
	return ((red << 16) | (green << 8) | blue);
}

int				get_default_color(int z, t_map *map)
{
	double	percentage;

	percentage = percent(map->z_min, map->z_max, z);
	if (percentage < 0.2)
		return (COLOR_1);
	else if (percentage < 0.4)
		return (COLOR_2);
	else if (percentage < 0.6)
		return (COLOR_3);
	else if (percentage < 0.8)
		return (COLOR_4);
	else
		return (COLOR_5);
}
