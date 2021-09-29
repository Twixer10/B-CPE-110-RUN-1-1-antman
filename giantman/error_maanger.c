/*
** EPITECH PROJECT, 2021
** B-CPE-110-RUN-1-1-antman-thomas.techer
** File description:
** error_maanger
*/

#include "./include/giantman.h"

int open_error(char *path, char *msg)
{
    my_putstr(path);
    my_putstr(msg);
    return (84);
}