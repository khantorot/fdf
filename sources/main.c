/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 05:15:30 by glychest          #+#    #+#             */
/*   Updated: 2020/01/30 17:49:32 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_data		*data;
	t_map		*map;
	t_val		*val;
	int			fd;

	if (argc != 2)
		ft_error("Usage: ./fdf [File]");
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("Could not open file");
	map = init_map();
	if (read_map(fd, &val, map) == -1)
		ft_error("Reading error");
	data = data_init(map);
	fill_map(&val, map);
	data->camera = camera_init(data);
	draw(data->map, data);
	setup_controls(data);
	mlx_loop(data->mlx);
	return (0);
}
