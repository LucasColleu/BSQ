/*
** EPITECH PROJECT, 2021
** B-CPE-110-REN-1-1-BSQ-lucas.colleu
** File description:
** biggest_square
*/

#include <my.h>
#include <bsq.h>

int buffer_index(map_t *map, int x, int y)
{
    return (((map->nb_colonnes + 1) * y) + x);
}

static void remplir_square(map_t *map, square_t *square)
{
    int i = 0;
    int j = 0;

    while (j < square->size) {
        while (i < square->size) {
            map->buffer[buffer_index(map, square->x + i, square->y + j)] = 'x';
            i++;
        }
        i = 0;
        j++;
    }
}

void find_the_biggest_square(char *buffer, int nb_lignes, int nb_colonnes)
{
    map_t map = {nb_lignes, nb_colonnes, buffer};
    square_t square = {0, 0, 0};
    int square_found = 0;
    int size = 0;

    while (square_found == 0) {
        try_square_of_greater_size(&square, &map);
        if (square.size > size)
            size++;
        else
            square_found = 1;
    }
    remplir_square(&map, &square);
}
