/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** coding
*/

#include "include.h"

int	my_nbr_length(int nb)
{
	if (nb >= 10) {
		my_nbr_length(nb / 10);
	}
	if (nb > 0) {
		my_putchar((nb % 10) + '0');
	}
	return (0);
}

int	my_put_nbr(int nb)
{
	if (nb == 0) {
		my_putchar('0');
	}
	if (nb < 0) {
		my_putchar('-');
		nb = -nb;
	}
	my_nbr_length(nb);
	return (0);
}
