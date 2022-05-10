/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illumination.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:36:27 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/10 12:08:11 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_color	reflexion_diffuse(t_light spot,
		t_color color, t_3d *intersection, t_3d *normale)
{
	t_color	diff;
	double	intensite;
	double	scalar;

	diff.r = 0;
	diff.g = 0;
	diff.b = 0;
	scalar = scalar_product(normalize(sub_vector(spot.position, *intersection)), *normale);
	if (scalar > 0)
	{
		intensite = 20 * spot.ratio / norm_square(sub_vector(spot.position, *intersection));
		diff.r = intensite * scalar * color.r * spot.color.r;
		diff.g = intensite * scalar * color.g * spot.color.g;
		diff.b = intensite * scalar * color.b * spot.color.b;
	}
	return (diff);
}

//Optimisation : L a calculer au moment du parsing
static t_color	ambient_reflexion(t_color color, t_amb ambient)
{
	double	L;

	L = ambient.ratio / 255;
	color.r += ambient.color.r * L;
	color.g += ambient.color.g * L;
	color.b += ambient.color.b * L;
	return (color);
}

int	illumination(t_obj obj, t_obj_list *obj_list,
	t_3d *normale, t_3d *intersection)

{
	t_color	diff;
	t_color	pixel;
	size_t	i;

	i = 0;
	pixel = ambient_reflexion(obj.color, obj_list->ambient);
	while (i < obj_list->nb_spot)
	{
		diff = reflexion_diffuse(obj_list->spot[i], pixel, intersection, normale);
		pixel.r += diff.r;
		pixel.g += diff.g;
		pixel.b += diff.b;
		i++;
	}
	return (trgb_color(0, pixel.r, pixel.g, pixel.b));
}
