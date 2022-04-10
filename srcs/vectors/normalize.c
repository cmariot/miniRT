/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:58:12 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/09 11:13:16 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_3d	normalize(t_3d a)
{
	t_3d		b;
	double		norm;

	norm = sqrt(norm_square(a));
	b.x = a.x / norm;
	b.y = a.y / norm;
	b.z = a.z / norm;
	return (b);
}
