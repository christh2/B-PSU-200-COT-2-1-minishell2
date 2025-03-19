/*
** EPITECH PROJECT, 2023
** separer
** File description:
** separer
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int verify(char str, char *chaine);

int count(char *av, int debut, int fin, char *str)
{
    int i = 1; int k;int a = 0;
    for (k = debut; k <= fin; k++) {
        if ((verify(av[k], str) == 1)
            && (verify(av[k], str) == 1)) {
            a++;
        }
        if ((verify(av[k], str) == 1)
            && (verify(av[k + 1], str) == 1)) {
            a += 2;
        }
    } return a;
}

char *clean(char *av, char *str)
{
    int taille = strlen(av); int debut, fin; int j, i = 1; char *tab;
    for (j = 0; j < taille; j++) {
        if (verify(av[j], str) == 1) {
            debut = j; break;
        }
    } fin = taille - 1;
    for (j = fin; j >= 0; j--) {
        if (verify(av[j], str) == 1) {
            fin = j; break;
        }
    }
    int k; i = 1; int n = count(av, debut, fin, str);
    tab = malloc(sizeof(char) * n);int d = 0;
    for (k = debut; k <= fin; k++) {
        if ((verify(av[k],str) == 1) && (verify(av[k + 1], str) == 1)) {
            tab[d] = av[k]; d++;
        } if ((verify(av[k], str) == 1) && (verify(av[k + 1], str) == 2)) {
            tab[d] = av[k];d++;tab[d] = av[k + 1];d++;
        }
    } return tab;
}

int verify(char str, char *chaine)
{
    for (int i = 0; chaine[i] != '\0'; i++)
        if (chaine[i] == str)
            return 2;
    if (str == '\0')
        return 2;
    return 1;
}

int compt_lignes(char *buffer, char *virg)
{
    int i = 0;
    int j = 0;
    for (; buffer[i] != '\0'; i++){
        if (verify(buffer[i], virg) == 1 && verify(buffer[i + 1], virg) == 2)
            j++;
    }
    return j;
}

int compt_cols(char *buffer, char *virg)
{
    int i = 0, j = 0; int mx = 0;
    for (;buffer[i] != '\0'; i++) {
        j++;
        if (verify(buffer[i], virg) == 1 && verify(buffer[i + 1], virg) == 2) {
            (j > mx) ? mx = j : mx;
            j = 0;
        }
    }
    return mx - 1;
}
