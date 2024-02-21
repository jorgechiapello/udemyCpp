#include <iostream>
using namespace std;

class Stack {
private:
  int top;
  int size;
  int *A;

public:
  Stack(int size) {
    this->size = size;
    this->top = -1;
    this->A = new int[size];
  }
  ~Stack() { delete A; }

  bool isFull() { return top == size - 1; }

  bool isEmpty() { return top == -1; }

  void Push(int elem) {
    if (isFull()) {
      printf("Stack is full\n");
    } else {
      top++;
      A[top] = elem;
    }
  }

  int Pop() {
    int x = -1;
    if (isEmpty()) {
      printf("Stack is empty\n");
      return x;
    } else {
      x = A[top];
      top--;
    }
    return x;
  }

  int StackTop() {
    if (isEmpty()) {
      return -1;
    }
    return A[top];
  }

  int Peek(int index) {
    int x = -1;
    if (top - index + 1 < 0 || top - index + 1 == size) {
      printf("Invalid position!");
    } else {
      x = A[top - index + 1];
    }
    return x;
  }

  void Display() {
    if (this->isEmpty()) {
      printf("Stack is empty\n");
    } else {
      for (int i = top; i > 0; i--) {
        printf("Elem: %d\n", A[i]);
      }
    }
  }
};

int main() {
  Stack *stack = new Stack(6);
  printf("isEmpty: %d\n", stack->isEmpty());
  printf("isFull: %d\n", stack->isFull());
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