/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <errno.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <fcntl.h>

typedef struct c {
    char *tube;
    struct c *next;
} gilles;

int segfaut(int stat);
int error_setenv(char *str);
int commande(char **argums, gilles *liste, char **env);
int commande2(char **argums, gilles *liste, char **env);
int argument(char **argums);
int my_execvp(const char *file, char *const argv[], char **env, gilles *liste);
int verify(char str, char *chaine);
int count(char *av, int debut, int fin, char *str);
char *clean(char *av, char *str);
int compt_lignes(char *buffer, char *virg);
int compt_cols(char *buffer, char *virg);
char **double_tab(int lignes, int cols);
char **remply(char **tab, char *buffer, char *virg);
char **str_to_word_array(char *str, char *sepa);
void stok(char *str, int i);
int list(const char *str, gilles *list);
int my_execvp(const char *file, char *const argv[], char **env, gilles *liste);
void totot(char **argums, char **env, gilles *liste);
void binary(char *ok, char **argums, char **env);
int fonction(char *format, va_list ap, int t);
int my_printf(char *format, ...);
int argument(char **argums);
char *my_getenv(const char *nom, char **env);
char *my_getenv2(const char *nom, char **env);
int fonction(char *format, va_list ap, int t);
void affich_list(gilles **list);
int cleaneur(char *chaine);
char *my_strcat(char *f1, const char *f2);
int my_strlen(const char *str);
char *slash_remove(char *str);
int my_strncmp(char const *t1, char const *t2, int nb);
int my_strcmp(const char *s1, const char *s2);
gilles *my_unsetenv(gilles *li, char **str);
void add_to_end_of_list(gilles **list, char *new);
void free_malloc(gilles **list);
int my_putchar(char c);
int my_putstr(char const *str);
int func_principal(char *entrer, gilles *liste, char **env);
#endif
