/*
** EPITECH PROJECT, 2021
** generator
** File description:
** main part of my maze generator
*/

#include <time.h>
#include "generator.h"

void print_maze(t_generator *gen)
{
    if (gen->width == 1 || gen->height == 1) {
        for (unsigned int c = 0; c < gen->width * gen->height; c++)
            gen->maze[c] = '*';
    }
    for (unsigned int c = 0; c < gen->width * gen->height; c++) {
        if (c != 0 && c % gen->width == 0)
            printf("\n");
        printf("%c", gen->maze[c]);
    }
    free(gen->maze);
}

void init_generator(t_generator *gen, int width, int height)
{
    unsigned int c;

    gen->width = (unsigned int){width};
    gen->height = (unsigned int){height};
    gen->maze = malloc(sizeof(char) * (gen->width * (gen->height + 1)));
    if (gen->maze == NULL) {
        fprintf(stderr, "ERROR: Malloc failed");
        exit(84);
    }
    for (c = 0; c < gen->height * gen->width; c++)
        gen->maze[c] = 'X';
    gen->maze[gen->width + 1] = '*';
    gen->maze[c] = '\0';
}

static void make_grid(t_generator *gen, bool perfect)
{
    int y;

    srand(time(0));
    if (perfect == true)
        perfect_maze(gen);
    else
        imperfect_maze(gen);
    print_maze(gen);
    return;
}

int generator(int width, int height, bool perfect)
{
    t_generator gen;

    if (width == 1) {
        for (int c = 1; c < height; c++) {
            write(1, "*\n", 2);
        }
        write(1, "*", 1);
        return 0;
    }
    if (height == 1) {
        for (int c = 0; c < width; c++)
            write(1, "*", 1);
        return 0;
    }
    init_generator(&gen, width, height);
    make_grid(&gen, perfect);
    return 0;
}