/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 22:25:15 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 18:59:50 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

typedef struct s_v3
{
	float			x;
	float			y;
	float			z;
	float			a;
}	t_v3;

t_v3		new_vector(const float x, const float y, const float z);

t_v3		add_vector(const t_v3 a, const t_v3 b);
t_v3		sub_vector(const t_v3 a, const t_v3 b);
t_v3		div_vector(const t_v3 a, const float b);
t_v3		mul_vector(const t_v3 a, const float b);

t_v3		normalize(const t_v3 a);
t_v3		cross_product(const t_v3 a, const t_v3 b);
float		norm_square(const t_v3 a);
float		norm(const t_v3 a);
float		scalar_product(const t_v3 a, const t_v3 b);
float		length(const t_v3 point_a, const t_v3 point_b);

#endif
