/*
** EPITECH PROJECT, 2021
** main
** File description:
** main function
*/

#include "generator.h"

int error_handle(int ac, char **av)
{
    if (ac < 3 || ac > 4) {
        fprintf(stderr, "read usage.\n");
        return 84;
    }
    if (atoi(av[1]) < 1 || atoi(av[2]) < 1) {
        fprintf(stderr, "x and y arguments must be positive numbers.\n");
        return 84;
    }
    if (ac == 4 && strcmp(av[3], "perfect") != 0) {
        fprintf(stderr, "precise perfect if the maze has to be perfect.\n");
        return 84;
    }
    return 0;
}

int print_usage(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        printf("USAGE\n\t./generator xsize ysize [perfect]\n");
        printf("DESCRIPTION\n\tthis is a labyrinth generator made by "
            "Zacharie .L and Louis .B as an epitech 1st year project\n"
            "ARGUMENTS\n\txsize\t\tlength of the maze\n\tysize\t\theight of "
            "the maze\n\t[perfect]\toptionnal argument to create a perfect"
            "maze or not\n");
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
    return (generator(atoi(av[1]), atoi(av[2]), (ac == 4 ? true : false)));
}