/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_structure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:43:27 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/04 10:57:42 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_sphere(void *ptr)
{
	t_obj	*sphere;

	sphere = (t_obj *)ptr;
	printf("\nSphere :\n");
	printf("|\tPosition : x = %.3f ; y = %.3f ; z = %.3f\n",
		sphere->position.x,
		sphere->position.y,
		sphere->position.z);
	printf("|\tRadius   : %.3f\n",
		sphere->radius);
	printf("|\tColor    : r = %d ; g = %d ; b = %d ; trgb = %d\n\n",
		sphere->color.r,
		sphere->color.g,
		sphere->color.b,
		sphere->color.trgb);
}

void	print_plan(void *ptr)
{
	t_obj	*plan;

	plan = (t_obj *)ptr;
	printf("\nPlan :\n");
	printf("|\tPosition  : x = %.3f ; y = %.3f ; z = %.3f\n",
		plan->position.x,
		plan->position.y,
		plan->position.z);
	printf("|\tDirection : x = %.3f ; y = %.3f ; z = %.3f\n",
		plan->direction.x,
		plan->direction.y,
		plan->direction.z);
	printf("|\tColor     : r = %d ; g = %d ; b = %d ; trgb = %d\n\n",
		plan->color.r,
		plan->color.g,
		plan->color.b,
		plan->color.trgb);
}

void	print_cylinder(void *ptr)
{
	t_obj	*cylinder;

	cylinder = (t_obj *)ptr;
	printf("\nCylinder :\n");
	printf("|\tPosition  : x = %.3f ; y = %.3f ; z = %.3f\n",
		cylinder->position.x,
		cylinder->position.y,
		cylinder->position.z);
	printf("|\tDirection : x = %.3f ; y = %.3f ; z = %.3f\n",
		cylinder->direction.x,
		cylinder->direction.y,
		cylinder->direction.z);
	printf("|\tRadius    : %.3f\n",
		cylinder->radius);
	printf("|\tHeight    : %.3f\n",
		cylinder->height);
	printf("|\tColor     : r = %d ; g = %d ; b = %d ; trgb = %d\n\n",
		cylinder->color.r,
		cylinder->color.g,
		cylinder->color.b,
		cylinder->color.trgb);
}

void	print_structure(t_obj_list objs_list)
{
	size_t	i;

	i = 0;
	while (i < objs_list.nb_camera)
	{
		objs_list.camera[0].print((void *)&objs_list.camera[0]);
		i++;
	}
	i = 0;
	while (i < objs_list.nb_objs)
	{
		objs_list.objs[i].print((void *)&objs_list.objs[i]);
		i++;
	}
	objs_list.ambient.print((void *)&objs_list.ambient);
	i = 0;
	while (i < objs_list.nb_spot)
	{
		objs_list.spot[0].print((void *)&objs_list.spot[i]);
		i++;
	}
}
