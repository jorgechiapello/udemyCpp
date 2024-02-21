#include <iostream>
using namespace std;

class LowerSquare {
private:
  int *A;

public:
  int n;
  int length;
  LowerSquare() {
    n = 5;
    length = 0;
    A = new int[(n * (n + 1)) / 2];
  }
  LowerSquare(int n) {
    this->n = n;
    length = 0;
    A = new int[(n * (n + 1)) / 2];
  }
  ~LowerSquare() { delete[] A; }

  int Get(int i, int j) {
    if (i >= j) {
      // Row major
      // 1 | 2 3 | 4 5 6 | 7 8 9 10
      int offset = (i * (i - 1)) / 2;
      return A[offset + j - 1];
    }
    return 0;
  };

  void Set(int i, int j, int number) {
    if (i >= j) {
      // Row major
      // 1 | 2 3 | 4 5 6 | 7 8 9 10
      int offset = (i * (i - 1)) / 2;
      A[offset + j - 1] = number;
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
};

int main() {
  LowerSquare *lower = new LowerSquare(5);

  lower->Set(1, 1, 10);
  lower->Set(1, 2, 20);
  lower->Set(2, 1, 30);
  lower->Set(4, 4, 50);
  lower->Set(5, 4, 60);

  lower->Display();

  cout << endl;

  lower->Set(20);
  lower->Set(25);

  cout << endl;

  lower->Display();
}