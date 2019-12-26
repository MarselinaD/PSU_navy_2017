/*
** EPITECH PROJECT, 2017
** strdup
** File description:
** file
*/

#include "include.h"

int	my_strlen(char const *str)
{
	int	i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*my_strdup(char const *str)
{
	int	i = 0;
	char	*string;

	string = malloc(sizeof(*string) * my_strlen(str));
	while (str[i] != '\0')
	{
		string[i] = str[i];
		i++;
	}
	return (string);
}
