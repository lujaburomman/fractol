/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <laburomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:03:54 by laburomm          #+#    #+#             */
/*   Updated: 2025/02/13 09:16:15 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int	calculate_fractal(double zr, double zi, t_data *data)
{
	double	cr;
	double	ci;
	double	tmp;
	int		it;

	it = 0;
	cr = data->julia_cr;
	ci = data->julia_ci;
	if (data->fractal_type == MANDELBROT)
	{
		cr = zr;
		ci = zi;
		zr = 0;
		zi = 0;
	}
	while (it < data->iter)
	{
		if (zr * zr + zi * zi > 4.0)
			break ;
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		it++;
	}
	return (it);
}

void	set_pixels(t_data *data, int x, int y, int color)
{
	char	*dest;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dest = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int *)dest = color;
	}
}

int	render_frame(t_data *data)
{
	int		x;
	int		y;
	int		iter;
	double	cr;
	double	ci;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cr = (x - WIDTH / 2.0) * data->zoom + data->offset_x;
			ci = (y - HEIGHT / 2.0) * data->zoom + data->offset_y;
			iter = calculate_fractal(cr, ci, data);
			set_pixels(data, x, y, iter * 0xFFFFFF / data->iter);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
