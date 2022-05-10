#include <stdio.h>

typedef void	(*t_func)(void);

typedef struct	s_obj {
	t_func	intersection;
}	t_obj;

void	print_sphere(void)
{
	printf("Sphere\n");
}

void	print_cylinder(void)
{
	printf("Cylinder\n");
}

int	main(void)
{
	t_obj	sphere;
	t_obj	cylinder;

	sphere.intersection = &print_sphere;
	cylinder.intersection = &print_cylinder;
	sphere.intersection();
	cylinder.intersection();
}
