/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 19:26:32 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 11:02:30 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Return the square of a vector norm */
extern inline double	norm_square(t_v3 a)
{
	return (a.x * a.x + a.y * a.y + a.z * a.z);
}
