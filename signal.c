/*
** EPITECH PROJECT, 2018
** signal
** File description:
** coding
*/

#include "include.h"
#include <stdio.h>

void	send_sig(int sig)
{
	kill(my_navy.pid_enemy, sig);
}

void	my_receive(int nb, siginfo_t *sig, void *c)
{
	(void)c;
	if (nb == SIGUSR1 && my_navy.is_connect == 0) {
		my_navy.is_connect = 1;
		if (my_navy.pid_enemy == -1) {
			my_navy.pid_enemy = sig->si_pid;
			my_putstr("\nenemy connected\n\n");
			send_sig(SIGUSR1);
		}
	}
	else if (my_navy.is_connect == 1 && my_navy.finish_letter == 0 && nb == SIGUSR1)
		my_navy.x++;
	else if (nb == SIGUSR2 && my_navy.finish_letter == 0)
		my_navy.finish_letter = 1;
	else if (my_navy.is_connect == 1 && my_navy.finish_number == 0 && nb == SIGUSR1)
		my_navy.y++;
	else if (nb == SIGUSR2 && my_navy.finish_number == 0)
		my_navy.finish_number = 1;
	else if (nb == SIGUSR1 && my_navy.finish_number == 1 && my_navy.finish_letter == 1 && my_navy.hit_or_miss == -1)
		my_navy.hit_or_miss = 1;
		else if (nb == SIGUSR1 && my_navy.finish_number == 1 && my_navy.finish_letter == 1 && my_navy.hit_or_miss == -1)
			my_navy.hit_or_miss = 2;
	if (my_navy.finish_letter == 1 && my_navy.finish_number == 1) {
		my_navy.my_save.cord_x = my_navy.x;
		my_navy.my_save.cord_y = my_navy.y;
	}
}

void	my_signalone(void) 
{
	struct	sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_sigaction = &my_receive;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}
