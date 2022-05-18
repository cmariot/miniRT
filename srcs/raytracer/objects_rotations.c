#include "miniRT.h"

/*
*
*/
static void x_rotation_matrix(double rad, double *m)
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;

	m[3] = 0;
	m[4] = cos(rad);
	m[5] = -(sin(rad));

	m[6] = 1;
	m[7] = sin(rad);
	m[8] = cos(rad);
}

static void y_rotation_matrix(double rad, double *m)
{
	m[0] = cos(rad);
	m[1] = 0;
	m[2] = sin(rad);

	m[3] = 0;
	m[4] = 1;
	m[5] = 0;

	m[6] = -sin(rad);
	m[7] = 0;
	m[8] = cos(rad);
}

static void z_rotation_matrix(double rad, double *m)
{
	m[0] = cos(rad);
	m[1] = -(sin(rad));
	m[2] = 0;

	m[3] = sin(rad);
	m[4] = cos(rad);
	m[5] = 0;

	m[6] = 0;
	m[7] = 0;
	m[8] = 1;
}

static t_v3	la_matmut(double *m, t_v3 p)
{
	t_v3 result;

	result.x = p.x * (m[0]) + p.x * (m[3]) + p.x * (m[6]);
	result.y = p.y * (m[1]) + p.y * (m[4]) + p.y * (m[7]);
	result.z = p.z * (m[2]) + p.z * (m[5]) + p.z * (m[8]);
	return (result);
}

// static double ***empty_mat(void)
// {
// 	double **main;
// 	main = malloc(sizeof(double*) * 3);
// }

static void rotate_vector(t_v3 *t, double rad_x, double rad_y, double rad_z)
{
	double *m;

	m = (double *)malloc(sizeof(double) * 9);
	if (rad_x)
	{
		x_rotation_matrix(rad_x, m);
		*t = la_matmut(m, *t);
	}
	if (rad_y)
	{
		y_rotation_matrix(rad_y, m);
		*t = la_matmut(m, *t);
	}
	if (rad_z)
	{
		z_rotation_matrix(rad_z, m);
		*t = la_matmut(m, *t);
	}
	// (void)rad_z;
	free(m);
	// return (t);
}

void rotate_all(t_obj_list *obj_list, t_cam *cam)
{
	size_t	i;
	double x,y,z;

	x = (cam->direction.x);
	y = (cam->direction.y);
	z = (cam->direction.z);
	i = 0;
	while (i < obj_list->nb_obj)
	{
		if (obj_list->obj[i].type == sphere)
			rotate_vector(&(obj_list->obj[i].position), x, y, 0);
		else if (obj_list->obj[i].type == cylindre)
		{
			rotate_vector(&(obj_list->obj[i].position), x, y, 0);
			rotate_vector(&(obj_list->obj[i].ext1), x, y, 0);
			rotate_vector(&(obj_list->obj[i].ext2), x, y, 0);
		}
		// else if (obj_list->obj[i].type == plan)
		// 	rotate_vector(&(obj_list->obj[i].position),  x, y, z);
		i++;
	}
	// rotate_vector(&(obj_list->light.position), x, y, z);
	cam->direction.x = 0;
	cam->direction.y = 0;
	cam->direction.z = 1;
}
