/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** library
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb < -2147483647 || nb > 2147483647)
        return (0);
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb == 0) {
        my_putchar('0');
        return (0);
    }
    if (nb / 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
    return (0);
}
