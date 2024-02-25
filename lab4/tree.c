#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

Tree *empty = NULL;

/* BASE EXERCISE */

int tree_member(int x, Tree *tree) { 
  /* TODO */
  while(tree != NULL)
  {
    if (tree -> value == x) {return 1;}
    else if (tree -> value > x) {tree = tree -> left;}
    else {tree = tree -> right;}
  }
  return 0;
}

Tree *tree_insert(int x, Tree *tree) { 
  /* TODO */
  if (tree == NULL)
  {
    Tree * newNode = malloc(sizeof(Tree));
    newNode -> value = x;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
  }
  if (tree_member(x, tree) == 1) {return tree;}
  if (tree -> value > x) {tree -> left = tree_insert(x, tree -> left);}
  else {tree->right = tree_insert(x, tree->right);}
  return tree;
}

void tree_free(Tree *tree) { 
  /* TODO */
  if (tree == NULL) {return;} 
  tree_free(tree -> left);
  tree_free(tree -> right);
  free(tree);
}

/* CHALLENGE EXERCISE */ 

void pop_minimum(Tree *tree, int *min, Tree **new_tree) { 
  /* TODO */
  Tree * root;
  Tree * tmp;
  while (tree -> left != NULL)
  {
    tmp = tree;
    tree = tree -> left;
  }
  min = &(tree -> value);
  tmp -> left = NULL;
  new_tree = &root;
}

Tree *tree_remove(int x, Tree *tree) {
    /* TODO */
    if (tree == NULL) {
        return tree;
    }

    if (x < tree->value) {
        tree->left = tree_remove(x, tree->left);
    }
    else if (x > tree->value) {
        tree->right = tree_remove(x, tree->right);
    }
    // Else: x == tree -> value: delete node.
    else {
        // Node with only one child or no child
        if (tree->left == NULL) {
            Tree *tmp = tree->right;
            free(tree);
            return tmp;
        } else if (tree->right == NULL) {
            Tree *tmp = tree->left;
            free(tree);
            return tmp;
        }

        // Node with two children: Use pop_minimum to get the inorder successor
        int minVal;
        Tree *newRightSubtree;
        pop_minimum(tree->right, &minVal, &newRightSubtree);

        // Copy the inorder successor's content to this node and delete the inorder successor
        tree->value = minVal;
        tree->right = newRightSubtree;
    }
    return tree;
}
