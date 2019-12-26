/*
** EPITECH PROJECT, 2018
** check
** File description:
** coding
*/

#include "include.h"

void	check_hit(char **map)
{
	int	x = 0;
	int	y = 0;

	x = my_navy.my_save.cord_x - 'A';
	y = my_navy.my_save.cord_y - '1';
	if (map[y][x] != '.' || map[y][x] != 'x') {
		map[y][x] = 'x';
		my_navy.hit++;
		my_navy.hit_or_miss = 1;
		printf("%c%c : hit\n", my_navy.my_save.cord_x, my_navy.my_save.cord_y);
	}
	else if (map[y][x] == '.') {
		my_navy.hit_or_miss = 2;
		printf("%c%c : missed\n", my_navy.my_save.cord_x, my_navy.my_save.cord_y);
	}
}
