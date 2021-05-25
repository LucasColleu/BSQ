/*
** EPITECH PROJECT, 2021
** B-CPE-110-REN-1-1-BSQ-lucas.colleu
** File description:
** find_square
*/

#include <my.h>
#include <bsq.h>

static int check_no_obstacle(int size, map_t *map, int x, int y)
{
    int i = 0;
    int j = 0;

    while (j < size) {
        if (map->buffer[buffer_index(map, x + i, y + j)] == 'o')
            return (1);
        i++;
        if (i == size) {
            i = 0;
            j++;
        }
    }
    return (0);
}

static int try_to_find_square(int size, map_t *map, int x, int y)
{
    if (x + size - 1 >= map->nb_colonnes || y + size - 1 >= map->nb_lignes)
        return (0);
    if (check_no_obstacle(size, map, x, y) == 1)
        return (0);
    return (1);
}

void try_square_of_greater_size(square_t *square, map_t *map)
{
    int x = square->x;
    int y = square->y;

    while (y < map->nb_lignes) {
        if (try_to_find_square(square->size + 1, map, x, y) == 1) {
            square->size += 1;
            square->x = x;
            square->y = y;
            return;
        }
        x++;
        if (x == map->nb_colonnes) {
            x = 0;
            y++;
        }
    }
}
