#include <iostream>
using namespace std;

int nestedRecursion(int n) {
  if (n > 100) {
    printf("%d\n", n);
    return n - 10;
  } else {
    printf("%d ", n);
    nestedRecursion(nestedRecursion(n + 11));
  }
  return n;
}

int main() { nestedRecursion(92); }