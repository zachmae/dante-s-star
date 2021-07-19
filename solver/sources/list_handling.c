/*
** EPITECH PROJECT, 2021
** list handling
** File description:
** handle my linked lists
*/

#include "solver.h"

t_node *cheapest_node(t_start *list)
{
    int c = 0;
    int save = 0;
    int lower;
    t_node *temp;

    if (list == NULL || list->firstnode == NULL)
        return NULL;
    temp = list->firstnode;
    if ((lower = get_cheapest(list)) == -1)
        return NULL;
    while (temp != NULL) {
        if (temp->status == opened && lower >= temp->cost) {
            save = c;
            lower = temp->cost;
        }
        c++;
        temp = temp->next;
    }
    return (this_node(list, save));
}

int open_status(t_start *list)
{
    int nb_open = 0;
    t_node *node;

    if (list != NULL) {
        node = list->firstnode;
        while (node) {
            if (node->status == opened)
                nb_open++;
            node = node->next;
        }
    }
    return nb_open;
}

t_start *close_node(t_start *list, t_node *current)
{
    t_node *temp;

    if (list == NULL || current == NULL)
        return NULL;
    temp = list->firstnode;
    while (temp != NULL) {
        if (temp->y == current->y && temp->x == current->x) {
            temp->status = closed;
            return (list);
        }
        temp = temp->next;
    }
    return NULL;
}

int get_cheapest(t_start *list)
{
    t_node *node = list->firstnode;

    while (node != NULL && node->status != opened)
        node = node->next;
    if (node == NULL)
        return -1;
    if (node->status == opened)
        return (node->cost);
    return -1;
}

t_node *this_node(t_start *list, int nb)
{
    t_node *node = list->firstnode;

    for (int c = 0; node != NULL && c != nb; c++) {
        node = node->next;
    }
    return (node);
}