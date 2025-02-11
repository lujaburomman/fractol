#include "fractol.h"

double ft_atof(const char *str)
{
    double result;
    double fraction;
    int sign;

    result = 0.0;
    fraction = 1.0;
    sign = 1;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
        sign = (*str++ == '-') ? -1 : 1;
    while (*str >= '0' && *str <= '9')
        result = result * 10.0 + (*str++ - '0');
    if (*str == '.')
    {
        str++;
        while (*str >= '0' && *str <= '9')
        {
            fraction *= 0.1;
            result += (*str++ - '0') * fraction;
        }
    }
    return (result * sign);
}

int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
}

int init_mlx(t_data *data)
{
    data->mlx = mlx_init();
    if (!data->mlx)
        return (ft_error("MLX initialization failed"));
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractol");
    if (!data->win)
        return (ft_error("Window creation failed"));
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    if (!data->img)
        return (ft_error("Image creation failed"));
    data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, &data->endian);
    if (!data->addr)
    return (ft_error("Image address retrieval failed"));
    data->zoom = 0.004;
    data->offset_x = -0.5;
    data->offset_y = 0;
    return (1);
}

int parse_args(int argc, char *argv[], t_data *data)
{
    if (argc < 2)
        return (ft_error("Usage: ./fractol [mandelbrot | julia cr ci]"));

    if (!ft_strcmp(argv[1], "mandelbrot"))
        data->fractal_type = MANDELBROT;
    else if (!ft_strcmp(argv[1], "julia"))
    {
        if (argc != 4)
            return (ft_error("Usage: ./fractol julia cr ci"));
        data->fractal_type = JULIA;
        data->julia_cr = ft_atof(argv[2]);
        data->julia_ci = ft_atof(argv[3]);
    }
    else
        return (ft_error("Invalid fractal type"));
    return (1);
}