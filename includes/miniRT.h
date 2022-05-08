/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:07:39 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/08 16:39:46 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <fcntl.h>
# include <limits.h>
# include <float.h>

# include "../libft/includes/libft.h"
# include "vector3.h"
# include "structure.h"
# include "mlx.h"
# include "keycodes.h"

# define SCREEN_WIDTH 1440

# define X 0
# define Y 1

/* ************************************************************************** */
/*                              Main directory                                */
/* ************************************************************************** */

int		main(int argc, char **argv);

/* ************************************************************************** */
/*                             Parsing directory                              */
/* ************************************************************************** */

int		parsing(t_world *world, const char *filename);
int		check_extension(const char *filename, const char *extension);
int		check_reading_access(const char *filename);
int		get_object_list(t_obj_list *obj_list, const char *filename);
int		memory_allocation(t_obj_list *o);
int		fill_world(t_world *world, const char *filename);
int		new_sphere(t_obj *sphere, char **array);
int		new_plan(t_obj *plan, char **array);
int		new_cylinder(t_obj *cylinder, char **array);
int		new_camera(t_cam *cam, char **array);
int		new_ambient(t_amb *ambient, char **array);
int		new_light(t_light *light, char **array);
int		set_position(t_3d *position, char *str);
int		set_direction(t_3d *direction, char *str);
int		set_colors(t_color *color, char *rgb);
int		set_double(double *dbl, char *str, double min, double max);

void	print_structure(t_obj_list objs_list);
void	print_sphere(void *ptr);
void	print_plan(void *ptr);
void	print_cylinder(void *ptr);
void	print_light(void *ptr);
void	print_ambient(void *ptr);
void	print_camera(void *ptr);

/* ************************************************************************** */
/*                               Mlx directory                                */
/* ************************************************************************** */

int		close_window(t_world *world);
int		open_window(t_world *world);
int		key_hook(int keycode, t_world *world);
int		create_images(t_mlx *mlx, size_t nb_images, t_world *world);
void	mlx_putpixel(t_img *data, size_t *pixel, int color);

/* ************************************************************************** */
/*                          Raytracinging directory                           */
/* ************************************************************************** */

void	raytracer(t_world *world, t_mlx *mlx, t_obj_list *objs, t_cam *cam);
t_ray	ray_generator(t_cam *camera, size_t x, size_t y);
int		illumination(t_obj obj, t_obj_list *obj_list, t_3d n, t_3d p);
int		check_intersection(t_cam *c, t_obj_list *o, t_3d *p, t_3d *n);

bool	intersection_plan(t_obj plan, t_ray ray, t_3d *p, t_3d *n);
bool	intersection_sphere(t_obj sphere, t_ray ray, t_3d *p, t_3d *n);
bool	intersection_cylinder(t_obj obj, t_ray ray, t_3d *p, t_3d *n);

/* ************************************************************************** */
/*                              Utils directory                               */
/* ************************************************************************** */

int		free_world(t_world *world);
int		rt_error(char const *error_message);
int		second_line_error(char const *error_message);
double	t1(double delta, double *abc);
double	t2(double delta, double *abc);
double	min_double(double t1, double t2);

#endif
