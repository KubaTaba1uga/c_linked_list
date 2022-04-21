#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* `time` dependency */
#include <time.h>
/* `sleep` dependency */
#include <unistd.h>

#include "../linked_list.h"
#include "example_context.h"

#define RANGE_MIN 10
#define RANGE_MAX 99
#define LIST_SIZE 2000000

void show_progress(int i) {
  const char *progress = "-\\|/";
  printf("%c%c%c]", 8, 8, progress[(i / 100) % 4]);
  fflush(stdout);
}

int main(void) {
  // reset random seed
  srand(time(0));

  /* printf("Initializing array [-]"); */

  /* /\* test adding to list *\/ */

  /* //  test insert */
  /* for (int i = 0; i < LIST_SIZE; ++i) { */
  /*   if (!(i % 100)) */
  /*     show_progress(i); */

  /*   // create random numbers */
  /*   numbers *n = create_random_numbers(RANGE_MIN, RANGE_MAX); */
  /*   l = linked_list_insert(l, n, 0); */
  /* } */
  /* puts(""); */

  /* /\* // test append *\/ */
  /* /\* for (int i = 0; i < LIST_SIZE; ++i) { *\/ */
  /* /\*   if (!(i % 100)) *\/ */
  /* /\*     show_progress(i); *\/ */

  /* /\*   // create random numbers *\/ */
  /* /\*   numbers *n = create_random_numbers(RANGE_MIN, RANGE_MAX); *\/ */
  /* /\*   l = linked_list_insert(l, n, 0); *\/ */
  /* /\* } *\/ */
  /* /\* puts(""); *\/ */

  /* /\* test searching *\/ */
  /* l_list *l_cp = l; */

  /* int looking_for = 69; */

  /* // test find */
  /* /\* for (int i = 0; l_cp; ++i) { *\/ */
  /* /\*   l_cp = linked_list_find(l_cp, &looking_for, &is_a); *\/ */
  /* /\*   if (l_cp) { *\/ */
  /* /\*     l_cp = l_cp->next; *\/ */
  /* /\*   } else *\/ */
  /* /\*     printf("Number of %i occurences in list: %i \n", looking_for, i);
   * *\/ */
  /* /\* } *\/ */

  /* // test index of */
  /* int j = linked_list_index_of(l_cp, &looking_for, &is_a); */
  /* numbers *n = linked_list_get_value(l_cp, j); */
  /* if (j >= 0) */
  /*   printf("Index: %i\na=%i | b=%i\n", j, n->a, n->b); */
  /* else */
  /*   printf("Value %i not found\n", looking_for); */

  /* /\* show list content *\/ */
  /* /\* l_list *l_cp = l; *\/ */
  /* /\* while (l_cp->next) { *\/ */
  /* /\*   numbers *n = l_cp->value; *\/ */
  /* /\*   printf("a=%i | b=%i\n", n->a, n->b); *\/ */
  /* /\*   l_cp = l_cp->next; *\/ */
  /* /\* } *\/ */

  /* /\* test removing from list *\/ */

  /* //  test clear */
  /* linked_list_clear(l); */

  /* /\* // test remove *\/ */
  /* /\* l_list *l_cp_2 = l; *\/ */
  /* /\* while (l_cp_2) { *\/ */
  /* /\*   l_cp_2 = linked_list_remove(l_cp_2, 0); *\/ */
  /* /\* } *\/ */

  /* /\* // test pop *\/ */
  /* /\* l_list *placeholder = NULL; *\/ */
  /* /\* while (l_cp_2) { *\/ */
  /* /\*   placeholder = l_cp_2->next; *\/ */
  /* /\*   numbers *n = linked_list_pop(l_cp_2, 0); *\/ */
  /* /\*   printf("a=%i | b=%i\n", n->a, n->b); *\/ */
  /* /\*   free(n); *\/ */
  /* /\*   l_cp_2 = placeholder; *\/ */
  /* /\* } *\/ */

  /* /\* for (int i = 0; i < 1000; i++) { *\/ */
  /* /\*   clock_t clk = clock(); *\/ */
  /* /\*   printf("`printf` took %ld procesor cycles\n", clock() - clk); *\/ */
  /* /\* } *\/ */

  return 0;
}
