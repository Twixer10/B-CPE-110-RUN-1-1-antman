/*
** EPITECH PROJECT, 2021
** GIANTMAN MAIN
** File description:
** NO DESCRIPTION FOUND
*/

#include "./include/giantman.h"

int main(int ac, char **av)
{
    if (ac == 3) {
        if (check_args(av, 2, "1")) {
            return (decompress_1(av[1]));
        }
    } else
        return (84);
}