/*
** EPITECH PROJECT, 2021
** B-CPE-110-REN-1-1-BSQ-lucas.colleu
** File description:
** my_strlen
*/

#include <my.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (-1);
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
