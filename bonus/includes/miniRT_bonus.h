/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:07:39 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/02 10:38:32 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include "libft.h"
# include "vector3.h"
# include "structure.h"
# include "mlx.h"
# include "keycodes.h"

# include <time.h>

# define SCREEN_WIDTH 1440

/* ************************************************************************** */
/*                                   Main                                     */
/* ************************************************************************** */

int		main(int argc, char **argv);

/* ************************************************************************** */
/*                             Parsing directory                              */
/* ************************************************************************** */

int		parsing(t_world *world, const char *filename);
int		check_extension(const char *filename, const char *extension);
int		check_reading_access(const char *filename);
int		count_objects(t_obj_list *obj_list, const char *filename);
int		memory_allocation(t_obj_list *o);
int		fill_structure(t_world *world, const char *filename);
int		new_sphere(t_obj *sphere, char **array);
int		new_plan(t_obj *plan, char **array);
int		new_cylinder(t_obj *cylinder, char **array);
int		new_camera(t_cam *cam, char **array);
int		new_ambient(t_amb *ambient, char **array);
int		new_light(t_light *light, char **array);
int		set_position(t_v3 *position, char *str);
int		set_direction(t_v3 *direction, char *str);
int		set_colors(t_color *color, char *rgb);
int		set_double(double *dbl, char *str, double min, double max);
int		new_triangle(t_obj *plan, char **array);

/* ************************************************************************** */
/*                               Mlx directory                                */
/* ************************************************************************** */

int		open_window(t_world *world);
int		create_image(t_mlx *mlx, t_world *world);
void	mlx_putpixel(t_img *data, double *x, double *y, int *color);
int		key_handler(int keycode, t_world *world);
int		close_window(t_world *world);

/* ************************************************************************** */
/*                          Raytracinging directory                           */
/* ************************************************************************** */

void	raytracer(t_obj_list *obj_list, t_cam *camera, t_mlx *mlx);
void	lookat(t_v3 cam_dir, double *matrix);
t_ray	ray_generator(t_cam	*camera, double *x, double *y);
void	compute_color(int *color, t_ray *first_ray, t_obj_list *obj_list);
t_color	ambient(t_obj *obj, t_amb *ambient);
t_ray	second_ray_generator(t_ray *first_ray, t_light *light);
bool	in_light(t_ray *second_ray, t_light *light, t_obj_list *obj_list);
void	compute_reflexion(t_obj_list *list, t_ray *ray, t_color *c, t_obj *obj);

/* ************************************************************************** */
/*                                Translation                                 */
/* ************************************************************************** */

void	translate_all(t_obj_list *obj_list, t_cam *cam);
void	translate(t_v3 *target, t_v3 value);
void	translate_plan(t_obj *plan, t_v3 cam_position);
void	translate_sphere(t_obj *sphere, t_v3 cam_position);
void	translate_cylinder(t_obj *cylinder, t_v3 cam_position);
void	translate_triangle(t_obj *triangle, t_v3 cam_position);

/* ************************************************************************** */
/*                           Intersection directory                           */
/* ************************************************************************** */

bool	intersection_sphere(t_obj *sphere, t_ray *ray);
bool	intersection_plan(t_obj *plan, t_ray *ray);
bool	intersection_cylinder(t_obj *cyl, t_ray *ray);
bool	intersection_triangle(t_obj *cyl, t_ray *ray);

bool	second_intersection_sphere(t_obj *sphere, t_ray *ray);
bool	second_intersection_plan(t_obj *plan, t_ray *ray);
bool	second_intersection_cylinder(t_obj *cyl, t_ray *ray);
bool	second_intersection_triangle(t_obj *obj, t_ray *ray);

double	t1(double delta, double *abc);
double	t2(double delta, double *abc);
double	min_positive(double t1, double t2);
t_v3	get_position(t_v3 origine, t_v3 direction, double t);
float	q_rsqrt(float number);

/* ************************************************************************** */
/*                              Utils directory                               */
/* ************************************************************************** */

int		free_structure(t_world *world);
int		rt_error(char const *error_message);
void	print_structure(t_obj_list objs_list);
void	print_sphere(void *ptr);
void	print_plan(void *ptr);
void	print_cylinder(void *ptr);
void	print_camera(void *ptr);
void	print_ambient(void *ptr);
void	print_light(void *ptr);
void	print_triangle(void *ptr);

#endif
