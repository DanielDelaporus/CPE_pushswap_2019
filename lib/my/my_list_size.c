/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** No file there, just an epitech header example
*/

#include "my.h"
#include<stdlib.h>

int my_list_size(linked_list_t const *begin)
{
    int len = 0;
    for (; begin != NULL; len++)
        begin = begin->next;
    return len;
}