/*
** EPITECH PROJECT, 2021
** main
** File description:
** main function
*/

#include "solver.h"

int error_handle(int ac, char **av)
{
    if (ac != 2) {
        fprintf(stderr, "read usage.\n");
        return 84;
    }
    return 0;
}

int print_usage(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        printf("USAGE\n\t./solver map.txt\n");
        printf("DESCRIPTION\n\tthis is a labyrinth solver made by "
            "Zacharie .L and Louis .B as an epitech 1st year project\n"
            "ARGUMENTS\n\tmap.txt\t\tfile that contain the map that"
            " has to be solved\n");
        return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (print_usage(ac, av) == 1)
        return 0;
    if (error_handle(ac, av) == 84)
        return 84;
    return (solver(av[1]));
}