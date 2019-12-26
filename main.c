/*
** EPITECH PROJECT, 2018
** main
** File description:
** coding
*/

#include "include.h"

void	usage(void)
{
	write(1, "USAGE\n\t", 7);
	write(1, "./navy [first_player_pid] navy", 30);
	write(1, "_positions\n", 11);
	write(1, "DESCRIPTION\n\t", 13);
	write(1, "first_player_pid:\tonly for the 2nd player.", 42);
	write(1, "\tpid of the first player.\n\t", 27);
	write(1, "navy_positions:\tfile representing the", 37);
	write(1, " positions of the ships.\n", 25);
}

int	file_exist(char const *file)
{
	int	fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	else
		return (0);
}

void	calling_sig(int ac, char **av)
{
	char	**map = NULL;
	char	**enemy;

	enemy = enemy_map();
	my_navy.x = '@';
	my_navy.y = '0';
	my_navy.finish_number = 0;
	my_navy.finish_letter = 0;
	my_navy.is_connect = 0;
	my_navy.hit_or_miss = -1;
	if  (ac == 2) {
		map = load_map(av[1]);
		my_pid();
		pause();
		send_sig(SIGUSR1);
		my_putstr("my positions:\n");
		display_map(map);
		display_map(enemy);
		game_player(map, enemy);
	}
	else if (ac == 3) {
		my_navy.pid_enemy = atoi(av[1]);
		map = load_map(av[2]);
		enemy_pid();
		send_sig(SIGUSR1);
		pause();
		my_putstr("my position:\n");
		display_map(map);
		display_map(enemy);
		game_enemy(map, enemy);
	}
}

int	main(int ac, char **av)
{
	if (ac == 1) {
		write(2, "Error, no argument!\n", 20);
		return (84);
	}
	else if (av[1][0] == '-' && av[1][1] == 'h')
		usage();
	else if ((ac == 2 && file_exist(av[1]) == 0) || (ac == 3 && \
						file_exist(av[2]) == 0)) {
		my_navy.pid_enemy = -1;
		my_signalone();
		calling_sig(ac, av);
	}
	else {
		return (84);
	}
	return (0);
}
