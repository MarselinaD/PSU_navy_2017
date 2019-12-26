/*
** EPITECH PROJECT, 2018
** clear
** File description:
** coding
*/

#include <errno.h>
#include <stdio.h>
#include "include.h"

void	my_pid(void)
{
	my_putstr("my_pid:\t");
	my_put_nbr(getpid());
	my_putstr("\n");
	my_putstr("waiting for enemy connection...\n");
}

void	enemy_pid(void)
{
	my_putstr("my_pid:\t");
	my_put_nbr(getpid());
	my_putstr("\nsuccessfully connected\n\n");
}

char	*read_command(void)
{
	int	nb = 0;
	char	*buff = malloc(sizeof(*buff) * 16);;
	char	*str;

	my_bzero(buff, 16);
	nb = read(0, buff, 16);
	if (nb < 0) {
		write(2, "Read Error\n", strlen("Read Error\n"));
		return (NULL);
	}
	if (buff[0] < 'A' || buff[0] > 'H' || \
	buff[1] < '1' || buff[1] > '8')
		return (NULL);
	else {
		buff[2] = '\0';
		str = my_strdup(buff);
	}
	return (str);
}

void	sending_signal(char *attact)
{
	char	c;
	char	i;

	for (c = '@'; c != attact[0]; c++) {
		send_sig(SIGUSR1);
		usleep(500);
	}
	send_sig(SIGUSR2);
	usleep(500);
	for (i = '0'; i != attact[1]; i++) {
		send_sig(SIGUSR1);
		usleep(500);
	}
	send_sig(SIGUSR2);
}

void	reset_values(void)
{
	my_navy.finish_letter = 0;
	my_navy.finish_number = 0;
	my_navy.x = '@';
	my_navy.y = '0';
}

void	game_player(char **map, char **enemy_map)
{
	char	*attact;

	while (my_navy.hit < 14 && my_navy.hit_enemy < 14) {
		my_putstr("attack: ");
		attact = read_command();
		sending_signal(attact);
		usleep(500);
		my_navy.already_sent = 1;
		if (my_navy.hit < 14 && my_navy.hit_enemy < 14) {
			my_putstr("waiting for enemy's attact...\n");
			pause();
			my_navy.already_sent = 0;
		}
// You have to wait to know if is it HIT or MISS
		while (my_navy.hit_or_miss != -1);
		if (my_navy.hit_or_miss == 1)
			
		// if my_navy.hit_or_miss equals to 1 it mean hit
		// else if my_navy.hit_or_miss equals to 2 it mean miss
	        // According the value of hit_or_miss you have to set the right character to the enemy map
		my_navy.hit_or_miss = -1;
		usleep(500);
		display_map(map);
		display_map(enemy_map);
		while (my_navy.finish_letter == 0 || my_navy.finish_number == 0);
		check_hit(enemy_map);
		// Hit or mi
		usleep(500);
		reset_values();
	}
}

void	game_enemy(char **map, char **enemy_map)
{
	char	*attact;

	while (my_navy.hit < 14 && my_navy.hit_enemy < 14) {
		my_putstr("waiting for enemy's attact...\n");
		my_navy.already_sent = 0;
		while (my_navy.finish_letter == 0 || my_navy.finish_number == 0);
		check_hit(map);
		usleep(500);
		reset_values();
		my_putstr("attack: ");
		attact = read_command();
		sending_signal(attact);
		// You have to wait to know if is it HIT or MISS
		usleep(500);
		my_navy.already_sent = 1;
		while (my_navy.hit_or_miss != -1);
		// if my_navy.hit_or_miss equals to 1 it mean hit
		// else if my_navy.hit_or_miss equals to 2 it mean miss
	        // According the value of hit_or_miss you have to set the right character to the enemy map
		display_map(map);
		display_map(enemy_map);
	}
}
