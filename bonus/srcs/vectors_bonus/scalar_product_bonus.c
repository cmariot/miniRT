/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_product_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:44:54 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 21:46:31 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

extern inline double	dot(const t_v3 a, const t_v3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

extern inline double	dot_lvalue(const t_v3 *a, const t_v3 *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}
