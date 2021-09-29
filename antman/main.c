/*
** EPITECH PROJECT, 2021
** ANTMAN MAIN
** File description:
** NO DESCRIPTION FOUND
*/

#include "./include/antman.h"

int main(int ac, char **av)
{
    if (ac == 3) {
        if (check_args(av, 2, "1")) {
            return (compress_1(av[1]));
        }
    } else
        return (84);
}