/*
** EPITECH PROJECT, 2021
** B-CPE-110-REN-1-1-BSQ-lucas.colleu
** File description:
** bsq
*/

#include <my.h>
#include <bsq.h>

static int open_map(char const *filepath, buffer_t *buffer, int size)
{
    int fd = open(filepath, O_RDONLY);

    if (fd < 0)
        return (0);
    buffer->size = read(fd, buffer->string, size);
    close(fd);
    if (buffer->size < 0)
        return (0);
    return (1);
}

buffer_t *read_buffer(char const *filepath)
{
    buffer_t *buffer = malloc(sizeof(buffer_t));
    struct stat statbuf;

    if (buffer == NULL)
        return (NULL);
    if (stat(filepath, &statbuf) == -1)
        return (NULL);
    buffer->string = malloc(sizeof(char) * (statbuf.st_size + 1));
    if (buffer->string == NULL)
        return (NULL);
    buffer->alloc_pointeur = buffer->string;
    if (open_map(filepath, buffer, statbuf.st_size) == 0)
        return (NULL);
    return (buffer);
}

static int get_number_of_lignes(buffer_t *buffer)
{
    char *current_buf = buffer->string;
    int nb_lignes = my_getnbr(buffer->string);
    int index = my_find_char(current_buf, '\n') + 1;

    buffer->string = &current_buf[index];
    buffer->size -= index;
    return (nb_lignes);
}

buffer_t *bsq(char const *filepath)
{
    int nb_lignes = 0;
    int nb_colonnes = 0;
    buffer_t *buffer = read_buffer(filepath);

    if (buffer == NULL)
        return (NULL);
    if (check_error(buffer->string)) {
        free_buffer(&buffer);
        return (NULL);
    }
    nb_lignes = get_number_of_lignes(buffer);
    nb_colonnes = my_find_char(buffer->string, '\n');
    find_the_biggest_square(buffer->string, nb_lignes, nb_colonnes);
    return (buffer);
}
