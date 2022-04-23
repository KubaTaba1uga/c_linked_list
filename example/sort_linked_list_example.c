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
#define LIST_SIZE 50
#define TESTS_NO 50000

void show_avg(int avg, char *sort) {
  printf("\n\n%s sort takes on avarage %i procesor cycles\n\n", sort, avg);
}

int test_bubble_sort(time_t r_seed) {
  int cycles;
  l_list *l;

  srand(r_seed);

  l = NULL;
  l = fill_list_with_numbers(l, LIST_SIZE, RANGE_MIN, RANGE_MAX);

  clock_t clk = clock();

  printf("\rBubble sorting [-]");
  linked_list_bubble_sort(l, cmp_a);

  cycles = clock() - clk;

  linked_list_clear(l);

  return cycles;
}

int test_insertion_sort(time_t r_seed) {
  int cycles;
  l_list *l;

  srand(r_seed);

  l = NULL;
  l = fill_list_with_numbers(l, LIST_SIZE, RANGE_MIN, RANGE_MAX);

  clock_t clk = clock();

  printf("\rInsertion sorting [-]");
  l = linked_list_insertion_sort(l, cmp_a);

  cycles = clock() - clk;

  linked_list_clear(l);

  return cycles;
}

int count_avg(int results[TESTS_NO]) {
  return sum_array(TESTS_NO, results) / TESTS_NO;
}

int main(void) {
  time_t now = time(NULL);

  printf("          Elements to sort: %i\n", LIST_SIZE);
  printf("Tests per sorting function: %i\n\n", TESTS_NO);

  int results_bubble_sort[TESTS_NO], results_insertion_sort[TESTS_NO];

  for (int i = 0; i < TESTS_NO; ++i) {
    results_bubble_sort[i] = test_bubble_sort(now);
  }

  show_avg(count_avg(results_bubble_sort), "Bubble");

  for (int i = 0; i < TESTS_NO; ++i) {
    results_insertion_sort[i] = test_insertion_sort(now);
  }

  show_avg(count_avg(results_insertion_sort), "Insertion");

  return EXIT_SUCCESS;
}
