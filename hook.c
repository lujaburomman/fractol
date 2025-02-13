/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <laburomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:03:24 by laburomm          #+#    #+#             */
/*   Updated: 2025/02/12 13:08:06 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	mouse_handler(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4)
		data->zoom *= 0.9;
	else if (button == 5)
		data->zoom *= 1.1;
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	data->mouse_x = x;
	data->mouse_y = y;
	if (data->fractal_type == JULIA)
	{
		data->julia_cr = (x - WIDTH / 2.0) * data->zoom + data->offset_x;
		data->julia_ci = (y - HEIGHT / 2.0) * data->zoom + data->offset_y;
		render_frame(data);
	}
	return (0);
}

int	key_handler(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		close_window(data);
	}
	else if (keycode == XK_equal || keycode == XK_plus || keycode == XK_KP_Add)
		data->iter += 10;
	else if (keycode == XK_minus || keycode == XK_KP_Subtract)
		data->iter -= 10;
	else if (keycode == XK_Left)
		data->offset_x -= 0.01;
	else if (keycode == XK_Right)
		data->offset_x += 0.01;
	else if (keycode == XK_Up)
		data->offset_y -= 0.01;
	else if (keycode == XK_Down)
		data->offset_y += 0.01;
	render_frame(data);
	return (0);
}

void	setup_hooks(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_handler, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_hook(data->win, 4, 1L << 2, mouse_handler, data);
	mlx_hook(data->win, 6, 1L << 6, mouse_move, data);
	mlx_loop_hook(data->mlx, render_frame, data);
}
