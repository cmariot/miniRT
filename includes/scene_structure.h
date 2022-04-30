/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_structure.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:48:55 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/01 00:15:04 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_STRUCTURE_H
# define SCENE_STRUCTURE_H

# include "mlx_structure.h"

/* Definition of the structure used to store the scene informations for
 * the miniRT project */

/* The t_3d structure is used to store positions and directions in
 * three dimensional space. */
typedef struct s_3d
{
	double			x;
	double			y;
	double			z;
}	t_3d;

typedef struct s_ambient_light
{
	double			ratio;
	t_3d			color;
	int				trgb_color;
}	t_ambient_light;

typedef struct s_camera
{
	t_3d			point;
	t_3d			direction;
	t_3d			ray_direction;
	double			fov;
}	t_camera;

typedef struct s_light
{
	t_3d			point;
	double			ratio;
	t_3d			color;
	int				trgb_color;
}	t_light;

typedef struct s_sphere
{
	t_3d			point;
	double			diameter;
	double			radius;
	t_3d			color;
	int				trgb_color;
}	t_sphere;

typedef struct s_plan
{
	t_3d			point;
	t_3d			direction;
	t_3d			color;
	int				trgb_color;
}	t_plan;

typedef struct s_cylinder
{
	t_3d			point;
	t_3d			direction;
	double			diameter;
	double			heigth;
	t_3d			color;
	int				trgb_color;
}	t_cylinder;

typedef struct s_counter
{
	size_t			nb_ambient_light;
	size_t			nb_camera;
	size_t			nb_light;
	size_t			current_sphere;
	size_t			nb_sphere;
	size_t			index_sphere;
	size_t			nb_plan;
	size_t			index_plan;
	size_t			nb_cylinder;
	size_t			index_cylinder;
}	t_counter;

typedef struct s_scene
{
	t_mlx			mlx;
	t_ambient_light	ambient_light;
	t_camera		camera;
	t_light			light;
	t_sphere		*sphere;
	t_plan			*plan;
	t_cylinder		*cylinder;
	t_counter		elements;
}	t_scene;

#endif
