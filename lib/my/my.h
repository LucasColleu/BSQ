/*
** EPITECH PROJECT, 2019
** Header for libmy.a
** File description:
** Contains the prototypes of all functions in libmy.a
*/

#ifndef HEADER_MY_H
#define HEADER_MY_H

#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_find_char(char const *str, char c);

#endif
