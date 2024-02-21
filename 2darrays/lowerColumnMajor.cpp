#include <iostream>
using namespace std;

int calculateSize(int n) { return (n * (n + 1)) / 2; }

class LowerSquare {
private:
  int *A;

  int calculateIndex(int i, int j) {
    return (this->n * (j - 1) - ((j - 2) * (j - 1) / 2)) + (i - j);
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
    if (i >= j) {
      // Column major
      // 1 4 7 | 5 8 | 9
      int index = this->calculateIndex(i, j);
      return A[index];
    }
    return 0;
  };

  void Set(int i, int j, int number) {
    if (i >= j) {
      // Column major
      // 1 2 3 4 5 | 6 7 8 9 | 10 11 12 | 13 14 | 15

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
  LowerSquare *lower = new LowerSquare(5);

  lower->Set(1, 1, 1);
  lower->Set(2, 1, 25);
  lower->Set(2, 2, 20);
  lower->Set(3, 3, 30);
  lower->Set(4, 4, 50);
  lower->Set(5, 4, 60);
  lower->Set(5, 5, 70);

  lower->Display();
  // cout << endl;

  lower->DisplayInner();
  cout << endl;
}