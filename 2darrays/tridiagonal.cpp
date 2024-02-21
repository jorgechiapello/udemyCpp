#include <iostream>
using namespace std;

int calculateSize(int n) { return (3 * n) - 2; }

class Tridiagonal {
private:
  int *A;
  // Store lower diagonal, middle and upper
  int calculateIndex(int i, int j) {
    // lower diagonal, i - j = 1; example [2,1]
    if ((i - j) == 1) {
      return j - 1;
    }
    // middle, i = j; example [2,2]
    if (i == j) {
      return n - 1 + i - 1;
    }
    // upper, i - j = -1; example [1,2]
    if ((i - j) == -1) {
      return (2 * n) - 1 + i - 1;
    }
    return -1;
  }

public:
  int n;
  int length;
  Tridiagonal() {
    n = 5;
    length = 0;
    A = new int[calculateSize(n)];
  }
  Tridiagonal(int n) {
    this->n = n;
    length = 0;
    A = new int[calculateSize(n)];
  }
  ~Tridiagonal() { delete[] A; }

  int Get(int i, int j) {
    int index = this->calculateIndex(i, j);
    if (index > -1) {
      return A[index];
    }
    return 0;
  };

  void Set(int i, int j, int number) {
    int index = this->calculateIndex(i, j);
    if (index > -1) {
      A[index] = number;
      length++;
    }
  };

  void Set(int number) {
    int i = 0;
    while (i < (n * (n + 1)) / 2 && A[i] != 0) {
      i++;
    }
    A[i] = number;
    length++;
  };

  void Display() {
    for (int i = 1; i < this->n + 1; i++) {
      for (int j = 1; j < this->n + 1; j++) {

        if (this->Get(i, j) < 10) {
          printf(" %d ", this->Get(i, j));
        } else {
          printf("%d ", this->Get(i, j));
        }
      }
      cout << endl;
    }
  };

  void DisplayInner() {
    for (int i = 0; i < calculateSize(n); i++) {
      printf("%d ", A[i]);
    }
  }
};

int main() {
  Tridiagonal *tridiagonal = new Tridiagonal(5);

  tridiagonal->Set(1, 1, 20);
  tridiagonal->Set(12);
  tridiagonal->Set(13);
  tridiagonal->Set(14);
  tridiagonal->Set(15);
  tridiagonal->Set(21);
  tridiagonal->Set(22);
  tridiagonal->Set(24);
  tridiagonal->Set(25);
  tridiagonal->Set(1, 2, 30);
  tridiagonal->Set(2, 3, 31);
  tridiagonal->Set(3, 4, 32);
  tridiagonal->Set(4, 5, 33);

  tridiagonal->Display();
  cout << endl;

  tridiagonal->DisplayInner();
  cout << endl;
}