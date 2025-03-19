/*
** EPITECH PROJECT, 2023
** principal
** File description:
** principal
*/

#include "my.h"

int func_principal(char *entrer, gilles *liste, char **env)
{
    int i; char *token; char **argums;
    if (my_strlen(entrer) == 1) return 3;
    i = 0; argums = str_to_word_array(entrer, " \t\n");
    if (my_strcmp(argums[0], "exit") == 0){my_putstr("exit\n"); return 4;}
    if (my_strcmp(argums[0], "env") == 0 ||
        my_strcmp(argums[0], "unsetenv") == 0 ||
        my_strcmp(argums[0], "setenv") == 0 ||
        my_strcmp(argums[0], "cd") == 0) {
        commande(argums, liste, env); return 3;
    } totot(argums, env, liste);
    return 3;
}

int error_setenv(char *str)
{
    char *t = "setenv: Variable name must contain alphanumeric characters.\n";
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')
            && i == 0) {
            write(1, "setenv: Variable name must begin with a letter.\n", 48);
            return 1;
        }
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')
            && i != 0) {
            my_putstr(t);
            return 1;
        }
    }
}
