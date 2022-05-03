/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:22:46 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 16:45:36 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

#define OBJ		0
#define CAM		1
#define LIGHT	2

int	set_world(t_world *world, t_obj_list *obj_list,
	char *line, size_t *index)
{
	char	**splitted_line;
	int		error;

	splitted_line = ft_split(line, ' ');
	if (!splitted_line)
		return (rt_error("The ft_split function failed in set_world()"));
	error = 0;
	if (!ft_strcmp(*splitted_line, "sp"))
		obj_list->objs[index[OBJ]++] = new_sphere(splitted_line, &error);
	else if (!ft_strcmp(*splitted_line, "pl"))
		obj_list->objs[index[OBJ]++] = new_plan(splitted_line, &error);
	else if (!ft_strcmp(*splitted_line, "cy"))
		obj_list->objs[index[OBJ]++] = new_cylinder(splitted_line, &error);
	else if (!ft_strcmp(*splitted_line, "C"))
		world->camera[index[CAM]++] = new_camera(splitted_line, &error);
	else if (!ft_strcmp(*splitted_line, "A"))
		world->light_list.ambient = new_ambient(splitted_line, &error);
	else if (!ft_strcmp(*splitted_line, "L"))
		world->light_list.spot_light[index[LIGHT]++]
			= new_light(splitted_line, &error);
	ft_free_array(splitted_line);
	return (error);
}

int	fill_world(t_world *world, const char *filename)
{
	int		file_descriptor;
	char	*line;
	size_t	index[3];
	bool	error;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (rt_error("The scene file can't be open."));
	error = false;
	index[OBJ] = 0;
	index[CAM] = 0;
	index[LIGHT] = 0;
	while (1)
	{
		line = gnl_without_bn(file_descriptor);
		if (!line)
			break ;
		if (error == false && set_world(world, &world->obj_list, line, index))
			error = true;
		free(line);
	}
	close(file_descriptor);
	if (error == true)
		return (1);
	return (0);
}
