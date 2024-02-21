#include <iostream>
using namespace std;

int calculateSize(int n) { return (n * (n + 1)) / 2; }

class UpperSquare {
private:
  int *A;

  // Row major
  // 1 2 3 4 | 5 6 7 | 8 9 | 10
  //(4x4) 1,4 = 4 // index = 3 // (0 + 4) - 1 = 0 + 3
  //(4x4) 1,2 = 2 // index = 1 // (0 + 2) - 1 = 0 + 2
  //(4x4) 2,2 = 5 // index = 4 // ([4] + 1) - 1 = 4
  //(4x4) 2,4 = 7 // index = 6 // ([4] + 3) - 1 = 3
  //(4x4) 3,3 = 8 // index = 7 // ([4 + 3] + 1) - 1 = 7 + 1
  //(4x4) 3,4 = 9 // index = 8 // ([4 + 3] + 2) - 1 = 7 + 2
  //(4x4) 4,4 = 10 // index = 9 // ([4 + 3 + 2] + 1) - 1 = 7 + 2
  // [4 + 3 + 2] = n + n-1 + n-2 = ((n * n-1)/2) - ((n-1*n-2)/2)
  int calculateIndex(int i, int j) {
    // Misma formula que en column major para lower triangular
    int offset = (this->n * (i - 1)) - (((i - 2) * (i - 1)) / 2);
    int index = offset + (j - i);
    return index;
  }

public:
  int n;
  int length;
  UpperSquare() {
    this->n = 5;
    length = 0;
    A = new int[calculateSize(n)];
  }
  UpperSquare(int n) {
    this->n = n;
    length = 0;
    A = new int[calculateSize(n)];
  }
  ~UpperSquare() { delete[] A; }

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
  UpperSquare *upper = new UpperSquare(5);

  upper->Set(1, 1, 1);
  upper->Set(1, 2, 25);
  upper->Set(1, 3, 26);
  upper->Set(1, 4, 27);
  upper->Set(1, 5, 28);
  upper->Set(2, 2, 20);
  upper->Set(3, 3, 30);
  upper->Set(4, 4, 50);
  upper->Set(5, 4, 60);
  upper->Set(5, 5, 70);

  upper->Display();
  upper->DisplayInner();
  cout << endl;
}