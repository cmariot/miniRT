/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:07:39 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/20 22:56:07 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <fcntl.h>
# include <limits.h>

# include "libft.h"
# include "scene_structure.h"
# include "mlx_structure.h"

typedef struct s_matrix
{
	float	**matrix;
	size_t	rows;
	size_t	columns;
}	t_matrix;

/* ************************************************************************** */
/*                              Main directory                                */
/* ************************************************************************** */

int		main(int argc, char **argv);

/* ************************************************************************** */
/*                             Parsing directory                              */
/* ************************************************************************** */

int		parse_scene(const char *scene, t_scene *rt_scene);
int		check_extension(const char *filename, const char *extension);
int		check_reading_access(const char *filename);
int		count_elements(const char *filename, t_scene *rt_scene);
int		alloc_structure(t_scene *rt_scene, t_counter elements);
int		fill_structure(t_scene *rt_scene, const char *file);
int		set_double(char *str, double *to_fill, double min, double max);
int		set_point(t_3d *coordinates, char *str);
int		set_orientation(t_3d *orientation, char *str);
int		set_colors(char *rgb, t_3d *colors, int *trgb);
int		trgb_color(int t, int r, int g, int b);
int		fill_ambient_light(char **array, t_ambient_light *ambient_light);
int		fill_camera(char **array, t_camera *camera);
int		fill_light(char **array, t_light *light);
int		fill_sphere(char **array, size_t *index, t_sphere *sphere);
int		fill_cylinder(char **array, size_t *index, t_cylinder *cylinder);
int		fill_plan(char **array, size_t *index, t_plan *plan);
void	print_structure(t_scene *rt_scene);
void	free_structure(t_scene *rt_scene, t_counter elements);
int		rt_error(char const *error_message);
int		second_line_error(char const *error_message);

/* ************************************************************************** */
/*                               Mlx directory                                */
/* ************************************************************************** */

int		open_window(t_scene *rt_scene);
int		key_hook(int keycode, t_scene *scene);
int		close_window(t_scene *scene);

/* ************************************************************************** */
/*                              Vector directory                              */
/* ************************************************************************** */

/* t_3d structure stores vectors (3D direction) or points (3D position).
 * Points and vectors can be transformed using linear transformations,
 * translation and rotation are examples of linear transformation.*/

t_3d	new_vector(float x, float y, float z);
t_3d	add_vector(t_3d a, t_3d b);
t_3d	sub_vector(t_3d a, t_3d b);
t_3d	div_vector(t_3d a, double b);
t_3d	mul_vector(double a, t_3d b);
double	scalar_product(t_3d a, t_3d b);
double	norm(t_3d a);
double	norm_square(t_3d a);
t_3d	normalize(t_3d a);
t_3d	cross_product(t_3d a, t_3d b);
double	distance(t_3d point_a, t_3d point_b);

float	fast_sqrt(float number);

struct s_matrix		create_matrix(size_t rows, size_t columns);
t_matrix			matrix_multiplication(t_matrix m1, t_matrix m2);

/* ************************************************************************** */
/*                          Raytracinging directory                           */
/* ************************************************************************** */

void	rendering(t_scene *scene);
bool	intersection(t_scene *scene, t_sphere sphere, t_3d *p, t_3d *n);

#endif
