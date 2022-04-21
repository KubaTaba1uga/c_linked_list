#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* `time` dependency */
#include <time.h>
/* `sleep` dependency */
#include <unistd.h>

#include "../linked_list.h"
#include "../sort_linked_list.h"
#include "example_context.h"

int main(void) {
  numbers *first_n = create_numbers(2, 2);
  numbers *second_n = create_numbers(3, 3);
  numbers *third_n = create_numbers(0, 0);
  numbers *thourth_n = create_numbers(1, 1);
  // create linked list
  l_list *l = linked_list_create_node(first_n), *a, *b, *c;

  linked_list_append(l, second_n);
  linked_list_append(l, third_n);
  linked_list_append(l, thourth_n);

  /* show list content */
  l_list *l_cp = l;
  while (l_cp) {
    numbers *n = l_cp->value;
    printf("a=%i | b=%i\n", n->a, n->b);
    l_cp = l_cp->next;
  }

  linked_list_bubble_sort(l, cmp_a);

  puts("");

  // show list content
  l_cp = l;
  while (l_cp) {
    numbers *n = l_cp->value;
    printf("a=%i | b=%i\n", n->a, n->b);
    l_cp = l_cp->next;
  }
}
