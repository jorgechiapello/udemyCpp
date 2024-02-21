#include <iostream>
#ifndef NODE_H
#define NODE_H

struct Node {
  Node *left;
  Node *right;
  int elem;
  Node(int elem) {
    this->left = this->right = NULL;
    this->elem = elem;
  }
  bool isLeaf() { return this->left == NULL && this->right == NULL; }
};
#endif