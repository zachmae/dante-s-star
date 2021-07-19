/*
** EPITECH PROJECT, 2021
** check node status
** File description:
** return node status
*/

#include "solver.h"

int chek_node_stat(t_start *list, int y, int x, int status)
{
    t_node *temp;

    if (list == NULL)
        exit(84);
    temp = list->firstnode;
    while (temp != NULL) {
        if (y == temp->y && x == temp->x && temp->status == status)
            return (status);
        temp = temp->next;
    }
    return (status == opened ? closed : opened);
}

void add_neigh_in_list(t_start *list, t_node *neigh)
{
    if (list == NULL)
        exit(84);
    neigh->next = list->firstnode;
    list->firstnode = neigh;
    return;
}