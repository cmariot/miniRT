/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 22:38:52 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/05 00:01:59 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

struct			s_obj;
struct			s_cam;

typedef void	(*t_m_print)(void *);

typedef struct s_img {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_img;

typedef struct s_mlx {
	void			*mlx_ptr;
	void			*win_ptr;
	size_t			nb_images;
	t_img			*image;
}	t_mlx;

typedef struct s_color {
	int				r;
	int				g;
	int				b;
	int				trgb;
}	t_color;

typedef struct s_light {
	t_m_print		print;
	t_3d			position;
	t_color			color;
	double			ratio;
}	t_light;

typedef struct t_amb {
	t_m_print		print;
	t_color			color;
	double			ratio;
}	t_amb;

typedef struct s_cam {
	t_m_print		print;
	t_3d			position;
	t_3d			direction;
	t_3d			ray;
	size_t			screen_width;
	size_t			screen_height;
	double			fov_horizontal;
	double			fov_vertical;
}	t_cam;

typedef bool	(*t_m_inter)(struct s_obj, struct s_cam, struct s_3d*, struct s_3d*);
typedef struct s_obj {
	t_m_inter		intersection;
	t_m_print		print;
	t_3d			position;
	t_3d			direction;
	t_color			color;
	double			radius;
	double			height;
}	t_obj;

typedef struct s_obj_list {
	size_t			nb_objs;
	t_obj			*objs;
	size_t			nb_camera;
	t_cam			*camera;
	size_t			nb_ambient;
	t_amb			ambient;
	size_t			nb_spot;
	t_light			*spot;
}	t_obj_list;

typedef struct s_world {
	t_obj_list		obj_list;
	t_mlx			mlx;
}	t_world;

#endif
