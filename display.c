/*
** EPITECH PROJECT, 2018
** display
** File description:
** coding
*/

#include "include.h"

void	display_map(char **map)
{
	int	y = 0;
	int	x;

	my_putstr(" |A B C D E F G H\n");
	my_putstr("-+---------------\n");
	while (map[y] != NULL)
	{
		x = 0;
		my_put_nbr(y + 1);
		my_putchar('|');
		while (map[y][x] != '\0')
		{
			my_putchar(map[y][x]);
			my_putchar(' ');
			x++;
		}
		my_putchar('\n');
		y++;
	}
	my_putchar('\n');
}

char	*init_line(void)
{
	int	i = 0;
	char	*str;

	str = malloc(sizeof(*str) * 8);
	while (i < 8)
	{
		str[i] = '.';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**enemy_map(void)
{
	char	**mymap = NULL;
	int	line = 0;

	mymap = malloc(sizeof(*mymap) * 8);
	while (line != 8) {
		mymap[line] = init_line();
		line++;
	}
	mymap[line] = NULL;
	return (mymap);
}

char	**my_map(char **array)
{
	pos_t	start;
	pos_t	end;
	char	**map;
	int	line = 0;

	map = malloc(sizeof(*map) * 8);
	while (line != 8) {
		map[line] = init_line();
		line++;
	}
	map[line] = NULL;
	line = 0;
	while (array[line] != NULL) {
		if ((array[line][5] - 'A') - (array[line][2] - 'A') == \
		array[line][0] - 49 && array[line][6] == array[line][3]) {
			start.x = array[line][2] - 'A';
			start.y = array[line][3] - 49;
			end.x = array[line][5] - 'A';
			end.y = array[line][3] - 49;
			while (start.x <= end.x) {
				map[start.y][start.x] = array[line][0];
				start.x++;
			}
		}
		else if (array[line][6] - array[line][3] == array[line][0] - \
			49 && array[line][5] == array[line][2]) {
			start.x = array[line][2] - 'A';
			start.y = array[line][3] - 49;
			end.x = array[line][2] - 'A';
			end.y = array[line][6] - 49;
			while (start.y <= end.y) {
				map[start.y][start.x] = array[line][0];
				start.y++;
			}
		}
		line++;
	}
	return (map);
}
