/*
** EPITECH PROJECT, 2024
** day6
** File description:
** task 5
*/

#include <stdio.h>

char *my_strstr(char *str, char const *to_find)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == to_find[i]){
            i++;
        }
        if (to_find[i] == '\0')
            return str;
        str++;
        i--;
    }
    return NULL;
}
