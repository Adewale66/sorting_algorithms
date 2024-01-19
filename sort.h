#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int partition(int *array, int low, int high, size_t size);
void quick_sort_rec(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, size_t size, size_t mid, int *tmp);
void merge_sort_rec(int *array, size_t size, int *tmp);
void radix_sort(int *array, size_t size);
int get_max(int *array, size_t size);
void count_sort(int *array, size_t size, int exp);
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t i, size_t size2);
#endif /* __SORT_H__ */
