#include "Node.h"
#include <iostream>
using namespace std;

class Stack {
private:
  int top;
  int size;
  Node **A;

public:
  Stack(int size);
  ~Stack();
  bool isFull();
  bool isEmpty();
  void Push(Node *node);
  Node *Pop();
  Node *StackTop();
  Node *Peek(int index);
  void Display();
  void DisplayInner();
};

Stack::Stack(int size) {
  this->size = size;
  this->top = -1;
  this->A = new Node *[size];
}
Stack::~Stack() { delete A; }

bool Stack::isFull() { return top == size - 1; }

bool Stack::isEmpty() { return top == -1; }

void Stack::Push(Node *node) {
  if (isFull()) {
    printf("Stack is full\n");
  } else {
    top++;
    A[top] = node;
  }
}

Node *Stack::Pop() {
  Node *x = NULL;
  if (isEmpty()) {
    printf("Stack is empty\n");
    return x;
  } else {
    x = A[top];
    top--;
  }
  return x;
}

Node *Stack::StackTop() {
  if (isEmpty()) {
    return NULL;
  }
  return A[top];
}

Node *Stack::Peek(int index) {
  Node *x = NULL;
  if (top - index + 1 < 0 || top - index + 1 == size) {
    printf("Invalid position!");
  } else {
    x = A[top - index + 1];
  }
  return x;
}

void Stack::Display() {
  if (this->isEmpty()) {
    printf("Stack is empty\n");
  } else {
    for (int i = top; i > 0; i--) {
      printf("Elem: %d\n", A[i]->elem);
    }
  }
}

void Stack::DisplayInner() {
  if (this->isEmpty()) {
    printf("Stack is empty\n");
  } else {
    int i = 0;
    while (A[i]) {
      printf("%p\n", A[i]);
      // printf("Elem: %d\n", A[i]->elem);
      i++;
    }
  }
}