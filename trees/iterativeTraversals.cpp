#include "Queue.h"
#include "Stack.h"
#include <iostream>

using namespace std;

class Tree {
private:
  Queue *queue;
  Node *root;

public:
  Tree(int size) {
    this->queue = new Queue(size);
    root = NULL;
  }

  Tree(int elems[], int size) {
    Queue *cola = new Queue(size);
    this->root = new Node(elems[0]);
    cola->Enqueue(this->root);
    int arrayIdx = 1;
    int count = 1;

    while (count < size) {
      Node *current = cola->GetFront();
      cout << "Processing: " << current->elem << endl;
      cola->Dequeue();

      if (count < size) {
        Node *newNode = new Node(elems[2 * arrayIdx - 1]);
        current->left = newNode;
        cout << "Adding left:" << current->left->elem << endl;
        cola->Enqueue(current->left);
        count++;
      }

      if (count < size) {
        Node *newNode = new Node(elems[2 * arrayIdx]);
        current->right = newNode;
        cout << "Adding right:" << current->right->elem << endl;
        cola->Enqueue(current->right);
        count++;
      }
      arrayIdx++;
    }
  }

  Tree(int prearray[], int inarray[], int size) {
    Node *root = new Node(prearray[0]);
    Node *current = root;
  }

  void DisplayQueue() { this->queue->Display(); }

  void Preorder() {
    Stack *stack = new Stack(10);
    Node *current = this->root;

    cout << "Preorder: ";
    while (current != NULL || !stack->isEmpty()) {
      if (current != NULL) {
        printf("%d ", current->elem);
        stack->Push(current);
        current = current->left;
      } else {
        current = stack->Pop()->right;
      }
    }
  }

  void Inorder() {
    Stack *stack = new Stack(10);
    Node *current = this->root;
    Node *next = NULL;

    cout << "Inorder: ";
    while (current != NULL || !stack->isEmpty()) {
      if (current != NULL) {
        stack->Push(current);
        current = current->left;
      } else {
        next = stack->Pop();
        printf("%d ", next->elem);
        current = next->right;
      }
    }
  }

  void Postorder() {
    Stack *stack = new Stack(12);
    Node *current = this->root;
    long int ptr;

    cout << "Postorder: ";
    while (current != NULL || !stack->isEmpty()) {
      if (current != NULL) {
        stack->Push(current);
        current = current->left;
      } else {
        current = stack->Pop();
        ptr = (long int)current;
        if (ptr > 0) {
          stack->Push((Node *)(-1 * ptr));
          current = current->right;
        } else {
          printf("%d ", ((Node *)(-1 * ptr))->elem);
          current = NULL;
        }
      }
    }
  }

  void LevelOrder() {
    cout << "Levelorder: ";
    printf("%d ", root->elem);
    Queue *displayQueue = new Queue(10);
    displayQueue->Enqueue(root);

    while (!displayQueue->isEmpty()) {
      Node *current = displayQueue->Dequeue();
      if (current->left) {
        printf("%d ", current->left->elem);
        displayQueue->Enqueue(current->left);
      }
      if (current->right) {
        printf("%d ", current->right->elem);
        displayQueue->Enqueue(current->right);
      }
    }
  }

  int Height() {
    int h = 0;
    int maxH = 0;
    Node *current = this->root;
    Stack *stack = new Stack(5);

    while (current != NULL || !stack->isEmpty()) {
      if (current != NULL) {
        stack->Push(current);
        current = current->left;
        h++;
      } else {
        current = stack->Pop()->right;
        h--;
      }
      if (h > maxH) {
        maxH = h;
      }
    }

    return maxH;
  }

  int Count() {
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
};

int main() {
  int elems[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int size = sizeof(elems) / sizeof(int);

  Tree *tree = new Tree(elems, size);

  tree->Preorder();
  cout << endl;
  tree->Inorder();
  cout << endl;
  tree->Postorder();
  cout << endl;
  tree->LevelOrder();
  cout << endl;
  cout << "Height: " << tree->Height() << endl;
  cout << "Count: " << tree->Count() << endl;

  int preorderarray[] = {1, 2, 4, 8, 5, 3, 6, 7};
  int inorderarray[] = {8, 4, 2, 5, 1, 6, 3, 7};

  Tree *tree2 = new Tree(preorderarray, inorderarray, size);
  cout << endl;
}