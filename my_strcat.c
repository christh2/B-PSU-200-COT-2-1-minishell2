/*
** EPITECH PROJECT, 2023
** strncpy
** File description:
** snprintf
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int my_strlen(const char *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++);
    return i;
}

char *my_strcat(char *str1, const char *str2)
{
    int t1 = my_strlen(str1);
    int	t2 = my_strlen(str2);
    char *str = (char *)malloc(sizeof(char) * (t1 + t2 + 1));
    for (int x = 0; x < t1; x++)
        str[x] = str1[x];
    for (int x = 0; x <= t2; x++)
        str[x + t1] = str2[x];
    str[t1 + t2] = '\0';
    return str;
    free(str);
}

char *slash_remove(char *str)
{
    int j = 0;
    char *src = malloc(sizeof(char) * (my_strlen(str) - 1));
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != '\n') {
            src[j] = str[i]; j++;
        }
    return src;
    free(src);
}

int my_strncmp(char const *t1, char const *t2, int nb)
{
    for (int i = 0; i < nb; i++)
        if (t1[i] != t2[i])
            return 1;
    return 0;
}

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;
    for (i = 0; s1[i] == s2[i] && s1[i]; i++);
    return (s1[i] - s2[i]);
}
