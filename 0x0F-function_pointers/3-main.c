#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - entry point of operator functions
 * @argc: 
 * @argv: 
 * 
 */

int main (int argc, char **argv)
{
	int x, z;
	char *y;
	int num;

	x = atoi(argv[1]);
	y = argv[2];
	z = atoi(argv[3]);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	if (!(*y == '+' || *y == '-'|| *y == '*' || *y == '/' || *y == '%'))
	{
		printf("Error\n");
		exit(99);
	}

	if ((y[0] == '/' || y[0] == '%') && (z == 0))
	{
		printf("Error\n");
		exit(100);
	}

	num = (get_op_func(y))(x, z);
	printf("%d\n", num);

	return (0);
}
