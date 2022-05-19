/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_shadow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:21:02 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/19 09:22:12 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	compute_shadow(t_color *obj_color, t_amb *ambient)
{
	t_color	shadow_color;

	shadow_color = ambient_reflexion(*obj_color, ambient);
	return (trgb_color(0, shadow_color.r, shadow_color.g, shadow_color.b));
}
