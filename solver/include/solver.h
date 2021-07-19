/*
** EPITECH PROJECT, 2021
** my prog.h
** File description:
** .h file for prog
*/

#ifndef _SOLVER_H_
#define _SOLVER_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static const int opened = 0;
static const int closed = 1;

typedef struct s_node
{
    int y;
    int x;
    int status;
    int cost;
    struct s_node *next;
    struct s_node *prev;
} t_node;

typedef struct s_start
{
    t_node *firstnode;
} t_start;

typedef struct s_solver
{
    char **maze;
    int height;
    int width;
} t_solver;

int solver(char *filepath);
char *read_file(char const *filename);
char **str_to_word_array(char *str, char lim);
void astar(t_solver *solver, t_start *list);
t_node *cheapest_node(t_start *list);
int open_status(t_start *list);
t_start *close_node(t_start *list, t_node *current);
int get_cheapest(t_start *list);
t_node *this_node(t_start *list, int nb);
int chek_node_stat(t_start *list, int y, int x, int status);
void add_neigh_in_list(t_start *list, t_node *neigh);

#endif