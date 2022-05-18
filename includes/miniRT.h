/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:07:39 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 19:40:29 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "vector3.h"
# include "structure.h"
# include "mlx.h"
# include "keycodes.h"

# define SCREEN_WIDTH 1440

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
int		set_float(float *dbl, char *str, float min, float max);

/* ************************************************************************** */
/*                               Mlx directory                                */
/* ************************************************************************** */

int		open_window(t_world *world);
int		create_image(t_mlx *mlx, t_world *world);
void	mlx_putpixel(t_img *data, float *x, float *y, int *color);
int		key_hook(int keycode, t_world *world);
int		key_handler(int keycode, t_world *world);
int		close_window(t_world *world);
int		mouse_hook(int mouse_code, void *ptr);

/* ************************************************************************** */
/*                          Raytracinging directory                           */
/* ************************************************************************** */

void	raytracer(t_obj_list *obj_list, t_cam *camera, t_mlx *mlx);
t_ray	ray_generator(t_cam	*camera, float *x, float *y);
void	compute_color(int *color, t_ray *first_ray, t_obj_list *obj_list);
t_ray	second_ray_generator(t_ray *first_ray, t_light *light);
bool	is_shadow(t_ray *second_ray, t_light *light, t_obj_list *obj_list);
int		compute_reflexion(t_color *color, t_obj_list *obj_list, t_ray *ray);
int		compute_shadow(t_color *obj_color, t_amb *ambient);
void	translate_all(t_obj_list *obj_list, t_cam *cam);
void	rotate_all(t_obj_list *obj_list, t_cam *cam);

/* ************************************************************************** */
/*                           Intersection directory                           */
/* ************************************************************************** */

bool	intersection_sphere(t_obj *sphere, t_ray *ray);
bool	intersection_plan(t_obj *plan, t_ray *ray);
bool	intersection_cylinder(t_obj *cyl, t_ray *ray);
float	t1(float delta, float *abc);
float	t2(float delta, float *abc);
float	min_positive(float t1, float t2);
t_v3	get_position(t_v3 origine, t_v3 direction, float t);

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

#endif
