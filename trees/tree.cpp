#include "Queue.h"
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

  void Create() {
    int x;
    cout << "Enter root value: " << flush;
    cin >> x;
    Node *elem = new Node(x);
    root = elem;
    queue->Enqueue(elem);

    Node *ptr;
    while (!queue->isEmpty()) {
      ptr = queue->Dequeue();
      cout << "Enter left child value of " << ptr->elem << ": " << flush;
      cin >> x;
      if (x != -1) {
        Node *newNode = new Node(x);
        ptr->left = newNode;
        queue->Enqueue(newNode);
      }

      cout << "Enter right child value of " << ptr->elem << ": " << flush;
      cin >> x;
      if (x != -1) {
        Node *newNode = new Node(x);
        ptr->right = newNode;
        queue->Enqueue(newNode);
      }
    }
  }

  void DisplayQueue() { this->queue->Display(); }

  void preorder(Node *current) {
    if (current) {
      printf("%d ", current->elem);
      this->preorder(current->left);
      this->preorder(current->right);
    }
  }

  void Preorder() {
    cout << "Preorder: ";
    this->preorder(this->root);
  }

  void inorder(Node *current) {
    if (current) {
      this->inorder(current->left);
      printf("%d ", current->elem);
      this->inorder(current->right);
    }
  }

  void Inorder() {
    cout << "Inorder: ";
    this->inorder(this->root);
  }

  void postorder(Node *current) {
    if (current) {
      this->postorder(current->left);
      this->postorder(current->right);
      printf("%d ", current->elem);
    }
  }

  void Postorder() {
    cout << "Postorder: ";
    this->postorder(this->root);
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
};

int main() {
  int elems[] = {1, 2, 3, 4, 5, 6, 7, 8};
  Tree *tree = new Tree(elems, 8);
  tree->Preorder();
  cout << endl;
  tree->Inorder();
  cout << endl;
  tree->Postorder();
  cout << endl;
  tree->LevelOrder();
  cout << endl;
}