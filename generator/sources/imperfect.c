/*
** EPITECH PROJECT, 2021
** imperfect
** File description:
** imperfect maze generator
*/

#include "generator.h"

void imperfect_maze(t_generator *gen)
{
    int c;

    perfect_maze(gen);
    for (c = 1; gen->height * gen->width / 2 + c < gen->height * gen->width &&
        gen->maze[gen->height * gen->width / 2 + c] != 'X'; c++);
    gen->maze[gen->height * gen->width / 2 + c] = '*';
    return;
}
