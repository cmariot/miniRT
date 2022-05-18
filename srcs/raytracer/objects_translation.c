#include "miniRT.h"

/*
*
*/
static void translate(t_v3 *target, t_v3 value)
{
	target->x -= value.x;
	target->y -= value.y;
	target->z -= value.z;
}

void translate_all(t_obj_list *obj_list, t_cam *cam)
{
	size_t	i;

	i = 0;
	while (i < obj_list->nb_obj)
	{
		if (obj_list->obj[i].type == sphere)
			translate(&(obj_list->obj[i].position), cam->position);
		 else if (obj_list->obj[i].type == cylindre)
		 {
		 	translate(&(obj_list->obj[i].position), cam->position);
		 	translate(&(obj_list->obj[i].ext1), cam->position);
		 	translate(&(obj_list->obj[i].ext2), cam->position);
		 }
		else if (obj_list->obj[i].type == plan)
			translate(&(obj_list->obj[i].position), cam->position);
		i++;
	}
	translate(&(obj_list->light.position), cam->position);
	cam->position.x = 0;
	cam->position.y = 0;
	cam->position.z = 0;
}
