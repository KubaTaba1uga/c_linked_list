#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../linked_list.h"

#ifndef EXAMPLE_CONTEXT_H
#define EXAMPLE_CONTEXT_H

typedef struct {
  int a;
  int b;
} numbers;

void show_progress(int i);

int create_random_n(int lower, int upper);

numbers *create_numbers(int a, int b);

numbers *create_random_numbers(int min, int max);

bool is_a(void *n, void *a);

bool cmp_a(void *n, void *m);

l_list *fill_list_with_numbers(l_list *l, int elements_no, int min, int max);

void show_list(l_list *l);

int sum_array(int n, int arr[n]);

#endif
