#include <iostream>
using namespace std;

struct Node {
  int elem;
  Node *next;
  Node(int elem) {
    this->elem = elem;
    this->next = NULL;
  }
};

class Stack {
private:
  int top;
  Node *topPtr;

public:
  Stack() { this->topPtr = NULL; }
  ~Stack() { delete topPtr; }

  bool isEmpty() { return topPtr == NULL; }

  void Push(int elem) {
    Node *newNode = new Node(elem);
    if (newNode == NULL) {
      printf("Stack is full");
    } else {
      newNode->next = topPtr;
      topPtr = newNode;
    }
  }

  int Pop() {
    Node *ptr;
    int x = -1;

    if (isEmpty()) {
      printf("Stack is empty");
      return x;
    } else {
      ptr = topPtr;
      x = ptr->elem;
      topPtr = ptr->next;
      free(ptr);
      return x;
    }
  }

  int StackTop() {
    if (topPtr)
      return topPtr->elem;
    return -1;
  }

  int Peek(int index) {
    Node *ptr = topPtr;

    for (int i = 0; ptr != NULL & i < index - 1; i++) {
      ptr = ptr->next;
    }

    if (ptr == NULL) {
      printf("Invalid position");
      return -1;
    } else {
      return ptr->elem;
    }
  }

  void Display() {
    if (isEmpty()) {
      printf("Stack is empty");
    } else {
      Node *current = topPtr;
      while (current) {
        printf("Elem: %d\n", current->elem);
        current = current->next;
      }
    }
  }
};

int main() {
  Stack *stack = new Stack();
  printf("isEmpty: %d\n", stack->isEmpty());
  cout << endl;
  stack->Pop();
  stack->Push(10);
  stack->Push(15);
  stack->Push(18);
  stack->Push(22);
  stack->Push(24);
  stack->Push(30);
  stack->Push(35);
  cout << endl;
  stack->Display();
  cout << "Peek 1: " << stack->Peek(1) << endl << endl;
  stack->Pop();
  stack->Display();
}