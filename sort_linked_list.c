#include "linked_list.h"

#include "example/example_context.h"

void linked_list_swap(l_list *a, l_list *b) {
  /* Swap value of node `a` with value of node `b`. */
  void **tmp = a->value;
  a->value = b->value;
  b->value = tmp;
}

void linked_list_bubble_sort(l_list *l, bool cmp_function(void *, void *)) {
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
}

void linked_list_insertion_sort(l_list *l, bool cmp_function(void *, void *)){

};
