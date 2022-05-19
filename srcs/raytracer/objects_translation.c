#include "miniRT.h"

/*
*
*/

typedef struct s_m4 {
	double	m[16];
}	t_m4;

void	create_matrix(t_m4 *matrix, double x, double y, double z)
{
	ft_bzero(matrix, sizeof(double) * 16);
	matrix->m[0] = 1;
	matrix->m[5] = 1;
	matrix->m[10] = 1;
	matrix->m[15] = 1;
	matrix->m[3] = x;
	matrix->m[7] = y;
	matrix->m[11] = z;
}

static void translate(t_v3 *target, t_v3 value)
{
	target->x -= value.x;
	target->y -= value.y;
	target->z -= value.z;
}

void translate_all(t_obj_list *obj_list, t_cam *cam)
{
	size_t	i;
	t_m4	translation_matrix;

	create_matrix(&translation_matrix, cam->position.x, cam->position.y, cam->position.z);
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
