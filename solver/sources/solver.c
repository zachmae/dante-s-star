/*
** EPITECH PROJECT, 2021
** solver
** File description:
** main part of my maze solver
*/

#include "solver.h"

void aff_map(t_solver *solver)
{
    for (int c = 0; c != solver->height - 1; c++)
        printf("%s\n", solver->maze[c]);
    printf("%s", solver->maze[solver->height - 1]);
}

void init_solver(t_solver *solver, char *buffer)
{
    int c;

    solver->maze = str_to_word_array(buffer, '\n');
    for (c = 0; solver->maze[c]; c++);
    solver->height = c;
    solver->width = strlen(solver->maze[0]);
}

t_start *init_first_node(t_solver *solver)
{
    t_node *first_node = malloc(sizeof(t_node));
    t_start *list = malloc(sizeof(t_start));

    if (first_node == NULL || list == NULL)
        exit(84);
    first_node->y = 0;
    first_node->x = 0;
    first_node->cost = solver->width - 1 + solver->height - 1;
    first_node->status = opened;
    first_node->next = NULL;
    first_node->prev = NULL;
    list->firstnode = first_node;
    return (list);
}

int solver(char *filepath)
{
    char *buffer = read_file(filepath);
    t_solver solver;
    t_start *list;

    init_solver(&solver, buffer);
    list = init_first_node(&solver);
    astar(&solver, list);
    aff_map(&solver);
    free(buffer);
    return 0;
}