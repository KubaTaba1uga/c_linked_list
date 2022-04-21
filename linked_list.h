#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Linked list
typedef struct _l_list {
  void *value;
  struct _l_list *next;
} l_list;

void print_hello(void);

l_list *linked_list_create_node(void *value);

l_list *linked_list_get_node(l_list *l, int i);

void *linked_list_get_value(l_list *l, int i);

l_list *linked_list_append(l_list *l, void *value);

l_list *linked_list_insert(l_list *l, void *value, int i);

l_list *linked_list_remove(l_list *l, int i);

void *linked_list_pop(l_list *l, int i);

void linked_list_clear(l_list *l);

l_list *linked_list_find(l_list *l, void *value,
                         bool cmp_function(void *, void *));

int linked_list_index_of(l_list *l, void *value,
                         bool cmp_function(void *, void *));

#endif
