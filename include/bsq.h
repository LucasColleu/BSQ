/*
** EPITECH PROJECT, 2021
** B-CPE-110-REN-1-1-BSQ-lucas.colleu
** File description:
** bsq
*/

#ifndef HEADER_BSQ
#define HEADER_BSQ

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_buffer
{
    char *string;
    char *alloc_pointeur;
    int size;
} buffer_t;

typedef struct s_map
{
    int nb_lignes;
    int nb_colonnes;
    char *buffer;
} map_t;

typedef struct s_square
{
    int x;
    int y;
    int size;
} square_t;

buffer_t *bsq(char const *filepath);
void find_the_biggest_square(char *buffer, int nb_lignes, int nb_colonnes);

buffer_t *read_buffer(char const *filepath);
void free_buffer(buffer_t **buffer);
int check_error(char const *buffer);
void try_square_of_greater_size(square_t *square, map_t *map);
int buffer_index(map_t *map, int x, int y);

#endif
