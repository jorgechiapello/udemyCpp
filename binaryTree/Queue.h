#include "Node.h"
#include <iostream>
using namespace std;

class Queue {
private:
  int size;
  int rear;
  int front;
  // pointer to array of pointers
  Node **elems; // [Node*]*: Pointer to [Pointer to Node]

public:
  Queue(int size);
  ~Queue();
  bool isEmpty();
  bool isFull();
  void Enqueue(Node *elem);
  Node *Dequeue();
  void Display();
  void resetPointers();
  Node *GetFront();
};

Queue::Queue(int size) {
  this->size = size;
  rear = front = -1;
  elems = new Node *[size];
}

Queue::~Queue() { delete[] elems; }
bool Queue::isEmpty() { return rear == front; }
bool Queue::isFull() { return rear == size - 1; }

void Queue::Enqueue(Node *node) {
  if (isFull()) {
    printf("Queue is full\n");
    return;
  }
  rear++;
  elems[rear] = node;
};

Node *Queue::Dequeue() {
  Node *x = NULL;
  if (isEmpty()) {
    printf("Queue is empty\n");
  } else {
    front++;
    x = elems[front];
  }
  if (isEmpty())
    resetPointers();
  return x;
};

void Queue::Display() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return;
  }
  for (int i = front + 1; i <= rear; i++) {
    printf("elem: %d, index: %d\n", elems[i]->elem, i);
  }
}

void Queue::resetPointers() { front = rear = -1; }

Node *Queue::GetFront() { return this->elems[front + 1]; }