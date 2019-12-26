/*
** EPITECH PROJECT, 2018
** check
** File description:
** coding
*/

#include "include.h"

int	check(char *str)
{
	if (str[0] < '2' && str[0] > '5')
		return (-1);
	else if (str[1] != ':' || str[4] != ':')
		return (-1);
	else if (str[2] < 'A' || str[2] > 'H' || str[5] < 'A' || str[5] > 'H')
		return (-1);
	else if (str[3] < '1' || str[3] > '8' || str[6] < '1' || str[6] > '8')
		return (-1);
	else if (str[6] == str[3] && str[5] - str[2] != (str[0] - 48) - 1)
		return (-1);
	else if (str[6] - str[3] != (str[0] - 48) - 1 && str[5] == str[2])
		return (-1);
	return (0);
}

int	check_array(char **array)
{
	int	line = 0;

	while (array[line] != NULL) {
		if (my_strlen(array[line]) != 7) {
			write(2, "Wrong position 1\n", 17);
			return (-1);
		}
		else if (check(array[line]) == -1) {
			write(2, "Wrong position 2\n", 17);
			return (-1);
		}
		line++;
	}
	return (0);
}
