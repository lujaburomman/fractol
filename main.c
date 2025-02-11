#include "fractol.h"

int ft_error(const char *msg)
{
    ft_putstr_fd("Error: ", 2);
    ft_putstr_fd(msg, 2);
    ft_putstr_fd("\n", 2);
    return (1);
}

int main(int argc, char *argv[])
{
    t_data data;

    if (!init_mlx(&data)
        || !parse_args(argc, argv, &data))
        return (1);
    setup_hooks(&data);
    mlx_loop(data.mlx);
    return (0);
}
