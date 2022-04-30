/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:44:54 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/30 19:28:37 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* */
double	scalar_product(t_3d a, t_3d b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
