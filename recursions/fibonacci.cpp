#include <iostream>
using namespace std;

int F[10];
int callsMem = 0;

int fibWithMem(int n) {
  callsMem++;
  printf("Call with n = %d\n", n);

  if (n < 2) {
    F[n] = n;
    return n;
  };

  int f1, f2;

  if (F[n - 1]) {
    f1 = F[n - 1];
  } else {
    f1 = fibWithMem(n - 1);
  }

  if (F[n - 2]) {
    f2 = F[n - 2];
  } else {
    f2 = fibWithMem(n - 2);
  }

  int res = f1 + f2;
  F[n] = res;
  return res;
};

int calls = 0;
int fib(int n) {
  calls++;
  printf("Call with n = %d\n", n);

  if (n < 2) {
    return n;
  };
  return fib(n - 1) + fib(n - 2);
};
int main() {
  int n = 5;
  cout << "Terms:" << n << endl;

  cout << "Fibonacci with memoize: " << fibWithMem(n) << endl;
  cout << "Calls with Memoize: " << callsMem << endl;

  cout << "Fibonacci no memoize: " << fib(n) << endl;
  cout << "Calls with not Memoize: " << calls << endl;
}