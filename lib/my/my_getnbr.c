/*
** EPITECH PROJECT, 2021
** B-CPE-110-REN-1-1-BSQ-lucas.colleu
** File description:
** my_getnbr
*/

#include <my.h>

int index_of_first_digit(char const *str)
{
    int i = 0;
    int len = my_strlen(str);

    while (i < len) {
        if (str[i] >= '0' && str[i] <= '9')
            return (i);
        i++;
    }
    return (0);
}

int negative_nb(char const *str, int index_first)
{
    int number_of_minus = 0;
    int i = index_first - 1;

    while (i >= 0 && (str[i] == '-' || str[i] == '+')) {
        if (str[i] == '-')
            number_of_minus += 1;
        i--;
    }
    return (number_of_minus % 2);
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int digit = 0;
    int i = index_of_first_digit(str);
    int sign = negative_nb(str, i);

    if (str == NULL)
        return (0);
    while (str[i] >= '0' && str[i] <= '9') {
        digit = str[i] - 48;
        if (sign == 0 && (nb <= (2147483647 - digit) / 10))
            nb = (nb * 10) + digit;
        else if (sign == 1 && (nb >= (-2147483648 + digit) / 10))
            nb = (nb * 10) - digit;
        else
            return (0);
        i++;
    }
    return (nb);
}
