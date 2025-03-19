/*
** EPITECH PROJECT, 2023
** setenv
** File description:
** setenv
*/

#include "my.h"

void stok(char *str, int i)
{
    char *jo = malloc(sizeof(char) * my_strlen(str) - i);
    int j = 0;int x;
    for (; str[j] != '='; j++);
    j++;
    for (x = 0; str[j] != '\0'; x++, j++)
        jo[x] = str[j];
    jo[x] = '\0';
    my_putstr(jo);
    my_putstr("\n");
    free(jo);
}

int list(const char *str, gilles *list)
{
    if (list == NULL)
        return 0;
    gilles *unset = list;
    gilles *tmp = unset->next;
    while (tmp != NULL) {
        if ((my_strncmp(tmp->tube, str, my_strlen(str))) == 0) {
            stok(tmp->tube, my_strlen(str));
            break;
        } unset = tmp; tmp = tmp->next;
    }
}

gilles *my_unsetenv(gilles *list, char **str)
{
    if (list == NULL)
        return list;
    gilles *unset = list;
    if ((my_strncmp(unset->tube, str[1], my_strlen(str[1]))) == 0) {
        list = unset->next;
        free(unset);
        return list;
    } gilles *tmp = unset->next;
    while (tmp != NULL) {
        if ((my_strncmp(tmp->tube, str[1], my_strlen(str[1]))) == 0) {
            unset->next = tmp->next;
            free(tmp);
            return list;
        } unset = tmp; tmp = tmp->next;
    } return list;
}

void add_to_end_of_list(gilles **list, char *new)
{
    gilles *tmp = *list;
    if (tmp != NULL) {
        for (; tmp->next != NULL; tmp = tmp->next);
        gilles *noeud = malloc(sizeof(gilles));
        noeud->tube = new;
        noeud->next = NULL;
        tmp->next = noeud;
    } else {
        gilles *noeud = malloc(sizeof(gilles));
        noeud->tube = new;
        noeud->next = NULL;
        *list = noeud;
    }
}

void affich_list(gilles **list)
{
    gilles *tmp = *list;
    for (; tmp != NULL; tmp = tmp->next) {
        my_putstr(my_strcat(tmp->tube, "\n"));
    }
}
