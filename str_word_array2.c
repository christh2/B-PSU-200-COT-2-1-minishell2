/*
** EPITECH PROJECT, 2023
** double_tab
** File description:
** double_tab
*/

#include "my.h"

char **double_tab(int lignes, int cols)
{
    char **tab = NULL; tab = malloc(sizeof(char *) * (lignes + 1));
    for (int i = 0; i < lignes; i++) {
        tab[i] = malloc(sizeof(char) * (cols + 1));
    } return tab;
}

char **remply(char **tab, char *buffer, char *virg)
{
    int lines = compt_lignes(buffer, virg);
    int clos = compt_cols(buffer, virg);int x = 0;int y = 0;
    for (int i = 0;buffer[i] != '\0';i++) {
        if (verify(buffer[i], virg) == 1) {
            tab[x][y] = buffer[i];y++;
        } else {
            tab[x][y] = '\0';x++;y = 0;
        }
    }
    return tab;
}

char **str_to_word_array(char *str, char *sepa)
{
    char *tab = clean(str,sepa);
    int n = compt_lignes(tab, sepa);
    int c = compt_cols(tab, sepa);
    char **arr = double_tab(n, c);
    arr = remply(arr, tab, sepa);
    return arr;
}
