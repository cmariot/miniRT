/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 22:25:15 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/02 10:38:45 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_BONUS_H
# define VECTOR3_BONUS_H

typedef struct s_v3
{
	double			x;
	double			y;
	double			z;
	double			a;
}	t_v3;

t_v3		new_vector(const double x, const double y, const double z);

t_v3		add(const t_v3 a, const t_v3 b);
t_v3		sub(const t_v3 a, const t_v3 b);
t_v3		divide(const t_v3 a, const double b);
t_v3		multiply(const t_v3 a, const double b);

t_v3		normalize(const t_v3 a);
t_v3		cross(const t_v3 a, const t_v3 b);
double		norm_square(const t_v3 a);
double		norm(const t_v3 a);
double		dot(const t_v3 a, const t_v3 b);
double		length(const t_v3 point_a, const t_v3 point_b);

t_v3		sub_lvalue(const t_v3 *a, const t_v3 *b);
t_v3		add_lvalue(const t_v3 *a, const t_v3 *b);
t_v3		divide_lvalue(const t_v3 *a, const double b);
t_v3		multiply_lvalue(const t_v3 *a, const double b);

t_v3		normalize_lvalue(const t_v3 *a);
t_v3		cross_lvalue(const t_v3 *a, const t_v3 *b);
double		norm_square_lvalue(const t_v3 *a);
double		norm_lvalue(const t_v3 *a);
double		dot_lvalue(const t_v3 *a, const t_v3 *b);
double		length_lvalue(const t_v3 *point_a, const t_v3 *point_b);

#endif
