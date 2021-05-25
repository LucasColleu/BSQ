/*
** EPITECH PROJECT, 2021
** B-CPE-110-REN-1-1-BSQ-lucas.colleu
** File description:
** freebuffer
*/

#include <my.h>
#include <bsq.h>

void free_buffer(buffer_t **buffer)
{
    free((*buffer)->alloc_pointeur);
    free(*buffer);
    *buffer = NULL;
}
