/*
** EPITECH PROJECT, 2022
** my_memcpy
** File description:
** temporal file
*/

void *my_memcpy(void *dest, const void *src, unsigned int size)
{
    int i = 0;
    const char* s = src;
    char *d = dest;

    while (i < size) {
        d[i] = s[i];
        i++;
    }
    return (dest);
}
