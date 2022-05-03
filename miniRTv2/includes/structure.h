/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 22:38:52 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 16:57:43 by cmariot          ###   ########.fr       */
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
	char			*str_image;
}	t_image;

typedef struct s_cam {
	t_3d			position;
	t_3d			direction;
	double			fov_horizontal;
	double			fov_vertical;
	double			screen_size_y;
	double			screen_size_x;
	size_t			nb_image;
	t_image			*image;
}	t_cam;

typedef struct s_light {
	t_3d			position;
	t_color			color;
	double			ratio;
}	t_light;

typedef struct t_amb {
	t_color			color;
	double			ratio;
}	t_amb;

typedef struct s_light_list {
	t_amb			ambient;
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

typedef struct s_mlx {
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_world {
	t_cam			*camera;
	t_obj_list		obj_list;
	t_light_list	light_list;
	t_mlx			mlx;
}	t_world;

#endif
