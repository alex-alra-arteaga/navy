/*
** EPITECH PROJECT, 2022
** my_putchar_stderr
** File description:
** writes on standard error output
*/

#include <unistd.h>

void my_putchar_stderr(char c)
{
    write(2, &c, 1);
}
