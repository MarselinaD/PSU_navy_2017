/*
** EPITECH PROJECT, 2018
** funxion
** File description:
** coding
*/

#include "include.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_putstr(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
	{
		my_putchar(str[i]);
		i++;
	}
}

void	my_bzero(char *str, int len)
{
	int	i = 0;

	while (i < len) {
		str[i] = '\0';
		i++;
	}
}
