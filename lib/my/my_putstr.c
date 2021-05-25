/*
** EPITECH PROJECT, 2021
** B-CPE-110-REN-1-1-BSQ-lucas.colleu
** File description:
** my_putstr
*/

#include <my.h>

int my_putstr(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (my_putstr("NULL"));
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}
