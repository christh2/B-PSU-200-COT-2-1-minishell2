/*
** EPITECH PROJECT, 2023
** shell
** File description:
** shell1
*/

#include "my.h"

int my_execvp(const char *file, char *const argv[], char **env, gilles *liste)
{
    char *path = my_getenv("PATH", env);
    char *cmd;
    if (my_strcmp(argv[0], "echo") == 0 && argv[1][0] == '$') {
        list(&argv[1][1], liste);
        exit (0);
    }
    for (char *dir = strtok(path, ":"); dir != NULL; dir = strtok(NULL, ":")) {
        cmd = my_strcat(my_strcat(dir, "/"), file);
        if (access(cmd, X_OK) == 0) {
            execve(cmd, argv, env);
        }
    }
    binary((char *) file, (char **) argv, env);
    my_putstr(file); my_putstr(": Command not found.\n");
    exit(0);
}

int argument(char **argums)
{
    int i = 0;
    for (; argums[i] != NULL; i++);
    return i;
}

int commande2(char **argums, gilles *liste, char **env)
{
    if (my_strcmp(argums[0], "cd") == 0) {
        if (argums[1] == NULL || my_strcmp(argums[1], "~") == 0) {
            chdir(my_getenv("HOME", env));
        } else {
            char *y = ": No such file or directory.\n";
            (chdir(argums[1]) == -1 && errno == 2) ?
                my_putstr(my_strcat(argums[1],y)) : 0;
        }
        if (chdir(argums[1]) == -1 && errno == 20)
            my_putstr(my_strcat(argums[1], ": Not a directory.\n"));
        if (chdir(argums[1]) == -1 && errno == 13)
            my_putstr(": Permission denied.\n");
    }
}

int commande(char **argums, gilles *liste, char **env)
{
    if (my_strcmp(argums[0], "unsetenv") == 0) my_unsetenv(liste, argums);
    if (my_strcmp(argums[0], "env") == 0) affich_list(&liste);
    if (my_strcmp(argums[0], "setenv") == 0) {
        if ((argument(argums) > 1) && error_setenv(argums[1]) == 1)
            return 1;
        if (argument(argums) == 1)
            affich_list(&liste);
        if (argument(argums) == 2)
            add_to_end_of_list(&liste, my_strcat(argums[1], "="));
        if (argument(argums) == 3) {
            add_to_end_of_list(&liste, my_strcat(argums[1],
            my_strcat("=", argums[2])));
        }
    } commande2(argums, liste, env);
}

int main(int ac, char **av, char **env)
{
    gilles *liste = NULL; char *s1, *s2, *s3; int top = 0;
    for (int i = 0; env[i] != NULL; i++) add_to_end_of_list(&liste, env[i]);
    char *entrer = NULL; size_t len = 0; char *token; char *argums[128]; int i;
    while (1) {
        my_putstr("\033[33;1m[christ@christ]$\033[0m ");
        if (getline(&entrer, &len, stdin) == -1) break;
        char **meuf = str_to_word_array(entrer, ";");
        for (i = 0; meuf[i] != NULL; i++) {
            top = func_principal(meuf[i], liste, env);
        } if (top == 4) break;
    } free(entrer); return (EXIT_SUCCESS);
}
