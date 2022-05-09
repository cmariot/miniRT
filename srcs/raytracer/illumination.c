/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illumination.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:36:27 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/09 17:17:01 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_color	diffuse_reflexion(t_light spot,
		t_color color, t_3d *intersection, t_3d *normale)
{
	double	scalar;

	scalar = scalar_product(normalize(
				sub_vector(spot.position, *intersection)), *normale);
	if (scalar <= 0)
		return (color);
	else
	{
		color.r += spot.color.r * spot.ratio * scalar
			/ norm_square(add_vector(*intersection, spot.position));
		color.g += spot.color.g * spot.ratio * scalar
			/ norm_square(add_vector(*intersection, spot.position));
		color.b += spot.color.b * spot.ratio * scalar
			;
	}
	return (color);
}

static t_color	ambient_reflexion(t_color color, t_amb ambient)
{
	color.r *= ambient.color.r / 255 * ambient.ratio;
	color.g *= ambient.color.g / 255 * ambient.ratio;
	color.b *= ambient.color.b / 255 * ambient.ratio;
	return (color);
}

int	illumination(t_obj obj, t_obj_list *obj_list,
	t_3d *normale, t_3d *intersection)

{
	t_color	color;
	size_t	i;

	i = 0;
	color = ambient_reflexion(obj.color, obj_list->ambient);
	while (i < obj_list->nb_spot)
	{
		color = diffuse_reflexion(obj_list->spot[i],
				color, intersection, normale);
		i++;
	}
	return (trgb_color(0, color.r, color.g, color.b));
}
