/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illumination.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:05:44 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/14 14:26:12 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//Produit scalaire entre la lumiere et le rayon permet de voir si les angles
//se croisent

static t_color	diffuse_reflexion(t_color obj_color, t_ray ray, t_light light)
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
		intensite = fmax(0, intensite_lumiere) * light.ratio
			/ norm_square(sub_vector(light.position, ray.intersection));
		diffuse_color.r = intensite * scalar * pow(obj_color.r, 2.0);
		diffuse_color.g = intensite * scalar * pow(obj_color.g, 2.0);
		diffuse_color.b = intensite * scalar * pow(obj_color.b, 2.0);
	}
	return (diffuse_color);
}

static t_color	ambient_reflexion(t_color color, t_amb ambient)
{
	double	k;

	k = ambient.ratio / 255;
	color.r *= ambient.color.r * k;
	color.g *= ambient.color.g * k;
	color.b *= ambient.color.b * k;
	return (color);
}

int	illumination(t_color pixel_color, t_obj_list obj_list, t_ray ray)
{
	t_color	ambient_color;
	t_color	diffuse_color;

	ambient_color = ambient_reflexion(pixel_color, obj_list.ambient);
	diffuse_color = diffuse_reflexion(pixel_color, ray, obj_list.light);
	pixel_color.r = ambient_color.r + diffuse_color.r;
	pixel_color.g = ambient_color.g + diffuse_color.g;
	pixel_color.b = ambient_color.b + diffuse_color.b;
	return (trgb_color(0, pixel_color.r, pixel_color.g, pixel_color.b));
}
