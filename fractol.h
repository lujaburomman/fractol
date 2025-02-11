#ifndef FRACTOL_H
#define FRACTOL_H

#include <mlx.h>
#include "./libft/includes/libft.h"
#include <X11/keysym.h>

typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
    double  zoom;
    double  offset_x;
    double  offset_y;
    int     fractal_type;
    int     mouse_x;
    int     mouse_y;
    double  julia_cr;
    double  julia_ci; 
}   t_data;

#define MANDELBROT 1
#define JULIA 2

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 100
//main
int ft_error(const char *msg);
//fractol
int render_frame(t_data *data);
//hook
int key_handler(int keycode, t_data *data);
int close_window(t_data *data);
int mouse_handler(int button, int x, int y, t_data *data);
int mouse_move(int x, int y, t_data *data);

#endif