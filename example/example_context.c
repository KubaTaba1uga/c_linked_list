#include "example_context.h"

int create_random_n(int lower, int upper) {
  return (rand() % (upper - lower + 1)) + lower;
}

numbers *create_numbers(int a, int b) {
  numbers *n = (numbers *)malloc(sizeof(numbers));
  if (!n) {
    puts("\nUnable to allocate numbers memory");
    exit(EXIT_FAILURE);
  }
  n->a = a;
  n->b = b;
  return n;
}

numbers *create_random_numbers(int min, int max) {
  int a = create_random_n(min, max);
  int b = create_random_n(min, max);
  numbers *n = create_numbers(a, b);
  return n;
}

bool is_a(void *n, void *a) {
  numbers *n_i = (numbers *)n;
  int *a_i = (int *)a;

  return n_i->a == *a_i;
}

bool cmp_a(void *n, void *m) {
  // Check if: n.a >= m.a
  numbers *n_i = (numbers *)n;
  numbers *m_i = (numbers *)m;

  return n_i->a >= m_i->a;
}
