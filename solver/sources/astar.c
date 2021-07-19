/*
** EPITECH PROJECT, 2021
** astar
** File description:
** astar algorithm
*/

#include "solver.h"

void do_backtrack(t_solver *solver, t_start *list, t_node *current)
{
    while (current != NULL) {
        solver->maze[current->y][current->x] = 'o';
        current = current->prev;
    }
    return;
}

void get_neighbour_pos(t_node *neighbor, int y, int x)
{
    neighbor->y = y;
    neighbor->x = x;
}

void add_neigh(t_node *new_node, t_solver *solv, t_start *list, t_node *cur)
{
    if (new_node->y >= 0 && new_node->y < solv->height &&
        new_node->x >= 0 && new_node->x < solv->width &&
        solv->maze[new_node->y][new_node->x] != 'X' &&
        chek_node_stat(list, new_node->y, new_node->x, closed) != closed) {
        if (chek_node_stat(list, new_node->y, new_node->x, opened) != opened) {
            new_node->status = opened;
            new_node->cost = solv->width - 1 + solv->height - 1;
            new_node->prev = cur;
            add_neigh_in_list(list, new_node);
        }
    }
}

void get_neighbours(t_solver *solver, t_start *list, t_node *current)
{
    t_node *neighbour;

    for (int c = 0; c < 4; c++) {
        if ((neighbour = malloc(sizeof(t_node))) == NULL)
            exit(84);
        if (c == 0)
            get_neighbour_pos(neighbour, current->y, current->x - 1);
        if (c == 1)
            get_neighbour_pos(neighbour, current->y - 1, current->x);
        if (c == 2)
            get_neighbour_pos(neighbour, current->y, current->x + 1);
        if (c == 3)
            get_neighbour_pos(neighbour, current->y + 1, current->x);
        add_neigh(neighbour, solver, list, current);
    }
    return;
}

void astar(t_solver *solver, t_start *list)
{
    t_node *current_node;

    while (open_status(list) > 0) {
        current_node = cheapest_node(list);
        if (current_node == NULL)
            exit(84);
        close_node(list, current_node);
        if (current_node->y == solver->height - 1 &&
            current_node->x == solver->width - 1) {
                do_backtrack(solver, list, current_node);
                return;
        }
        get_neighbours(solver, list, current_node);
    }
    printf("no solution found");
    exit(0);
}
