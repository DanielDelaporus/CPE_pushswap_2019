/*
** EPITECH PROJECT, 2019
** PSCE_pushswap_2019
** File description:
** No file there, just an epitech header example
*/

#include<stdio.h>
#include<stdlib.h>
#include"lib/my/my.h"

void sa_or_sb(linked_list_t **tab_a, int sa)
{
    linked_list_t *b1 = *tab_a;
    void *tmp = NULL;
    (sa) ? my_putstr("sa ") : my_putstr("sb ");
    tmp = b1->data;
    b1->data = b1->next->data;
    b1->next->data = tmp;
}

void sa_and_sb(linked_list_t **tab_a, linked_list_t **tab_b)
{
    sa_or_sb(tab_a, 1);
    sa_or_sb(tab_b, 0);
}

void push_a_to_b(linked_list_t **tab_aa, linked_list_t **tab_bb, int a_to_b)
{
    linked_list_t *tab_a = *tab_aa;
    linked_list_t *tab_b = *tab_bb;
    if (tab_a == NULL)
        return;
    (a_to_b) ? my_putstr("pb ") : my_putstr("pa ");
    int first = tab_a->data;
    linked_list_t *new_node = tab_a;
    tab_a = tab_a->next;
    new_node->data = first;
    new_node->next = tab_b;
    tab_b = new_node;
    *tab_aa = tab_a;
    *tab_bb = tab_b;
}

void rotate_first_to_last(linked_list_t **tab_aa, int a)
{
    linked_list_t *tab_a = *tab_aa;
    if (a != 2)
        (a) ? my_putstr("ra ") : my_putstr("rb ");
    linked_list_t *first = tab_a;
    linked_list_t *retour = tab_a->next;
    for (; tab_a->next != NULL; tab_a = tab_a->next);
    tab_a->next = first;
    first->next = NULL;
    *tab_aa = retour;
}

void rotate_last_to_first(linked_list_t **tab_aa, int a)
{
    linked_list_t *tab_a = *tab_aa;
    if (a != 2)
        (a) ? my_putstr("rra ") : my_putstr("rrb ");
    linked_list_t *first = tab_a;
    linked_list_t *new_node = NULL;
    for (; tab_a->next->next != NULL; tab_a = tab_a->next);
    new_node = tab_a->next;
    tab_a->next = NULL;
    new_node->next = first;
}