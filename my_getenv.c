/*
** EPITECH PROJECT, 2023
** getenv
** File description:
** getenv
*/

#include "my.h"

char *my_getenv2(const char *nom, char **env)
{
    int i, len; len = my_strlen(nom);
    for (i = 0; env[i] != NULL; i++) {
        if (my_strncmp(nom, env[i], len) == 0) {
            my_putstr(env[i]);
        }
    } return NULL;
}

char *my_getenv(const char *nom, char **env)
{
    int i, len; len = my_strlen(nom);
    for (i = 0; env[i] != NULL; i++) {
        if (my_strncmp(nom, env[i], len) == 0 &&
            env[i][len] == '=') {
            return &env[i][len + 1];
        }
    } return NULL;
}

void binary(char *ok, char **argums, char **env)
{
    if (ok[0] == '.' && ok[1] == '/') {
        if (access(argums[0], X_OK) == 0) {
            execve(argums[0], argums, env);
        }
    }
}

void free_malloc(gilles **list)
{
    gilles *tmp = *list;
    gilles *tmp2;
    for (; tmp != NULL; tmp = tmp->next) {
        tmp2 = tmp;
        tmp = tmp->next;
        free(tmp2);
    }
}
