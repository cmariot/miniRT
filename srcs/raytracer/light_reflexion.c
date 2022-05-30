/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_reflexion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:05:44 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/20 15:21:22 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//Produit scalaire entre la lumiere et le rayon permet de voir si les angles
//se croisent

void	diffuse(t_color *color, t_color *obj_color, t_obj_list *obj_list)
{
	t_color			diffuse_color;
	t_v3			light_ray;
	double			scalar;
	double			intensite;
	const double	intensite_lumiere = 20.0;

	// ft_bzero(&diffuse_color, sizeof(t_color));  = (const t_color){0};
	diffuse_color = (const t_color){0};
	light_ray = sub_lvalue(&obj_list->light.position,
			&obj_list->camera.ray.intersection);
	scalar = dot(normalize_lvalue(&light_ray), obj_list->camera.ray.normale);
	if (scalar > 0)
	{
		intensite = scalar * intensite_lumiere * obj_list->light.ratio
			* fmin(1.0, 1 / norm_square_lvalue(&light_ray));
		diffuse_color.r = intensite * obj_color->r * color->r;
		diffuse_color.g = intensite * obj_color->g * color->g;
		diffuse_color.b = intensite * obj_color->b * color->b;
	}
	color->r += diffuse_color.r;
	color->g += diffuse_color.g;
	color->b += diffuse_color.b;
}

t_color	ambient(t_obj *obj, t_amb *amb)
{
	t_color	ambient;

	ambient.r = obj->color.r * amb->color.r * amb->ambient_constant;
	ambient.g = obj->color.g * amb->color.g * amb->ambient_constant;
	ambient.b = obj->color.b * amb->color.b * amb->ambient_constant;
	return (ambient);
}
