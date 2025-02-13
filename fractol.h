/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laburomm <laburomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:03:35 by laburomm          #+#    #+#             */
/*   Updated: 2025/02/12 13:03:45 by laburomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/includes/libft.h"
# include <X11/keysym.h>
# include <mlx.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		fractal_type;
	int		mouse_x;
	int		mouse_y;
	double	julia_cr;
	double	julia_ci;
	int		iter;
}			t_data;

# define MANDELBROT 1
# define JULIA 2

# define WIDTH 800
# define HEIGHT 800
//efine MAX_ITER 100
//main
int			ft_error(const char *msg);
void		closeproject(t_data *data, int i);
//fractol
int			render_frame(t_data *data);
int			calculate_fractal(double zr, double zi, t_data *data);
void		set_pixels(t_data *data, int x, int y, int color);
//hook
void		setup_hooks(t_data *data);
int			key_handler(int keycode, t_data *data);
int			close_window(t_data *data);
int			mouse_handler(int button, int x, int y, t_data *data);
int			mouse_move(int x, int y, t_data *data);
//initial_parse
int			init_mlx(t_data *data);
int			parse_args(int argc, char *argv[], t_data *data);
double		ft_atof(const char *str);

#endif
