#include <iostream>
using namespace std;

int fun(int &x, int c) {
  c = c - 1;
  if (c == 0)
    return 1;
  x = x + 1;
  cout << x << endl;
  return fun(x, c) * x;
}

int main() {
  int p = 2;
  cout << fun(p, p) << endl;
}