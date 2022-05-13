/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illumination.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:05:44 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/13 16:22:15 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_color	diffuse_reflexion(t_color obj_color, t_ray ray,
		t_light light, t_amb ambient)
{
	t_color			diffuse_color;
	double			scalar;
	double			intensite;
	const double	intensite_lumiere = 20;

	diffuse_color.r = 0;
	diffuse_color.g = 0;
	diffuse_color.b = 0;
	scalar = scalar_product(normalize(sub_vector(light.position,
					ray.intersection)), ray.normale);
	if (scalar > 0)
	{
		intensite = intensite_lumiere * light.ratio
			/ norm_square(sub_vector(light.position, ray.intersection));
		diffuse_color.r = intensite * scalar * obj_color.r * ambient.color.r;
		diffuse_color.g = intensite * scalar * obj_color.g * ambient.color.g;
		diffuse_color.b = intensite * scalar * obj_color.b * ambient.color.b;
	}
	return (diffuse_color);
}

static t_color	ambient_reflexion(t_color obj_color, t_amb ambient)
{
	t_color	ambient_color;
	double	k;

	k = ambient.ratio / 255;
	ambient_color.r = ambient.color.r * k * obj_color.r;
	ambient_color.g = ambient.color.g * k * obj_color.g;
	ambient_color.b = ambient.color.b * k * obj_color.b;
	return (ambient_color);
}

int	illumination(t_color obj_color, t_obj_list obj_list, t_ray ray)
{
	t_color	ambient_color;
	t_color	diffuse_color;

	ambient_color = ambient_reflexion(obj_color, obj_list.ambient);
	diffuse_color = diffuse_reflexion(obj_color, ray, obj_list.light,
			obj_list.ambient);
	obj_color.r = ambient_color.r + diffuse_color.r;
	obj_color.g = ambient_color.g + diffuse_color.g;
	obj_color.b = ambient_color.b + diffuse_color.b;
	return (trgb_color(0, obj_color.r, obj_color.g, obj_color.b));
}
