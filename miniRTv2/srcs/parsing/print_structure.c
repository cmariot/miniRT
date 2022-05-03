/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_structure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:43:27 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 00:39:11 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_sphere(t_obj sphere)
{
	printf("\nSphere :\n");
	printf("|\tPosition : (x = %.3f ; y = %.3f ; z = %.3f))\n",
		sphere.position.x, sphere.position.y, sphere.position.z);
	printf("|\tDiameter : %.3f, Radius : %.3f\n",
		sphere.radius * 2, sphere.radius);
	printf("|\tColor    : (r = %.d ; g = %.d ; b = %.d ; trgb = %d)\n\n",
		sphere.color.r, sphere.color.g, sphere.color.b, sphere.color.trgb);
}

void	print_plan(t_obj plan)
{
	printf("\nPlan :\n");
	printf("|\tPosition  : (x = %.3f ; y = %.3f ; z = %.3f))\n",
		plan.position.x, plan.position.y, plan.position.z);
	printf("|\tDirection : (x = %.3f ; y = %.3f ; z = %.3f))\n",
		plan.direction.x, plan.direction.y, plan.direction.z);
	printf("|\tColor     : (r = %.d ; g = %.d ; b = %.d ; trgb = %d)\n\n",
		plan.color.r, plan.color.g, plan.color.b, plan.color.trgb);
}

void	print_cylinder(t_obj cylinder)
{
	printf("\nCylinder :\n");
	printf("|\tPosition  : (x = %.3f ; y = %.3f ; z = %.3f))\n",
		cylinder.position.x, cylinder.position.y, cylinder.position.z);
	printf("|\tDirection : (x = %.3f ; y = %.3f ; z = %.3f))\n",
		cylinder.direction.x, cylinder.direction.y, cylinder.direction.z);
	printf("|\tRadius : %.3f ; Height : %.3f\n",
		cylinder.radius, cylinder.height);
	printf("|\tColor     : (r = %.d ; g = %.d ; b = %.d ; trgb = %d)\n\n",
		cylinder.color.r, cylinder.color.g, cylinder.color.b,
		cylinder.color.trgb);
}

void	print_structure(t_world *world, t_obj *objs)
{
	size_t	i;

	i = 0;
	while (i < world->obj_list.nb_objs)
	{
		objs[i].print(objs[i]);
		i++;
	}
}
