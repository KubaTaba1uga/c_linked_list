CC      = gcc
CFLAGS  = -g -std=c17 -Wall
RM      = rm -f


default: all

all: example.out

linked_list.out: linked_list.c
	$(CC) $(CFLAGS) -nostartfiles -o linked_list.out linked_list.c

example.out: example/example_context.c example/linked_list_example.c linked_list.c
	$(CC) $(CFLAGS) -o  linked_list_example.out linked_list.c example/example_context.c example/linked_list_example.c

sorting_example.out: example/example_context.c example/sort_linked_list_example.c linked_list.c sort_linked_list.c
	$(CC) $(CFLAGS) -o sorting_example.out linked_list.c sort_linked_list.c example/example_context.c example/sort_linked_list_example.c


clean veryclean:
	$(RM) *.out
