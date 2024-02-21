#include <iostream>
using namespace std;

int power(int n, int p) {
  if (p == 0) {
    return 1;
  }

  if (p % 2 == 0) {
    return power(n * n, p / 2);
  }

  return n * power(n * n, p - 1);
};

int sum(int n) {
  if (n == 1) {
    return 1;
  };
  return n + sum(n - 1);
};

int fac(int n) {
  if (n == 1) {
    return 1;
  };
  return n * fac(n - 1);
};

// Se puede usar una sola vez porque usa variables estaticas
double e(double x, double t) {
  static double p = 1, f = 1;
  double r;

  if (t == 0)
    return 1;

  r = e(x, t - 1);
  p = p * x;
  f = f * t;

  return r + (p / f);
};

int main() {
  cout << "Power of 2^8: " << power(2, 8) << endl;
  cout << "Sum of 3: " << sum(3) << endl;
  cout << "Factorial of 3: " << fac(3) << endl;
  double t1 = e(1, 10);
  cout << "e^1 with 10 terms: " << t1 << endl;
}