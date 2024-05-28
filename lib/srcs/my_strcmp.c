/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** my_strcmp.c
*/

#include "my.h"

int compare_strs(char *str1, char *str2)
{
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] > str2[i])
            return 1;
        if (str1[i] < str2[i])
            return -1;
    }
    return 0;
}

int my_strcmp(char *str1, char *str2)
{
    if (my_strlen(str1) > my_strlen(str2))
        return 1;
    else if (my_strlen(str1) < my_strlen(str2))
        return -1;
    return (compare_strs(str1, str2));
}

int comparen_strs(char *str1, char *str2, int n)
{
    for (int i = 0; str1[i] != '\0' && i < n; i++) {
        if (str1[i] > str2[i])
            return 1;
        if (str1[i] < str2[i])
            return -1;
    }
    return 0;
}

int my_strncmp(char *str1, char *str2, int n)
{
    return comparen_strs(str1, str2, n);
}
