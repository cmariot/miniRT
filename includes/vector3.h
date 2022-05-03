/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 22:25:15 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/01 22:38:08 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

/* ************************************************************************** */
/*  t_3d structure is used to store 3 floats.                                 */
/*  Those floats can be use to store a 3D position, a vector direction ...    */
/* ************************************************************************** */

typedef struct s_3d
{
	double			x;
	double			y;
	double			z;
}	t_3d;

t_3d	new_vector(float x, float y, float z);
t_3d	add_vector(t_3d a, t_3d b);
t_3d	sub_vector(t_3d a, t_3d b);
t_3d	div_vector(t_3d a, double b);
t_3d	mul_vector(t_3d a, double b);
t_3d	cross_product(t_3d a, t_3d b);
double	norm(t_3d a);
double	norm_square(t_3d a);
t_3d	normalize(t_3d a);
double	scalar_product(t_3d a, t_3d b);
double	length(t_3d point_a, t_3d point_b);

#endif
