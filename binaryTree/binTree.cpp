#include "Node.h"
#include "Queue.h"
#include "Stack.h"
#include <iostream>

using namespace std;

class TreeBinSearch {
private:
  Node *root;

public:
  TreeBinSearch();
  void Insert(int elem);
  bool isEmpty();
  int Count();
  void Display();
  Node *Search(int elem);
  Node *Delete(int elem);
};

TreeBinSearch::TreeBinSearch() { root = NULL; }

void TreeBinSearch::Insert(int elem) {
  if (isEmpty()) {
    root = new Node(elem);
    return;
  }

  Node *current = root;
  Node *tail = NULL;

  while (current != NULL) {
    if (elem < current->elem) {
      tail = current;
      current = current->left;
    } else {
      tail = current;
      current = current->right;
    }
  }

  if (tail != NULL) {
    if (elem < tail->elem) {
      tail->left = new Node(elem);
    } else {
      tail->right = new Node(elem);
    }
  }
}

bool TreeBinSearch::isEmpty() { return root == NULL; }

void TreeBinSearch::Display() {
  if (isEmpty()) {
    printf("Tree is empty\n");
    return;
  }

  cout << "Display:\n";
  Queue *displayQueue = new Queue(100);
  displayQueue->Enqueue(root);

  while (!displayQueue->isEmpty()) {
    Node *current = displayQueue->Dequeue();
    printf("elem: %d ", current->elem);
    if (current->left) {
      printf("left: %d ", current->left->elem);
      displayQueue->Enqueue(current->left);
    }
    if (current->right) {
      printf("right: %d ", current->right->elem);
      displayQueue->Enqueue(current->right);
    }
    cout << endl;
  }
}

Node *TreeBinSearch::Search(int elem) {
  Node *current = this->root;

  while (current != NULL) {
    if (current->elem == elem) {
      return current;
    }
    if (elem < current->elem) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return NULL;
};

Node *TreeBinSearch::Delete(int target) {
  Node *current = this->root;
  Node **parentPtr = &this->root;

  while (current != NULL) {
    if (current->elem == target) {
      break;
    }

    if (target < current->elem) {
      parentPtr = &current->left;
      current = current->left;
    } else {
      parentPtr = &current->right;
      current = current->right;
    }
  }

  if (current == NULL) {
    return NULL;
  }

  if (current->left == NULL && current->right == NULL) {
    *parentPtr = NULL;
    return current;
  }

  if (current->left == NULL || current->right == NULL) {
    if (current->right == NULL) {
      *parentPtr = current->left;
    } else {
      *parentPtr = current->right;
    }
    return current;
  }

  // find upmost right from left side
  Node *inorderPred = current->left;
  Node **parentInorderPredPtr = &current->left;

  while (inorderPred->right != NULL) {
    parentInorderPredPtr = &inorderPred->right;
    inorderPred = inorderPred->right;
  }

  *parentInorderPredPtr = inorderPred->left;
  inorderPred->left = current->left;
  inorderPred->right = current->right;
  *parentPtr = inorderPred;

  return current;
}

int TreeBinSearch::Count() {
  int count = 0;
  Queue *displayQueue = new Queue(10);
  displayQueue->Enqueue(root);

  while (!displayQueue->isEmpty()) {
    count++;
    Node *current = displayQueue->Dequeue();
    if (current->left) {
      displayQueue->Enqueue(current->left);
    }
    if (current->right) {
      displayQueue->Enqueue(current->right);
    }
  }
  return count;
}

int main() {
  TreeBinSearch *tree = new TreeBinSearch();
  tree->Insert(31);
  tree->Insert(40);
  tree->Insert(41);
  tree->Insert(43);
  tree->Insert(20);
  tree->Insert(29);
  tree->Insert(8);
  tree->Insert(7);
  tree->Insert(10);

  tree->Display();
  cout << endl;
  cout << "Search(10): " << tree->Search(10)->elem << endl;
  Node *res = tree->Search(1);

  if (res != NULL) {
    cout << "Search(1): " << res << endl;
  } else {
    cout << "Search(1): NULL" << endl;
  }

  cout << "tree->Delete(7)" << endl;
  tree->Delete(7);
  tree->Display();

  cout << "tree->Delete(8)" << endl;
  tree->Delete(8);
  tree->Display();

  cout << "tree->Delete(41)" << endl;
  tree->Delete(41);
  tree->Display();

  cout << "tree->Delete(31)" << endl;
  tree->Delete(31);
  tree->Display();
  cout << endl;

  tree->Insert(25);
  tree->Insert(22);
  tree->Insert(21);
  tree->Insert(23);
  tree->Display();

  cout << "tree->Delete(29)" << endl;
  tree->Delete(29);
  tree->Display();

  tree->Delete(23);
  tree->Delete(22);
  tree->Delete(21);
  tree->Delete(25);

  tree->Insert(12);
  tree->Insert(11);
  tree->Insert(18);
  tree->Insert(16);
  tree->Insert(15);
  tree->Display();

  cout << "tree->Delete(20)" << endl;
  tree->Delete(20);
  tree->Display();
}