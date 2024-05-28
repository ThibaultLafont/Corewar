/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** my_memcpy.c
*/

#include <stddef.h>
#include <stdint.h>

void *my_memcpy(void *dest, const void *src, size_t len)
{
    uint8_t *d = dest;
    const uint8_t *s = src;

    for (; len--; ++s){
        *d = *s;
        ++d;
    }
    return dest;
}
