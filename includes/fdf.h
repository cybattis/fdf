/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:33:14 by cybattis          #+#    #+#             */
/*   Updated: 2022/01/17 00:39:31 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

# define WIN_W		960
# define WIN_H		540

# ifdef __linux__
#  define KEY_Q		0x71
#  define KEY_ESC	0xff1b
# else
#  define KEY_Q		12
#  define KEY_ESC	53
# endif

# define WHITE		0x00FFFFFF

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_frame {
	void	*img;
	char	*addr;
	int		bits_pp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_frame;

/* main.c */
void	init_frame(t_vars *vars, t_frame *frame);

t_vec3	**parsing_map(int argc, char **argv, int size);
int		get_matrix_size(char *path);

/* draw.c */
void	draw_frame(t_vars *vars, t_frame *frame, t_vec3 **map, int size);
void	draw_map(t_frame *frame, t_vec3 **map, int size);
void	mlx_pixel_put_img(t_frame *frame, int x, int y, int color);
void	clear_screen(t_frame *frame, int color);

/* draw_line.c */
void	draw_line(t_frame *frame, t_vec2 p1, t_vec2 p2, int color);

/* draw_circle.c */
void	draw_circle(t_frame *frame, t_vec3 origin, int r, int color);

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
void	ft_ferror(int fd);
void	free_matrix(t_vec3 **map, size_t i);
void	ft_print_map(t_vec3 **matrix, int size);

/* ++++++++++ cheat_func ++++++++++ */
void	print_vec2(t_vec2 v);
void	print_vec3(t_vec3 v);

#endif
