/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:39:25 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 21:45:58 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

extern inline t_v3	multiply(const t_v3 a, const double b)
{
	return (new_vector(a.x * b, a.y * b, a.z * b));
}
