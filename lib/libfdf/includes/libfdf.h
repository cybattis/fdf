/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:03:16 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/16 12:27:29 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFDF_H
# define LIBFDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifdef __linux__
#  define OPEN_MAX FOPEN_MAX
# endif

# define BUFFER_SIZE 2048

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_matrix
{
	float	m[4][4];
}	t_matrix;

void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memset(void *src, int cpy, size_t n);
int			ft_atoi(const char *str);
void		ft_putstr(char *s);
void		ft_putnbr(int nb);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_dprintf(int fd, const char *format, ...);
int			ft_printf(const char *format, ...);
size_t		ft_strlen(const char *str);
void		ft_putchar(char c);
int			ft_isdigit(int c);
int			ft_strichr(const char *s, int c);
int			ft_isspace(int c);
int			ft_nbrlen(long nb);
void		*ft_free_all(char **strs, size_t i);
int			ft_atoi_base(const char *str, const char *base);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		**ft_split(char const *s, char c);
char		*ft_get_next_line(int fd);
char		*ft_str_tolower(char *str);
void		ft_print_matrix(int fd, t_vec3 **matrix, int size);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);

/* vec2 */
t_vec2		vec2(float x, float y);
t_vec2		vec2_zero(void);
t_vec2		vec2_set(float value);
t_vec2		*vec2_add(t_vec2 *self, t_vec2 v2);
t_vec2		*vec2_multv2(t_vec2 *self, t_vec2 v2);
t_vec2		*vec2_multi(t_vec2 *self, long n);
t_vec2		*vec2_multf(t_vec2 *self, float n);
t_vec2		*vec2_divv2(t_vec2 *self, t_vec2 v2);
t_vec2		*vec2_divi(t_vec2 *self, long n);
t_vec2		*vec2_divf(t_vec2 *self, float n);
float		vec2_mag(t_vec2 vec2);
t_vec2		*vec2_normalize(t_vec2 *v);
t_vec2		vec2_normalized(t_vec2 v);

/* vec3 */
t_vec3		vec3(float x, float y, float z);
t_vec3		vec3_zero(void);
t_vec3		vec3_set(float value);
t_vec3		*vec3_add(t_vec3 *self, t_vec3 v3);
t_vec3		*vec3_multv3(t_vec3 *self, t_vec3 v3);
t_vec3		*vec3_multi(t_vec3 *self, long n);
t_vec3		*vec3_multf(t_vec3 *self, float n);
t_vec3		*vec3_divv3(t_vec3 *self, t_vec3 v3);
t_vec3		*vec3_divi(t_vec3 *self, long n);
t_vec3		*vec3_divf(t_vec3 *self, float n);
t_vec3		*vec3_normalize(t_vec3 *v);
t_vec3		vec3_normalized(t_vec3 v);
t_vec3		*vec3_clamp_max(t_vec3 *v, float x, float y, float z);
t_vec3		*vec3_clamp_min(t_vec3 *v, float x, float y, float z);
t_vec3		vec3_lerpf(t_vec3 base, t_vec3 high, float value);
float		vec3_mag(t_vec3 v);

/* matrix */
void		matrix_mult44(float m1[][4], float m2[][4], t_matrix *out);
t_vec3		matrix_mult44v3(const t_vec3 *v, t_matrix *matrix);

float	ft_lerp(float a, float b, float f);

#endif
