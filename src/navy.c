/*
** EPITECH PROJECT, 2020
** navy.c
** File description:
** main source file for navy project
*/

#include "../include/navy.h"
#include <signal.h>
#include <sys/stat.h>

void signal_handler(int signal, siginfo_t *info, void *blabla)
{
    PID = info->si_pid;
    my_putstr("enemy connected\n");
}

int connect_one(player_t *player, struct sigaction sa)
{
    display_pid(player->my_pid);
    my_putstr("waiting for enemy connection...\n\n");
    sigaction(SIGUSR2, &sa, NULL);
    pause();
    return (0);
}

int connect_two(player_t *player, struct sigaction sa)
{
    display_pid(player->my_pid);
    if (kill(player->his_pid, SIGUSR2) == -1) {
        my_putstr("INVALID PID\n");
        return (84);
    }
    my_putstr("sucessfully connected\n");
    player->win_cond = 0;
    return (0);
}

int navy_player_one(player_t *player)
{
    struct sigaction sa;
    sa.sa_sigaction = &signal_handler;
    sa.sa_flags = SA_SIGINFO;
    connect_one(player, sa);
    display_my_map(player->map);
    display_enemy_map(player->enemy_map);
    return (0);
}

int navy_player_two(player_t *player)
{
    struct sigaction sa;
    sa.sa_sigaction = &signal_handler;
    sa.sa_flags = SA_SIGINFO;
    if (connect_two(player, sa) == 84)
        return (84);
    display_my_map(player->map);
    display_enemy_map(player->enemy_map);
    return (0);
}

int main(int ac, char **av)
{
    player_t player;

    if (ac != 2 && ac != 3) {
        return (84);
    }
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            display_help();
            return (0);
        }
        if (my_init_player_one(&player, av) == 84)
            return (84);
        if (navy_player_one(&player) == 84)
            return (84);
    } else {
        if (my_init_player_two(&player, av) == 84)
            return (84);
        if (navy_player_two(&player) == 84)
            return (84);
    }
    return (0);
}
