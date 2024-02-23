#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *cons(int head, List *tail) { 
  /* malloc() will be explained in the next lecture! */
  List *cell = malloc(sizeof(List));
  cell->head = head;
  cell->tail = tail;
  return cell;
}

/* Functions for you to implement */

int sum(List *list) {
  /* TODO */
  int sum = 0;
  while (list -> tail != NULL)
  {
    sum += list -> head;
    list = list -> tail;
  }
  sum += list -> head;
  return sum;
}

void iterate(int (*f)(int), List *list) {
  /* TODO */
  while (list -> tail != NULL) 
  {
    list -> head = f(list -> head);
    list = list -> tail;
  }
  list -> head = f(list -> head);
}

void print_list(List *list) { 
  /* TODO */
  List * ptr = list;
  printf("[");
  while (ptr -> tail != NULL) 
  {
    printf("%d, ", ptr -> head);
    ptr = ptr -> tail;
  }
  printf("%d]\n", ptr -> head);
}

// /**** CHALLENGE PROBLEMS ****/

List *merge(List *list1, List *list2) {
  if (list1 == NULL) return list2;
  if (list2 == NULL) return list1;

  List dummy; // Create a dummy node to simplify the merging process.
  dummy.tail = NULL;
  List *tmp = &dummy;

  while (list1 != NULL && list2 != NULL) {
    if (list1->head <= list2->head) {
      tmp->tail = list1;
      list1 = list1->tail;
    } else {
      tmp->tail = list2;
      list2 = list2->tail;
    }
    tmp = tmp->tail;
  }

  // At least one of list1 or list2 is now NULL. Append the non-NULL list to the merged list.
  tmp->tail = (list1 != NULL) ? list1 : list2;

  return dummy.tail;
}

void split(List *list, List **list1, List **list2) {
  if (list == NULL) {
    *list1 = NULL;
    *list2 = NULL;
    return;
  }

  List *slow = list;
  List *fast = list->tail;

  // Use the fast and slow pointer technique to find the middle of the list.
  while (fast != NULL && fast->tail != NULL) {
    slow = slow->tail;
    fast = fast->tail->tail;
  }

  // `slow` is now at the midpoint in the list.
  *list1 = list;      // The first half starts from the head of the original list.
  *list2 = slow->tail; // The second half starts from the next element after `slow`.
  slow->tail = NULL;  // Split the list into two halves.
}

/* You get the mergesort implementation for free. But it won't
   work unless you implement merge() and split() first! */

List *list_mergesort(List *list) { 
  if (list == NULL || list->tail == NULL) { 
    return list;
  } else { 
    List *list1;
    List *list2;
    split(list, &list1, &list2);
    list1 = list_mergesort(list1);
    list2 = list_mergesort(list2);
    return merge(list1, list2);
  }
}
