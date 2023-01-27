/*
** EPITECH PROJECT, 2022
** my_swapcontext.c
** File description:
** signal.h
*/

#include <signal.h>

void my_swapcontext(ucontext_t *a, ucontext_t *b)
{
    ucontext_t temp = *a;
    *a = *b;
    *b = temp;
}
