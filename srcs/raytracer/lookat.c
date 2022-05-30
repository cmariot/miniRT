/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:14:56 by rballage           #+#    #+#            */
/*   Updated: 2022/05/20 19:16:12 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	lookat(t_v3 cam_dir, double *m)
{
	t_v3	placeholder;
	t_v3	right;
	t_v3	up;

	placeholder.x = 0;
	placeholder.y = 1;
	placeholder.z = 0;
	if (cam_dir.x == 0 && cam_dir.z == 0)
		placeholder.z = 0.000001;
	right = normalize(cross(placeholder, cam_dir));
	up = normalize(cross(cam_dir, right));
	*(t_v3 *)(&m[0]) = right;
	*(t_v3 *)(&m[3]) = up;
	*(t_v3 *)(&m[6]) = cam_dir;
}
