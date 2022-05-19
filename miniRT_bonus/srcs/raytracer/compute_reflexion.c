/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_reflexion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:05:44 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/19 16:37:49 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//Produit scalaire entre la lumiere et le rayon permet de voir si les angles
//se croisent

static t_color	diffuse_reflexion(t_color *obj_color, t_ray *ray, t_light *light)
{
	t_color			diffuse_color;
	t_v3			light_ray;
	double			scalar;
	double			intensite;
	const double	intensite_lumiere = 20.0;

	ft_memset(&diffuse_color, 0, sizeof(double) * 3);
	light_ray = sub_vector(light->position, ray->intersection);
	scalar = scalar_product(normalize(light_ray), ray->normale);
	if (scalar > 0)
	{
		intensite = scalar * intensite_lumiere * light->ratio
			/ norm_square(light_ray);
		diffuse_color.r = intensite * obj_color->r * light->color.r;
		diffuse_color.g = intensite * obj_color->g * light->color.g;
		diffuse_color.b = intensite * obj_color->b * light->color.b;
	}
	return (diffuse_color);
}

t_color	ambient_reflexion(t_color color, t_amb *ambient)
{
	color.r *= ambient->color.r * ambient->ambient_constant;
	color.g *= ambient->color.g * ambient->ambient_constant;
	color.b *= ambient->color.b * ambient->ambient_constant;
	return (color);
}

void	compute_reflexion(t_color *obj_color, t_light *light, t_ray *ray, t_color *pixel_color)
{
	t_color	diffuse_color;

	diffuse_color = diffuse_reflexion(obj_color, ray, light);
	pixel_color->r += diffuse_color.r;
	pixel_color->g += diffuse_color.g;
	pixel_color->b += diffuse_color.b;
}
