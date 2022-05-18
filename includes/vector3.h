/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 22:25:15 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 16:10:49 by cmariot          ###   ########.fr       */
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

t_v3		new_vector(double x, double y, double z);

t_v3		add_vector(t_v3 a, t_v3 b);
t_v3		sub_vector(t_v3 a, t_v3 b);
t_v3		div_vector(t_v3 a, double b);
t_v3		mul_vector(t_v3 a, double b);

t_v3		normalize(t_v3 a);
t_v3		cross_product(t_v3 a, t_v3 b);
double		norm_square(t_v3 a);
double		norm(t_v3 a);
double		scalar_product(t_v3 a, t_v3 b);
double		length(t_v3 point_a, t_v3 point_b);

#endif
