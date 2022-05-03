/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 22:38:52 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 09:23:17 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# define SCREEN_SIZE_X 1440
# define SCREEN_SIZE_Y 872

struct			s_obj;

typedef struct s_color {
	int				r;
	int				g;
	int				b;
	int				trgb;
}	t_color;

typedef struct s_image {
	size_t			pixel_y;
	size_t			pixel_x;
}	t_image;

typedef struct s_cam {
	t_3d			position;
	t_3d			direction;
	double			fov_horizontal;
	double			fov_vertical;
	size_t			screen_size_y;
	size_t			screen_size_x;
	t_image			image;
}	t_cam;

typedef struct s_light {
	t_3d			position;
	t_color			color;
	double			ratio;
}	t_light;

typedef struct t_ambient {
	t_color			color;
	double			ratio;
}	t_ambient;

typedef struct s_light_list {
	t_ambient		ambient;
	t_light			*spot_light;
}	t_light_list;

typedef void	(*t_print)(struct s_obj);
typedef struct s_obj {
	t_print			print;
	t_3d			position;
	t_3d			direction;
	t_color			color;
	double			radius;
	double			height;
}	t_obj;

typedef struct s_obj_list {
	size_t			nb_objs;
	size_t			nb_camera;
	size_t			nb_spot_light;
	size_t			nb_ambient_light;
	t_obj			*objs;
}	t_obj_list;

typedef struct s_world {
	t_cam			*camera;
	t_obj_list		obj_list;
	t_light_list	light_list;
}	t_world;

#endif
