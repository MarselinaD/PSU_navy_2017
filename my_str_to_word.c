/*
** EPITECH PROJECT, 2018
** my_str
** File description:
** coding
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	how_many_words(char *str, char delim)
{
	int	nb_word;
	int	i;

	nb_word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == delim) {
			nb_word++;
			while (str[i] == delim)
				i++;
		}
		i++;
	}
	return (nb_word + 1);
}

int	how_m_ch(char *str, int i, char delim)
{
	int	count;

	count = 0;
	while (str[i] != delim && str[i] != '\0') {
		count++;
		i++;
	}
	return (count);
}

char	**my_str_to_word(char *str, char delim)
{
	char	**a;
	int	line = 0;
	int	col = 0;
	int	i = 0;

	a = malloc(sizeof(*a) * how_many_words(str, delim) + 1);
	a[line] = malloc(sizeof(**a) * how_m_ch(str, i, delim) + 1);
	while (str[i] != '\0') {
		if (str[i] == delim) {
			a[line][col] = '\0';
			col = 0;
			line++;
			a[line] = malloc(sizeof(**a) * how_m_ch(str, i, delim) + 1);
		}
		if (str[i] != delim) {
			a[line][col] = str[i];
			col++;
		}
		i++;
	}
	line = line + 1;
	a[line] = NULL;
	return (a);
}
