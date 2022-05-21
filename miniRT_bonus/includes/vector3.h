/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 22:25:15 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/20 11:44:39 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

typedef struct s_v3
{
	double			x;
	double			y;
	double			z;
	double			a;
}	t_v3;

t_v3		new_vector(const double x, const double y, const double z);

t_v3		add_vector(const t_v3 a, const t_v3 b);
t_v3		sub_vector(const t_v3 a, const t_v3 b);
t_v3		div_vector(const t_v3 a, const double b);
t_v3		mul_vector(const t_v3 a, const double b);

t_v3		normalize(const t_v3 a);
t_v3		cross_product(const t_v3 a, const t_v3 b);
double		norm_square(const t_v3 a);
double		norm(const t_v3 a);
double		scalar_product(const t_v3 a, const t_v3 b);
double		length(const t_v3 point_a, const t_v3 point_b);

#endif
