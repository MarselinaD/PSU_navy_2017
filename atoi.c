/*
** EPITECH PROJECT, 2017
** atoi
** File description:
** coding
*/

#include <stdlib.h>

int	my_atoi(char *str)
{
	int	i = 0;
	int	res = 0;

	while (str[i] != '\0')
	{
		res = res + (str[i] - 48);
		res = res * 10;
		i++;
	}
	res = res / 10;
	return (res);
}
