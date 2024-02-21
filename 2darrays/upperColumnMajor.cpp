#include <iostream>
using namespace std;

int calculateSize(int n) { return (n * (n + 1)) / 2; }

class LowerSquare {
private:
  int *A;

  // Column major
  // 1 2 3
  // 0 4 5
  // 0 0 6
  // 1 | 2 4 | 3 5 6
  // (4x4) [1,2] = 2, index = 2, offset = 1
  // (4x4) [2,3] = 5, index = 4, offset = 2
  int calculateIndex(int i, int j) {
    // Misma formula que en row major para lower triangular
    // pero uso la columna para el offset
    int offset = (j * (j - 1)) / 2;
    int index = offset + i - 1;
    return index;
  }

public:
  int n;
  int length;
  LowerSquare() {
    this->n = 5;
    length = 0;
    A = new int[calculateSize(n)];
  }
  LowerSquare(int n) {
    this->n = n;
    length = 0;
    A = new int[calculateSize(n)];
  }
  ~LowerSquare() { delete[] A; }

  int Get(int i, int j) {
    if (i <= j) {
      int index = this->calculateIndex(i, j);
      return A[index];
    }
    return 0;
  };

  void Set(int i, int j, int number) {
    if (i <= j) {
      int index = this->calculateIndex(i, j);
      A[index] = number;
      length++;
    }
  };

  void Set(int number) {
    int i = 0;
    while (i < calculateSize(n) && A[i] != 0) {
      i++;
    }
    A[i] = number;
    length++;
  };

  void Display() {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        int number = Get(i, j);
        if (number < 10) {
          printf(" %d ", number);
        } else {
          printf("%d ", number);
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
  LowerSquare *upper = new LowerSquare(5);

  upper->Set(1, 1, 1);
  upper->Set(1, 2, 25);
  upper->Set(1, 3, 26);
  upper->Set(1, 4, 27);
  upper->Set(1, 5, 28);
  upper->Set(2, 2, 20);
  upper->Set(3, 3, 30);
  upper->Set(4, 4, 50);
  upper->Set(4, 5, 55);
  upper->Set(5, 4, 60);
  upper->Set(5, 5, 70);

  upper->Display();
  upper->DisplayInner();
  cout << endl;
}