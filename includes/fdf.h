/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:33:14 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/05 18:42:39 by cybattis         ###   ########.fr       */
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

typedef struct s_vextex {
	float	x;
	float	y;
	float	z;
	int		color;
}	t_vertex;

typedef struct s_map {
	t_vertex	**v;
	t_vec2		size;
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
	int		width;
	int		height;
}	t_frame;

/* main.c */
void		init_frame(t_vars *vars, t_frame *frame);

/* matrix.c */
void		model_to_view_matrix(t_transform w, t_vec3 eye_dist);
/* rotation_matrix.c */
void		rotation_matrix(t_matrix *p_x, t_vec3 angle);

/* map_parsing.c */
t_map		*get_map(int argc, char *path);

void		update_map(t_vec3 **map, int size);

/* draw.c */
void		draw_frame(t_vars *vars, t_frame *frame, t_vec3 **map, int size);
void		draw_map(t_frame *frame, t_vec3 **map, int size);
void		mlx_pixel_put_img(t_frame *frame, int x, int y, int color);
void		clear_screen(t_frame *frame, int color);

/* draw_line.c */
void		draw_line(t_frame *frame, t_vec3 p1, t_vec3 p2, int color);

/* draw_circle.c */
void		draw_circle(t_frame *frame, t_vec3 origin, int r, int color);

/* hooks.c.c */
int			key_hook(int keycode, t_vars *vars);
int			close_win(t_vars *vars);

/* colors.c */
int			create_trgb(int t, int r, int g, int b);
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);

/* colors2.c */
int			get_opposite(int trgb);
int			add_shade(float distance, int trgb);

/* utils.c */
void		ft_ferror(int fd);
void		ft_error_msg(char *msg);
void		free_matrix(t_map *map, int i);

/* utils_print.c */
int			print_color(int trgb);
void		ft_print_map(t_map map);
void		print_vec2(t_vec2 v);
void		print_vec3(t_vec3 v);
void		print_matrix44(t_matrix44f m);

#endif
