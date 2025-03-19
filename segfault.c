/*
** EPITECH PROJECT, 2023
** seg
** File description:
** fault
*/

#include "my.h"

int segfaut(int stat)
{
    if (WIFSIGNALED(stat)) {
        if (WTERMSIG(stat) == SIGSEGV) {
            my_putstr("Segmentation fault\n");
            return (139);
        }
        if (WTERMSIG(stat) == SIGFPE) {
            my_putstr("Floating exception\n");
            return (136);
        }
    }
}

void totot(char **argums, char **env, gilles *liste)
{
    int seg;
    pid_t lol = fork();
    if (lol == 0) {
        my_execvp(argums[0], argums, env, liste);
    } else {
        waitpid(lol, &seg, 0);
        segfaut(seg);
    }
}
