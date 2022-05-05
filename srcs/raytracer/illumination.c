/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illumination.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:36:27 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/05 22:56:11 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	reflexion_lambert(t_color color, t_light spot, t_3d normale, t_3d intersection)
{
	float	scalar;

	scalar = scalar_product(normale, normalize(sub_vector(spot.position, intersection)));
	if (scalar == 0)
		return (color);
	color.r += spot.ratio * scalar * color.r;
	color.g += spot.ratio * scalar * color.g;
	color.b += spot.ratio * scalar * color.g;
	return (color);
}

t_color	reflexion_ambiente(t_color obj_color, t_amb ambient)
{
	float	k;

	k = ambient.ratio;
	obj_color.r *= k;
	obj_color.g *= k;
	obj_color.b *= k;
	return (obj_color);
}

int	illumination(t_obj obj, t_obj_list *obj_list, t_3d normale, t_3d intersection)

{
	t_color	color;
	size_t	i;

	//Luminosite ambiente
	color = reflexion_ambiente(obj.color, obj_list->ambient);
	i = 0;
	while (i < obj_list->nb_spot)
	{
		//Luminosite += Luminosite diffuse
		color = reflexion_lambert(color, obj_list->spot[i], normale, intersection);
		//Luminosite += Luminosite speculaire
		i++;
	}
	return (trgb_color(0, color.r, color.g, color.b));
}
