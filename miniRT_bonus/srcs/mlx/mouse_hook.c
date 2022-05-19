/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 08:45:35 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 13:01:01 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	mouse_hook(int mouse_code, void *ptr)
{
	(void)ptr;
	if (mouse_code == 1)
		printf("LEFT_CLICK\n");
	else
		printf("MOUSE_CODE = %d\n", mouse_code);
	return (0);
}
