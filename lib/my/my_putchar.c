/*
** EPITECH PROJECT, 2021
** B-CPE-110-REN-1-1-BSQ-lucas.colleu
** File description:
** my_putchar
*/

#include <my.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
