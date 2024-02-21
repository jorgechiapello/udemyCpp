#include <iostream>
using namespace std;

struct Node {
  Node *prev;
  Node *next;
  int elem;
  Node(int elem) {
    this->elem = elem;
    this->prev = NULL;
    this->next = NULL;
  }
};

class DoubleLL {
public:
  Node *firstPtr;
  Node *lastPtr;
  DoubleLL(int elem) {
    Node *node = new Node(elem);
    this->firstPtr = node;
    this->lastPtr = node;
  }
  DoubleLL() {
    this->firstPtr = NULL;
    this->lastPtr = NULL;
  }
  bool isEmpty() { return !this->firstPtr; }

  void Display() {

    if (this->isEmpty()) {
      cout << "Empty List" << endl;
      return;
    }

    Node *current = this->firstPtr;
    int index = 0;

    while (current) {
      printf("index: %d, elem: %d, prev: %p,current: %p, next: %p, \n", index,
             current->elem, current->prev, current, current->next);
      index++;
      current = current->next;
    }
  }

  void DisplayBackwards() {
    if (this->isEmpty()) {
      cout << "Empty List" << endl;
      return;
    }
    Node *current = this->lastPtr;
    while (current) {
      printf("elem: %d\n", current->elem);
      current = current->prev;
    }
  }

  void Insert(int elem, int index) {
    Node *newNode = new Node(elem);

    if (this->isEmpty()) {
      this->firstPtr = newNode;
      this->lastPtr = newNode;
      return;
    }

    if (index == 0) {
      newNode->next = this->firstPtr;
      this->firstPtr->prev = newNode;
      this->firstPtr = newNode;
      return;
    }

    Node *target = this->firstPtr;

    for (int i = 0; i < index - 1; i++) {
      if (!target->next)
        break;
      target = target->next;
    }

    if (target->next) {
      target->next->prev = newNode;
    }
    newNode->next = target->next;
    newNode->prev = target;
    target->next = newNode;

    if (!newNode->next) {
      this->lastPtr = newNode;
    }
  }

  void Delete(int index) {
    Node *target = this->firstPtr;

    for (int i = 0; i < index; i++) {
      if (!target->next)
        break;
      target = target->next;
    }

    if (target->prev) {
      target->prev->next = target->next;
    }
    if (target->next) {
      target->next->prev = target->prev;
    }
    delete target;
  }

  void Reverse() {
    Node *current = this->firstPtr;
    this->firstPtr = lastPtr;
    this->lastPtr = current;

    while (current) {
      Node *aux = current->next;
      current->next = current->prev;
      current->prev = aux;
      // prev now contains the original next elem
      current = current->prev;
    }
  }
};

int main() {
  DoubleLL *doubleLL = new DoubleLL();
  doubleLL->Display();
  cout << endl;
  doubleLL->DisplayBackwards();
  cout << endl;
  doubleLL->Insert(15, 1);
  doubleLL->Insert(16, 2);
  doubleLL->Insert(20, 1);
  doubleLL->Insert(29, 0);

  doubleLL->Display();
  cout << endl;
  doubleLL->DisplayBackwards();
  cout << endl;
  doubleLL->Delete(1);
  doubleLL->Display();
  cout << endl;
  doubleLL->Reverse();
  doubleLL->Display();
  cout << endl;
}