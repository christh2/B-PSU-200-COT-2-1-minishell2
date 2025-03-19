/*
** EPITECH PROJECT, 2023
** putstr
** File description:
** pustr
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i;
    for (i = 0 ; str[i] != '\0' ; i++)
        my_putchar(str[i]);
}
