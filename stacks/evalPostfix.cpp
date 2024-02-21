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

  void Push(int elem) {
    if (isFull()) {
      printf("Stack is full\n");
    } else {
      top++;
      A[top] = elem;
    }
  }

  int Pop() {
    char x = '\0';
    if (isEmpty()) {
      printf("Stack is empty\n");
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
};

bool isOperand(char symbol) { return symbol > 47 && symbol < 58; }

int eval(int x1, int x2, char op) {
  switch (op) {
  case '+':
    return x1 + x2;
    break;
  case '-':
    return x1 - x2;
    break;
  case '*':
    return x1 * x2;
    break;
  case '/':
    return x1 / x2;
    break;
  default:
    return -1;
  }
};

int evalPostfix(char *postfix) {
  int size = strlen(postfix);
  Stack *stack = new Stack(size);

  for (int i = 0; postfix[i] != '\0'; i++) {
    if (isOperand(postfix[i])) {
      stack->Push(postfix[i] - '0');
    } else {
      int x2 = stack->Pop();
      int x1 = stack->Pop();
      int res = eval(x1, x2, postfix[i]);
      stack->Push(res);
    }
  }
  return stack->StackTop();
};

int main() {
  char postfix[] = "35*62/+4-";
  cout << evalPostfix(postfix) << endl;
}
