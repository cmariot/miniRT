/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illumination.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:36:27 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/07 18:38:16 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_color	reflexion_lambert(t_color color, t_light spot,
	t_3d normale, t_3d intersection)
{
	float	scalar;

	scalar = scalar_product(normalize(sub_vector(spot.position, intersection)), normale);
	if (scalar == 0)
		return (color);
	color.r += spot.ratio * scalar * color.r;
	color.g += spot.ratio * scalar * color.g;
	color.b += spot.ratio * scalar * color.b;
	return (color);
}

static t_color	reflexion_ambiente(t_color obj_color, t_amb ambient)
{
	float	k;

	k = ambient.ratio;
	obj_color.r *= k;
	obj_color.g *= k;
	obj_color.b *= k;
	return (obj_color);
}

//Couleur = Luminosite ambiente
// + Somme
// {
//		Couleur += Reflexion diffuse
//		Couleur += Reflexion speculaire
// }
int	illumination(t_obj obj, t_obj_list *obj_list,
	t_3d normale, t_3d intersection)

{
	t_color	color;
	size_t	i;

	color = reflexion_ambiente(obj.color, obj_list->ambient);
	i = 0;
	while (i < obj_list->nb_spot)
	{
		color = reflexion_lambert(color, obj_list->spot[i],
				normale, intersection);
		i++;
	}
	return (trgb_color(0, color.r, color.g, color.b));
}
