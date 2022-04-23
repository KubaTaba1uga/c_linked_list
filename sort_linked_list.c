#include "linked_list.h"

#include "example/example_context.h"

void linked_list_swap(l_list *a, l_list *b) {
  /* Swap value of node `a` with value of node `b`. */
  void **tmp = a->value;
  a->value = b->value;
  b->value = tmp;
}

l_list *linked_list_bubble_sort(l_list *l, bool cmp_function(void *, void *)) {
  l_list *current = NULL;
  l_list *cmp_to = NULL;
  int swap_counter;

  do {
    current = l;
    cmp_to = l->next;
    swap_counter = 0;

    while (cmp_to) {
      if (cmp_function(current->value, cmp_to->value)) {
        linked_list_swap(current, cmp_to);
        swap_counter++;
      }
      cmp_to = cmp_to->next;
      current = current->next;
    }

  } while (swap_counter > 0);

  return l;
}

l_list *_linked_list_insertion_sort_insert_node(l_list *l, l_list *n, int i) {
  l_list *prev = l, *tmp;

  // get node  before `n`
  while (prev->next != n) {
    prev = prev->next;
  }
  prev->next = n->next;

  if (i != 0) {
    /* get node before `i` */
    tmp = linked_list_get_node(l, i - 1);
    n->next = tmp->next;
    tmp->next = n;
  } else {
    n->next = l;
    l = n;
  }

  return l;
}

l_list *linked_list_insertion_sort(l_list *l,
                                   bool cmp_function(void *, void *)) {
  l_list *sorted = l, *current = l->next, *cmp_to;
  int i;

  while (sorted) {
    i = 0;
    cmp_to = l;

    while (cmp_to != current) {
      if (cmp_function(cmp_to->value, current->value)) {
        if (!i)
          l = _linked_list_insertion_sort_insert_node(l, current, i);
        else
          _linked_list_insertion_sort_insert_node(l, current, i);
        break;
      }
      cmp_to = cmp_to->next;
      i++;
    }
    sorted = current->next;
    current = current->next;
  }

  return l;
};
