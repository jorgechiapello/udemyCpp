#include <iostream>
using namespace std;

void headRecursion(int n) {
  if (n > 0) {
    headRecursion(n - 1);
    printf("%d ", n);
  }
}

void tailRecursion(int n) {
  if (n > 0) {
    printf("%d ", n);
    tailRecursion(n - 1);
  }
}

int powerOf(int n) {
  // Variables estaticas son lo mismo que variable globales
  static int x = 0;
  if (n > 0) {
    x++;
    return powerOf(n - 1) + x;
  }
  return 0;
}

int main() {
  int x = 3;

  cout << "Head recursion: ";
  headRecursion(x);

  cout << endl << "For loop replacing head recursion: ";

  // no podemos reemplazar head recursion 1:1 con otra estructura
  for (int h = 0; h < x; h++) {
    printf("%d ", h + 1);
  }

  cout << endl << "Tail recursion: ";
  tailRecursion(x);
  cout << "while replacing tail recursion: " << endl;

  int t = x;
  // is facil de reemplazar una tail recursion
  while (t > 0) {
    printf("%d ", t);
    t--;
  }

  cout << "Recursion static variable: " << powerOf(10) << endl;
  return 0;
}
