/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 19:26:32 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/30 19:27:01 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Return the square of a vector norm */
double	norm_square(t_3d a)
{
	return (a.x * a.x + a.y * a.y + a.z * a.z);
}
