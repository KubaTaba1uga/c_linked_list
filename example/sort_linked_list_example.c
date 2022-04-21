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

#define RANGE_MIN 10
#define RANGE_MAX 99
#define LIST_SIZE 5000
#define TESTS_NO 50

void show_avg(int avg) {
  printf("\n\nBubble sort takes on avarage %i procesor cycles\n", avg);
}

int main(void) {
  printf("Number of elements to sort %i\n\n", LIST_SIZE);

  l_list *l = NULL;
  int bubble_sort_results[TESTS_NO], insertion_sort_results[TESTS_NO];
  int avg_bubble_sort;

  for (int i = 0; i <= TESTS_NO; i++) {
    l = NULL;
    l = fill_list_with_numbers(l, LIST_SIZE, RANGE_MIN, RANGE_MAX);

    clock_t clk = clock();

    printf("\r%i. Bubble sorting [-]", i);
    linked_list_bubble_sort(l, cmp_a);

    bubble_sort_results[i] = clock() - clk;
  }

  avg_bubble_sort = sum_array(TESTS_NO, bubble_sort_results) / TESTS_NO;

  show_avg(avg_bubble_sort);

  linked_list_clear(l);

  return EXIT_SUCCESS;
}
