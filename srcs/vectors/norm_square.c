/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 19:26:32 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 18:57:05 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Return the square of a vector norm */
extern inline float	norm_square(const t_v3 a)
{
	return (a.x * a.x + a.y * a.y + a.z * a.z);
}
