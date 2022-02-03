/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:33:14 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/03 15:56:39 by cybattis         ###   ########.fr       */
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
#  define KEY_Q		0x71	// for ANSI
#  define KEY_ESC	0xff1b
# else
#  define KEY_Q		12		// for ANSI
#  define KEY_ESC	53
# endif

# define WHITE		0x00FFFFFF
# define RED		0x00FF0000
# define GREEN		0x0000FF00
# define BLUE		0x000000FF

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_vertex {
	t_vec3	v;
	int		color;
}	t_vertex;

typedef struct s_frame {
	void	*img;
	char	*addr;
	int		bits_pp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_frame;

t_vec3	*matrix_multv3(const t_vec3 *v, double **m);
double 	**matrix_multm4(double **m, double **out);

/* main.c */
void	init_frame(t_vars *vars, t_frame *frame);

/* matrix.c */
void	translation_matrix(double **m, t_vec3 translation);
void	scale_matrix(double **m, t_vec3 scale);
void	rotation_x_matrix(double **m, double angle);
void	rotation_y_matrix(double **m, double angle);
void	rotation_z_matrix(double **m, double angle);

/* map.c */
t_vec3	**init_map(char *path, int size);
void	update_map(t_vec3 **map, int size);
void	map_offset(t_vec3 **map, int size);

/* parsing.c */
t_vec3	**map_parsing(char *path, int size);
int		get_matrix_size(int argc, char *path);

/* draw.c */
void	draw_frame(t_vars *vars, t_frame *frame, t_vec3 **map, int size);
void	draw_map(t_frame *frame, t_vec3 **map, int size);
void	mlx_pixel_put_img(t_frame *frame, int x, int y, int color);
void	clear_screen(t_frame *frame, int color);

/* draw_line.c */
void	draw_line(t_frame *frame, t_vec3 p1, t_vec3 p2, int color);

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
