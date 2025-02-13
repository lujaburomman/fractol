/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <laburomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:04:04 by laburomm          #+#    #+#             */
/*   Updated: 2025/02/12 13:10:52 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	closeproject(t_data *data, int i)
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
	if (i == 1)
		ft_printf("MLX initialization failed: mlx_init failed\n");
	else if (i == 2)
		ft_printf("MLX initialization failed: mlx_new_window failed\n");
	else if (i == 3)
		ft_printf("MLX initialization failed: mlx_new_image failed\n");
	else if (i == 4)
		ft_printf("MLX initialization failed: mlx_get_data_addr failed\n");
	exit(1);
}

int	ft_error(const char *msg)
{
	ft_printf("Error : %s.\n", msg);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 1)
	{
		ft_printf("Usage: ./fractol [mandelbrot] or [julia cr ci]\n");
		exit(1);
	}
	if (!parse_args(argc, argv, &data) || !init_mlx(&data))
		return (1);
	setup_hooks(&data);
	mlx_loop(data.mlx);
	closeproject(&data, 1);
	return (0);
}
