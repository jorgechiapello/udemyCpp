#include <cstring>
#include <iostream>
using namespace std;

class Stack {
private:
  int top;
  int size;
  char *A;

public:
  Stack(int size) {
    this->size = size;
    this->top = -1;
    this->A = new char[size];
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

bool isBalanced(char *exp) {
  int size = strlen(exp);
  Stack *stack = new Stack(size);

  for (int i = 0; exp[i] != '\0'; i++) {
    if (exp[i] == '(') {
      stack->Push('(');
    } else if (exp[i] == ')') {
      if (stack->isEmpty()) {
        return false;
      }
      stack->Pop();
    }
  }

  return stack->isEmpty();
}

int main() {
  char exp1[] = "(hi)";
  printf("exp %s is balanced: %i\n", exp1, isBalanced(exp1));

  char exp2[] = "((a+b)(c*d))";
  printf("exp %s is balanced: %i\n", exp2, isBalanced(exp2));

  char exp3[] = "((a+b)(c*d)";
  printf("exp %s is balanced: %i\n", exp3, isBalanced(exp3));

  char exp4[] = "((a+b)(c*d)))";
  printf("exp %s is balanced: %i\n", exp4, isBalanced(exp4));
}