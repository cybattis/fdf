/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:33:14 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/13 17:08:48 by cybattis         ###   ########.fr       */
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
#  define KEY_SPACE	0x20
#  define KEY_A		0x61
#  define KEY_D		0x64
#  define KEY_E		0x65	// for ANSI
#  define KEY_F		0x66
#  define KEY_P		0x70
#  define KEY_Q		0x71
#  define KEY_S		0x73
#  define KEY_W		0x77
#  define KEY_X		0x78
#  define KEY_Z		0x7A
#  define KEY_ESC	0xff1b
#  define KEY_LEFT	0xff51
#  define KEY_UP	0xff52
#  define KEY_RIGHT	0xff53
#  define KEY_DOWN	0xff54
#  define KEY_F3	0xffc0
# else
#  define KEY_A		0
#  define KEY_S		1
#  define KEY_D		2
#  define KEY_F		3
#  define KEY_Z		6
#  define KEY_X		7
#  define KEY_Q		12		// for ANSI
#  define KEY_W		13
#  define KEY_E		14
#  define KEY_P		35
#  define KEY_ESC	53
#  define KEY_SPACE	49
#  define KEY_F3	99
#  define KEY_LEFT	123
#  define KEY_UP	126
#  define KEY_RIGHT	124
#  define KEY_DOWN	125
# endif

# define BLACK		0x00000000
# define RED		0x00FF0000
# define GREEN		0x0000FF00
# define BLUE		0x000000FF
# define WHITE		0x00FFFFFF
# define PINK		0x00FF00FF
# define YELLOW		0x00FFFF00
# define TURQUOISE	0x0000FFFF

# define DEBUG		1
# define DB_MATRIX	0
# define DB_COLOR	0

typedef struct s_map {
	t_vec3	v;
	int		color;
}	t_map;

typedef struct s_transform {
	float	scale;
	t_vec3	rotation;
	t_vec3	translation;
}	t_transform;

typedef struct s_frame {
	void	*img;
	char	*addr;
	int		bits_pp;
	int		line_length;
	int		endian;
}	t_frame;

typedef struct s_fdf {
	void		*mlx;
	void		*win;
	t_vec2		screen;
	t_vec2		map_size;
	t_map		**map;
	t_map		**screen_map;
	t_frame		frame;
	t_transform	t;
	int			def_color;
}	t_fdf;

void		map_projection(t_fdf *fdf, t_matrix *projection);
void		screen_projection(t_fdf *fdf, t_matrix *projection);

/* matrix.c */
void		world_matrix(t_transform t, t_matrix *world);
void		model_to_view_matrix(t_matrix *view, t_transform t, t_vec3 eye);

/* rotation_matrix.c */
void		rotation_matrix(t_matrix *p_x, t_vec3 angle);

/* map_parsing.c */
void		get_matrix_size(char *path, t_vec2 *size);
t_map		**get_map(char *path, t_vec2 *map_size);

/* draw.c */
int			draw_frame(t_fdf *fdf);
void		draw_map(t_fdf *fdf, t_vec2 map_size);
void		mlx_pixel_put_img(t_frame *frame, int x, int y, int color);
void		clear_screen(t_fdf *fdf, int color);

/* draw_line.c */
void		draw_line(t_fdf *fdf, t_map p1, t_map p2);
int			lerp_color(int a, int b, int i, int max);

/* draw_circle.c */
void		draw_circle(t_frame *frame, t_vec3 origin, int r, int color);

/* hooks.c.c */
int			key_hooks(int keycode, t_fdf *fdf);
int			mouse_hooks(int mousecode, t_fdf *fdf);

/* colors.c */
int			create_trgb(int t, int r, int g, int b);
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);

/* colors2.c */
int			get_opposite(int trgb);
int			add_shade(float distance, int trgb);

/* strtrim.c */
void		strtrim(char *str);
char		*strtriml(char *str);
void		strtrimr(char *str);

/* utils.c */
void		ft_ferror(int fd);
void		ft_error_msg(char *msg);
void		free_matrix(t_map **map, int i);
void		free_all(t_fdf *fdf);

/* utils_print.c */
int			print_color(int trgb);
void		ft_print_map(t_map	**map, t_vec2 size);
void		print_vec2(t_vec2 v);
void		print_vec3(t_vec3 v);
void		print_matrix44(t_matrix matrix);

#endif
