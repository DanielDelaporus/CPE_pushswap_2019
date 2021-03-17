/*
** EPITECH PROJECT, 2019
** PSCE_pushswap_2019
** File description:
** No file there, just an epitech header example
*/

#include<stdio.h>
#include<stdlib.h>
#include"lib/my/my.h"

void sa_or_sb(linked_list_t **tab_a, int sa);

void sa_and_sb(linked_list_t **tab_a, linked_list_t **tab_b);

void push_a_to_b(linked_list_t **tab_a, linked_list_t **tab_b, int a_to_b);

void rotate_first_to_last(linked_list_t **tab_a, int a);

void rotate_last_to_first(linked_list_t **tab_a, int a);

void rot_f_to_l_both(linked_list_t **tab_a, linked_list_t **tab_b);

void rot_l_to_f_both(linked_list_t **tab_a, linked_list_t **tab_b);

void move_to_min(linked_list_t **tab_a, int len)
{
    if (len < 2)
        return;
    linked_list_t *taba = *tab_a;
    int index = 0;
    int min = taba->data;
    for (int i = 0; i < len; i++, taba = taba->next) {
        if (min > taba->data) {
            min = taba->data;
            index = i;
        }
    }
    taba = *tab_a;
    for (int  i = 0; i < index; i++)
        rotate_first_to_last(&taba, 1);
    *tab_a = taba;
}

int list_is_sorted(linked_list_t *tab_a)
{
    int len = my_list_size(tab_a);
    for (int i = 0; i < len - 1; i++, tab_a = tab_a->next) {
        if (tab_a->data > tab_a->next->data)
            return 0;
    }
    return 1;
}

void tri(linked_list_t **tab_a, linked_list_t **tab_b)
{
    linked_list_t *taba = *tab_a;
    linked_list_t *tabb = *tab_b;
    if (list_is_sorted(taba))
            return;
    int len = my_list_size(*tab_a);
    for (int i = 0; i < len - 1; i++) {
        move_to_min(&taba, len - i);
        push_a_to_b(&taba, &tabb, 1);
    }
    for (int i = 0; i < len; i++)
        push_a_to_b(&tabb, &taba, 0);
    my_putstr("sa sa");
}

void add_node(linked_list_t **tab_a, int val)
{
    linked_list_t *new_node = malloc(sizeof(linked_list_t));
    new_node->next = *tab_a;
    new_node->data = val;
    *tab_a = new_node;
}

int main(int argc, char *argv[])
{
    linked_list_t *tab_a = NULL;
    linked_list_t *tab_b = NULL;
    for (int i = argc - 1; i > 0; i--)
        add_node(&tab_a, my_getnbr(argv[i]));
    if (argc < 3) {
        my_putstr("\n");
        return 0;
    }
    tri(&tab_a, &tab_b);
    my_putstr("\n");
    return 0;
}