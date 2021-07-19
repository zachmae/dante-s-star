/*
** EPITECH PROJECT, 2021
** perfect
** File description:
** perfect maze generator
*/

#include "generator.h"

static void test_value(t_generator *gen, int *y, int *x, int *c)
{
    if ((gen->posx + gen->dirx) > 0 && (gen->posx + gen->dirx) < gen->width &&
        (gen->posy + gen->diry) > 0 && (gen->posy + gen->diry) < gen->height &&
        gen->maze[gen->posy * gen->width + gen->posx] == 'X' &&
        gen->maze[(gen->posy + gen->diry) * gen->width +
        (gen->posx + gen->dirx)] == 'X') {
        gen->maze[gen->posy * gen->width + gen->posx] = '*';
        gen->maze[(gen->posy + gen->diry) * gen->width +
            (gen->posx + gen->dirx)] = '*';
        gen->dir = rand() % 4;
        *x = gen->posx + gen->dirx;
        *y = gen->posy + gen->diry;
        *c = 0;
    } else {
        gen->dir = (gen->dir + 1) % 4;
        *c = *c + 1;
    }
}

static void test_neighbour(t_generator *gen)
{
    gen->dirx = 0;
    gen->diry = 0;
    if (gen->dir == 0)
        gen->dirx = 1;
    if (gen->dir == 1)
        gen->diry = 1;
    if (gen->dir == 2)
        gen->dirx = -1;
    if (gen->dir == 3)
        gen->diry = -1;
}

static void get_maze(t_generator *gen, int x, int y)
{
    int c = 0;

    gen->dir = rand() % 4;
    while (c < 4) {
        test_neighbour(gen);
        gen->posy = y + gen->diry;
        gen->posx = x + gen->dirx;
        test_value(gen, &y, &x, &c);
    }
    return;
}

void perfect_maze(t_generator *gen)
{
    unsigned int y = 1;
    unsigned int x = 1;

    while (y < gen->height) {
        while (x < gen->width) {
            get_maze(gen, x, y);
            x += 2;
        }
        y += 2;
        x = 1;
    }
    gen->maze[0] = '*';
    gen->maze[1] = '*';
    gen->maze[(gen->height - 1) * gen->width + (gen->width - 2)] =\
( gen->height % 2 == 1  && gen->maze[(gen->height - 2)\
* gen->width + (gen->width - 1)] == '*'? 'X' : '*');
    gen->maze[(gen->height - 1) * gen->width + (gen->width - 1)] = '*';
    return;
}
