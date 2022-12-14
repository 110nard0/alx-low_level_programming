#include "3-calc.h"
#include <stdio.h>
/**
  * get_op_func - selects the correct function to perform an operation
  * @s: operator passed to function
  * Return: pointer to corresponding operator function
  */

int (*get_op_func(char *s))(int, int)
{
	int i = 0;
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};

	while (ops[i].op != NULL)
	{
		if (*s == *(ops + i)->op)
			return (ops[i].f);
		i++;
	}

	return (NULL);
}
