/*
** EPITECH PROJECT, 2018
** load map
** File description:
** coding
*/

#include "include.h"

char	*read_file(char const *filepath)
{
	int	fd;
	int	len;
	char	*str;
	char	buff[32];

	fd = open(filepath, O_RDONLY);
	if (fd == -1) {
		write(2, "Error the file\n", 15);
		return (NULL);
	}
	else {
		len = 1;
		my_bzero(buff, 32);
		while (len > 0) {
			len = read(fd, buff, 32);
			str = my_strdup(buff);
		}
	}
	return (str);
}

int	how_many_line(char *str)
{
	int	i = 0;
	int	count = 0;

	while (str[i] != '\0') {
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

char	**split_position(char *filepath)
{
	int	i = 0;
	char	*str;
	char	**array = NULL;

	str = read_file(filepath);
	if (str == NULL)
		return (NULL);
	array = malloc(sizeof(*array) * how_many_line(str) + 1);
	while (str[i] != '\0')
	{
		array = my_str_to_word(str, '\n');
		i++;
	}
	if (check_array(array) == -1)
		return (NULL);
	return (array);
}

char	**load_map(char *filename)
{
	char	**array = NULL;
	char	**map = NULL;

	array = split_position(filename);
	if (array != NULL) {
		map = my_map(array);
	}
	return (map);
}
