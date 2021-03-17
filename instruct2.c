/*
** EPITECH PROJECT, 2019
** PSCE_pushswap_2019
** File description:
** No file there, just an epitech header example
*/

#include<stdio.h>
#include<stdlib.h>
#include"lib/my/my.h"

void rotate_first_to_last(linked_list_t **tab_a, int a);

void rotate_last_to_first(linked_list_t **tab_a, int a);

void rot_f_to_l_both(linked_list_t **tab_a, linked_list_t **tab_b)
{
    my_putstr("rr ");
    rotate_first_to_last(tab_a, 2);
    rotate_first_to_last(tab_b, 2);
}

void rot_l_to_f_both(linked_list_t **tab_a, linked_list_t **tab_b)
{
    rotate_last_to_first(tab_a, 1);
    rotate_last_to_first(tab_b, 0);
}