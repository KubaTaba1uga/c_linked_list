#include "example_context.h"

void show_progress(int i) {
  const char *progress = "-\\|/-";
  // 8 is clearing one char before
  // 8, 8 is clearing two chars before
  printf("%c%c%c]", 8, 8, progress[(i / 100) % 5]);
  fflush(stdout);
}

void show_numbers(numbers *n) { printf("a=%i | b=%i\n", n->a, n->b); }

void show_list(l_list *l) {
  while (l) {
    numbers *n = l->value;
    show_numbers(n);
    l = l->next;
  }
}

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
  static long long int zxcvbnmasdfghjkl = 0;
  if (zxcvbnmasdfghjkl++ % 100 == 0)
    show_progress(zxcvbnmasdfghjkl);

  // Check if: n.a >= m.a
  numbers *n_i = (numbers *)n;
  numbers *m_i = (numbers *)m;

  return n_i->a > m_i->a;
}

l_list *fill_list_with_numbers(l_list *l, int elements_no, int min, int max) {
  for (int i = 0; i < elements_no; ++i) {
    // create random numbers
    numbers *n = create_random_numbers(min, max);
    l = linked_list_insert(l, n, 0);
    if (!l) {
      printf("Not enough memory to allocate random linked list\n");
      exit(EXIT_FAILURE);
    }
  }

  return l;
}

int sum_array(int n, int arr[n]) {
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += arr[i];
  }
  return sum;
}
