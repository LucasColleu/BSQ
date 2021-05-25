/*
** EPITECH PROJECT, 2021
** B-CPE-110-REN-1-1-BSQ-lucas.colleu
** File description:
** my_find_char
*/

#include <my.h>

int my_find_char(char const *str, char c)
{
    int i = 0;

    if (str == NULL)
        return (-1);
    while (str[i] != '\0') {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (-1);
}
