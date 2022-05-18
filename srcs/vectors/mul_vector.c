/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:39:25 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 18:56:38 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

extern inline t_v3	mul_vector(const t_v3 a, const float b)
{
	return (new_vector(a.x * b, a.y * b, a.z * b));
}
