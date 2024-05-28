/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** my_strcpy.c
*/

char *my_strcpy(char *str, char *dest)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        dest[i] = str[i];
    dest[i] = '\0';
    return (dest);
}

char *my_strncpy(char *str, char *dest, int len)
{
    int i = 0;

    for (; str[i] != '\0' && i < len; i++)
        dest[i] = str[i];
    dest[i] = '\0';
    return (dest);
}
