/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:07:39 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 17:08:54 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <fcntl.h>
# include <limits.h>
# include <float.h>

# include "libft.h"
# include "vector3.h"
# include "structure.h"
# include "mlx.h"

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
int		memory_allocation(t_world *w, t_obj_list *o, t_light_list *l);
int		fill_world(t_world *world, const char *filename);
t_obj	new_sphere(char **array, int *error);
t_obj	new_plan(char **array, int *error);
t_obj	new_cylinder(char **array, int *error);
t_cam	new_camera(char **array, int *error);
t_amb	new_ambient(char **array, int *error);
t_light	new_light(char **array, int *error);
int		set_position(t_3d *position, char *str);
int		set_direction(t_3d *direction, char *str);
int		set_colors(t_color *color, char *rgb);
int		set_double(double *dbl, char *str, double min, double max);
int		trgb_color(int t, int r, int g, int b);

void	print_structure(t_world *world, t_obj_list *objs_list);
void	print_sphere(t_obj sphere);
void	print_plan(t_obj plan);
void	print_cylinder(t_obj cylinder);

/* ************************************************************************** */
/*                               Mlx directory                                */
/* ************************************************************************** */

int		close_window(t_world *world);
int		open_window(t_world *world);
int		key_hook(int keycode, t_world *world);

/* ************************************************************************** */
/*                          Raytracinging directory                           */
/* ************************************************************************** */

/* ************************************************************************** */
/*                              Utils directory                               */
/* ************************************************************************** */

void	free_world(t_world *world);
int		rt_error(char const *error_message);
int		second_line_error(char const *error_message);

#endif
