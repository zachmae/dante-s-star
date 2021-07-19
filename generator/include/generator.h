/*
** EPITECH PROJECT, 2021
** my prog.h
** File description:
** .h file for prog
*/

#ifndef _GENERATOR_H_
#define _GENERATOR_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct s_generator
{
    char *maze;
    unsigned int height;
    unsigned int width;
    int dir;
    unsigned int dirx;
    unsigned int diry;
    unsigned int posx;
    unsigned int posy;
} t_generator;

int generator(int width, int height, bool perfect);
void perfect_maze(t_generator *gen);
void imperfect_maze(t_generator *gen);

#endif