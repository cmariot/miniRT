/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:28:57 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/11 08:34:55 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	get_line_content(char *line, t_scene *rt_scene)
{
	char	**splitted_line;

	splitted_line = ft_split(line, ' ');
	if (!splitted_line)
		return (rt_error("Split failed.", true));
	if (ft_strcmp(splitted_line[0], "A") == 0)
		return (fill_ambient_light(splitted_line, &rt_scene->ambient_light));
	else if (ft_strcmp(splitted_line[0], "C") == 0)
		return (fill_camera(splitted_line, &rt_scene->camera));
	else if (ft_strcmp(splitted_line[0], "L") == 0)
		return (fill_light(splitted_line, &rt_scene->light));
	else if (ft_strcmp(splitted_line[0], "sp") == 0)
		return (fill_sphere(splitted_line,
				&(rt_scene->elements.index_sphere),
				&(rt_scene->sphere[rt_scene->elements.index_sphere])));
	else if (ft_strcmp(splitted_line[0], "pl") == 0)
		return (fill_plan(splitted_line,
				&(rt_scene->elements.index_plan),
				&(rt_scene->plan[rt_scene->elements.index_plan])));
	else if (ft_strcmp(splitted_line[0], "cy") == 0)
		return (fill_cylinder(splitted_line,
				&(rt_scene->elements.index_cylinder),
				&(rt_scene->cylinder[rt_scene->elements.index_cylinder])));
	ft_free_array(splitted_line);
	return (0);
}

int	fill_structure(t_scene *rt_scene, const char *filename)
{
	int		file_descriptor;
	char	*line;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (rt_error("Could not open the scene.", true));
	while (1)
	{
		line = gnl_without_bn(file_descriptor);
		if (!line)
			break ;
		if (get_line_content(line, rt_scene))
		{
			free(line);
			close(file_descriptor);
			return (1);
		}
		free(line);
	}
	close(file_descriptor);
	return (0);
}
