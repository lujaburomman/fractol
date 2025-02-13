/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <laburomm@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:04:09 by laburomm          #+#    #+#             */
/*   Updated: 2025/02/13 08:54:40 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_data *data)
{
	if (data->mlx)
	{
		if (data->img)
		{
			mlx_destroy_image(data->mlx, data->img);
		}
		if (data->win)
		{
			mlx_destroy_window(data->mlx, data->win);
		}
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
}

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		closeproject(data, 1);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractol");
	if (!data->win)
		closeproject(data, 2);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		closeproject(data, 3);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len,
			&data->endian);
	if (!data->addr)
		closeproject(data, 4);
	data->zoom = 0.004;
	data->offset_x = -0.5;
	data->offset_y = 0;
	data->iter = 42;
	return (1);
}

int	parse_args(int argc, char *argv[], t_data *data)
{
	size_t m = 10;
	size_t j = 5;
	if (argc < 2)
		return (ft_error("Usage: ./fractol [mandelbrot] or [julia cr ci]"));
	if (argc == 2 && (ft_strlen(argv[1]) == m) && !ft_strncmp(argv[1], "mandelbrot", 10))
		data->fractal_type = MANDELBROT;
	else if (argc == 4 && (ft_strlen(argv[1]) == j) && !ft_strncmp(argv[1], "julia", 5))
	{
		if (argc != 4)
			return (ft_error("Usage: ./fractol julia cr ci"));
		data->fractal_type = JULIA;
		data->julia_cr = ft_atof(argv[2]);
		data->julia_ci = ft_atof(argv[3]);
	}
	else
	{
		ft_error("Invalid fractal type");
		exit (1);
	}
	return (1);
}
