/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:33:14 by cybattis          #+#    #+#             */
/*   Updated: 2022/01/13 12:54:42 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>

# define WIN_W		960
# define WIN_H		540

# define KEY_Q		12
# define KEY_ESC	53

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_frame {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_frame;

void	init_frame(t_vars *vars, t_frame *frame);

/* draw.c */
void	my_mlx_pixel_put(t_frame *data, int x, int y, int color);
void	clear_screen(t_frame *frame, int color);

/* hooks.c.c */
int		key_hook(int keycode, t_vars *vars);
int		close_win(t_vars *vars);

/* colors.c */
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

/* colors2.c */
int		get_opposite(int trgb);
int		add_shade(double distance, int trgb);

/* utils.c */
int		print_color(int trgb);

#endif
