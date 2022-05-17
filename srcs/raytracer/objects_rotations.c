#include "miniRT.h"

/*
*
*/
void x_rotation_matrix(double rad, double ***m)
{
	*m[0][0] = 1;
	*m[0][1] = 0;
	*m[0][2] = 0;

	*m[1][0] = 0;
	*m[1][1] = cos(rad);
	*m[1][2] = -(sin(rad));

	*m[2][0] = 1;
	*m[2][1] = sin(rad);
	*m[2][2] = cos(rad);
}

void y_rotation_matrix(double rad, double ***m)
{
	*m[0][0] = cos(rad);
	*m[0][1] = 0;
	*m[0][2] = sin(rad);

	*m[1][0] = 0;
	*m[1][1] = 1;
	*m[1][2] = 0;

	*m[2][0] = -sin(rad);
	*m[2][1] = 0;
	*m[2][2] = cos(rad);
}

void z_rotation_matrix(double rad, double ***m)
{
	*m[0][0] = cos(rad);
	*m[0][1] = -(sin(rad));
	*m[0][2] = 0;

	*m[1][0] = sin(rad);
	*m[1][1] = cos(rad);
	*m[1][2] = 0;

	*m[2][0] = 0;
	*m[2][1] = 0;
	*m[2][2] = 1;
}

t_v3	la_matmut(double ***m, t_v3 p)
{
	t_v3 result;

	result.x = p.x * (*m[0][0]) + p.x * (*m[1][0]) + p.x * (*m[2][0]);
	result.y = p.y * (*m[0][1]) + p.y * (*m[1][1]) + p.y * (*m[2][1]);
	result.z = p.z * (*m[0][2]) + p.z * (*m[1][2]) + p.z * (*m[2][2]);
	return (result);
}

t_v3 rotate_vector(t_v3 t, double rad_x, double rad_y, double rad_z)
{
	double ***m;

	m = (double ***)malloc(sizeof(double) * 9);
	if (rad_x)
	{
		x_rotation_matrix(rad_x, m);
		t = la_matmut(m, t);
	}
	if (rad_y)
	{
		y_rotation_matrix(rad_y, m);
		t = la_matmut(m, t);
	}
	if (rad_z)
	{
		z_rotation_matrix(rad_z, m);
		t = la_matmut(m, t);
	}
	free(m);
	return (t);
}
