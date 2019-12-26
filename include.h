/*
** EPITECH PROJECT, 2018
** include
** File description:
** coding
*/

#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ucontext.h>

typedef	struct	save {
	char	cord_x;
	char	cord_y;
}		save_t;

typedef	struct	pos {
	int	x;
	int	y;
}	pos_t;

typedef	struct	navy {
	int	pid_enemy;
	int	pid;
	int	hit;
	int	is_connect;
	int	finish_letter;
	int	finish_number;
	int	already_sent;
	char	x;
	char	y;
	int	hit_or_miss;
	save_t	my_save;
	int	hit_enemy;
}		navy_t;

navy_t	my_navy;

char	**my_str_to_word(char *str, char delim);
char	*my_strdup(char const *str);
void	my_putchar(char c);
void	my_putstr(char *str);
void	my_bzero(char *str, int len);
int	my_strlen(char const *str);
int	my_put_nbr(int nb);
void	my_pid();
void	enemy_pid();
char	*read_file(char const *filepath);
int	how_many_line(char *str);
int	check(char *str);
int	check_array(char **array);
void	display_map(char **map);
char	**split_position(char *filepath);
char	**my_map(char **array);
char	**enemy_map();
void	send_sig(int sig);
void	my_receive(int nb, siginfo_t *sig, void *c);
char	**load_map(char *filepath);
void	my_signalone(void);
void	game_player(char **m, char **en);
void	game_enemy(char **m, char **e);
int	file_exist(char const *file);
int	my_atoi(char *str);
char	*get_next_line(int fd);
void	check_hit(char **map);

#endif
