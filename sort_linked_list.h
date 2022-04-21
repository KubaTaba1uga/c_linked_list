#include "linked_list.h"

#ifndef SORT_LINKED_LIST_H
#define SORT_LINKED_LIST_H

void linked_list_swap(l_list *a, l_list *b);

void linked_list_bubble_sort(l_list *l, bool cmp_function(void *, void *));

void linked_list_insertion_sort(l_list *l, bool cmp_function(void *, void *));

#endif
