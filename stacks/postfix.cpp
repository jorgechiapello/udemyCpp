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
  ~Stack() { delete[] A; }

  bool isFull() { return top == size - 1; }

  bool isEmpty() { return top == -1; }

  void Push(char elem) {
    if (isFull()) {
      printf("Stack is full\n");
    } else {
      top++;
      A[top] = elem;
    }
  }

  char Pop() {
    char x = '\0';
    if (isEmpty()) {
      printf("Stack is empty\n");
    } else {
      x = A[top];
      top--;
    }
    return x;
  }

  char StackTop() {
    if (isEmpty()) {
      return -1;
    }
    return A[top];
  }
};

int outPrecedence(char x) {
  if (x == '+' || x == '-') {
    return 1;
  } else if (x == '*' || x == '/') {
    return 3;
  } else if (x == '^') {
    return 6;
  } else if (x == '(') {
    return 7;
  } else if (x == ')') {
    return 0;
  }
  return -1;
}

int inPrecedence(char x) {
  if (x == '+' || x == '-') {
    return 2;
  } else if (x == '*' || x == '/') {
    return 4;
  } else if (x == '^') {
    return 5;
  } else if (x == '(') {
    return 0;
  }
  return -1;
}

bool isOperand(char x) {
  if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' ||
      x == ')') {
    return false;
  }
  return true;
}

char *convertToPostfix(char *infix) {
  int size = strlen(infix);
  Stack *stack = new Stack(size + 1);
  char *postfix = new char[size + 1];
  int i = 0, j = 0;

  while (infix[i] != '\0') {
    if (isOperand(infix[i])) {
      postfix[j++] = infix[i++];
    } else {
      if (stack->isEmpty() ||
          outPrecedence(infix[i]) > inPrecedence(stack->StackTop())) {
        stack->Push(infix[i++]);
      } else if (outPrecedence(infix[i]) == inPrecedence(stack->StackTop())) {
        stack->Pop();
      } else {
        postfix[j++] = stack->StackTop();
        stack->Pop();
      }
    }
  }

  while (!stack->isEmpty() && stack->StackTop() != ')') {
    postfix[j++] = stack->StackTop();
    stack->Pop();
  }

  postfix[j] = '\0';
  return postfix;
}

int main() {
  char infix[] = "((a+b)*c)-d^e^f";
  char *postfix = convertToPostfix(infix);
  cout << postfix << endl;
  delete[] postfix;
}
