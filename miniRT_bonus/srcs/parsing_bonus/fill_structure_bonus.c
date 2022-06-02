/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:22:46 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/21 19:54:29 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

#define OBJ 0
#define LIGHT 1

static int	set_world(t_obj_list *obj_list, char *line, size_t *index)
{
	char	**splitted_line;
	int		ret;

	splitted_line = ft_split(line, ' ');
	if (!splitted_line)
		return (rt_error("The ft_split function failed in set_world()"));
	ret = 0;
	if (!ft_strcmp(*splitted_line, "sp"))
		ret = new_sphere(&obj_list->obj[index[OBJ]++], splitted_line);
	else if (!ft_strcmp(*splitted_line, "pl"))
		ret = new_plan(&obj_list->obj[index[OBJ]++], splitted_line);
	else if (!ft_strcmp(*splitted_line, "cy"))
		ret = new_cylinder(&obj_list->obj[index[OBJ]++], splitted_line);
	else if (!ft_strcmp(*splitted_line, "tr"))
		ret = new_triangle(&obj_list->obj[index[OBJ]++], splitted_line);
	else if (!ft_strcmp(*splitted_line, "C"))
		ret = new_camera(&obj_list->camera, splitted_line);
	else if (!ft_strcmp(*splitted_line, "A"))
		ret = new_ambient(&obj_list->ambient, splitted_line);
	else if (!ft_strcmp(*splitted_line, "L"))
		ret = new_light(&obj_list->light[index[LIGHT]++], splitted_line);
	ft_free_array(splitted_line);
	return (ret);
}

int	fill_structure(t_world *world, const char *filename)
{
	int		file_descriptor;
	char	*line;
	size_t	index[2];
	bool	error;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (rt_error("The scene file can't be open."));
	error = false;
	ft_bzero(index, sizeof(size_t) * 2);
	while (1)
	{
		line = gnl_without_bn(file_descriptor);
		if (!line)
			break ;
		if (error == false && set_world(&world->obj_list, line, index))
			error = true;
		free(line);
	}
	close(file_descriptor);
	if (error == true)
		return (1);
	return (0);
}
