/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** my.h
*/

#pragma once

#include <stdbool.h>
#include <stddef.h>
#include "color.h"

#define ABS(value) ((value > 0) ? (value) : (-(value)))

int my_strlen(char *str);
int my_strcmp(char *first_str, char *second_str);
int my_strncmp(char *first_str, char *second_str, int n);
void my_putstr(char *str);
int my_getnbr(char *str);
char *my_convert_base(char *nbr, char *base_from, char *base_to);
char *add_char_pos(char *str, char c, int position);
char *my_strdup(char *str);
char *my_strcpy(char *str, char *dest);
void my_putchar(char c);
void my_putnbr(int nb);
char *my_strncpy(char *str, char *dest, int len);
char *my_strndup(char *str, int len);
long my_getlongnbr(char const *str);
char *my_strcat(char *dest, char *src);
void my_putstr_error(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
char *my_strncat(char *dest, char const *src, int nb);
size_t my_strspn(const char *string, char *valid_chars);
char *my_strchr(const char *s, int c);
char *my_strstr(char *str, char const *to_find);
void *my_memcpy(void *dest, const void *src, size_t len);
