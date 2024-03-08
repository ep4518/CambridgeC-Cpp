#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

Node *empty = NULL;

Node *node(int value, Node *left, Node *right) { 
  Node *r = malloc(sizeof(Node));
  r->marked = false;
  r->value = value;
  r->left = left;
  r->right = right;
  return r;
}


/* Basic Problems */

int size(Node *node) { 
  /* TODO */
  if (node == NULL) return 0;
  if (node->marked) return 0;
  else {
    node->marked = true;
    return 1 + size(node->left) + size(node->right);
  }
}


void unmark(Node *node) { 
  /* TODO */
  if (node == NULL) return;
  if (!node->marked) return;
  node->marked = false;
  unmark(node->left);
  unmark(node->right);
}

bool path_from(Node *node1, Node *node2) {
  /* TODO */
  if (node1 == NULL || node2 == NULL) return false;
  else if (node1 == node2) return true;
  return path_from(node1->left, node2) || path_from(node1->right, node2);
}

bool cyclic(Node *node) { 
  /* TODO */
  return (path_from(node->left, node) || path_from(node->right, node));
} 


/* Challenge problems */

void get_nodes(Node *node, Node **dest) { 
  /* TODO */
  if (node->marked || node == NULL) return;
  node->marked = true;
  *dest = node;
  (*dest)++;
  get_nodes(node->left, dest);
  get_nodes(node->right, dest);
}

void graph_free(Node *node) {
  /* TODO */ 
  Node * nodes[size(node)];
  /* pass a pointer into the nodes array to the get_nodes function */
  Node **dest = nodes;
  get_nodes(node, dest);
}

