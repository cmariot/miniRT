/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_reflexion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:05:44 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/30 11:23:02 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//Produit scalaire entre la lumiere et le rayon permet de voir si les angles
//se croisent

void	diffuse(t_color *color, t_obj_list *obj_list,
		t_light light)
{
	t_color			diffuse_color;
	t_v3			light_ray;
	double			scalar;
	double			intensite;
	const double	intensite_lumiere = 20.0;

	diffuse_color = (const t_color){0};
	light_ray = sub(light.position,
			obj_list->camera.ray.intersection);
	scalar = dot(normalize(light_ray), obj_list->camera.ray.normale);
	if (scalar > 0)
	{
		intensite = scalar * light.ratio * intensite_lumiere
			* fmin(1.0, 1 / norm_square(light_ray));
		diffuse_color.r = intensite * color->r * light.color.r;
		diffuse_color.g = intensite * color->g * light.color.g;
		diffuse_color.b = intensite * color->b * light.color.b;
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

void	compute_reflexion(t_obj_list *obj_list, t_ray *first_ray,
		t_color *color, t_obj *obj)
{
	size_t	j;
	t_ray	second_ray;

	*color = ambient(obj, &obj_list->ambient);
	j = 0;
	while (j < obj_list->nb_light)
	{
		second_ray = second_ray_generator(first_ray, &obj_list->light[j]);
		if (in_light(&second_ray, &obj_list->light[j], obj_list))
			diffuse(color, obj_list, obj_list->light[j]);
		j++;
	}
}
