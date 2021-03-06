/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_vector_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:42:12 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 21:45:50 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

extern inline t_v3	divide(const t_v3 a, const double b)
{
	return (new_vector(a.x / b, a.y / b, a.z / b));
}

extern inline t_v3	divide_lvalue(const t_v3 *a, const double b)
{
	return (new_vector(a->x / b, a->y / b, a->z / b));
}
