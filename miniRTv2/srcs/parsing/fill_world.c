/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:22:46 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 12:26:06 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	get_line_content(char *line, t_obj_list *obj_list, t_world *world,
	size_t *index)
{
	char	**splitted_line;
	int		error;

	splitted_line = ft_split(line, ' ');
	if (!splitted_line)
		return (rt_error("Split failed."));
	error = 0;
	if (ft_strcmp(splitted_line[0], "sp") == 0)
		obj_list->objs[(index[0])++] = new_sphere(splitted_line, &error);
	else if (ft_strcmp(splitted_line[0], "pl") == 0)
		obj_list->objs[(index[0])++] = new_plan(splitted_line, &error);
	else if (ft_strcmp(splitted_line[0], "cy") == 0)
		obj_list->objs[(index[0])++] = new_cylinder(splitted_line, &error);
	else if (ft_strcmp(splitted_line[0], "C") == 0)
		world->camera[(index[1])++] = new_camera(splitted_line, &error);
	else if (ft_strcmp(splitted_line[0], "A") == 0)
		world->light_list.ambient = new_ambient(splitted_line, &error);
	else if (ft_strcmp(splitted_line[0], "L") == 0)
		world->light_list.spot_light[(index[2])++]
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
		return (rt_error("Could not open the scene."));
	error = false;
	index[0] = 0;
	index[1] = 0;
	index[2] = 0;
	while (1)
	{
		line = gnl_without_bn(file_descriptor);
		if (!line)
			break ;
		if (error == false
			&& get_line_content(line, &world->obj_list, world, index))
			error = true;
		free(line);
	}
	close(file_descriptor);
	if (error == true)
		return (1);
	return (0);
}
