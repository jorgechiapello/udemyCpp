#include <iostream>
using namespace std;

int add(int x, int y) { return x + y; };

void swapByAddress(int *x, int *y) {
  // *x va y busca el valor, tmp es un int
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

void swapByReferece(int &x, int &y) {
  int tmp = x;
  x = y;
  y = tmp;
}

int main() {

  int a = 10;
  int b = 30;

  cout << "Add: " << add(a, b) << endl;

  cout << "Before swap: " << endl;
  cout << "a: " << a << ", b: " << b << endl;

  cout << "Swap by adress: " << endl;
  swapByAddress(&a, &b);

  cout << "After swap: " << endl;
  cout << "a: " << a << ", b: " << b << endl;

  // *p gets the value of the pointer, &a get the value's address
  int *p = &a;
  cout << "*p: " << *p << endl;

  cout << "Swap by reference: " << endl;
  swapByReferece(a, b);
  cout << "After swap by ref: " << endl;
  cout << "a: " << a << ", b: " << b << endl;
}