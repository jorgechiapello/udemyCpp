#include <iostream>
using namespace std;

int calculateSize(int n) { return (n * (n + 1)) / 2; }

class Symmetric {
private:
  int *A;
  // Row major
  // 1 | 2 3 | 4 5 6 | 7 8 9 10
  int calculateIndex(int i, int j) {
    int offset = (i * (i - 1)) / 2;
    return offset + j - 1;
  }

public:
  int n;
  int length;
  Symmetric() {
    n = 5;
    length = 0;
    A = new int[calculateSize(n)];
  }
  Symmetric(int n) {
    this->n = n;
    length = 0;
    A = new int[calculateSize(n)];
  }
  ~Symmetric() { delete[] A; }

  int Get(int i, int j) {
    if (i >= j) {
      int index = this->calculateIndex(i, j);
      return A[index];
    } else {
      int index = this->calculateIndex(j, i);
      return A[index];
    }
  };

  void Set(int i, int j, int number) {
    if (i >= j) {
      int index = this->calculateIndex(i, j);
      A[index] = number;
      length++;
    } else {
      int index = this->calculateIndex(j, i);
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
  Symmetric *symmetric = new Symmetric(5);

  symmetric->Set(1, 1, 10);
  symmetric->Set(1, 2, 20);
  symmetric->Set(1, 5, 25);
  symmetric->Set(2, 1, 30);
  symmetric->Set(4, 4, 50);
  symmetric->Set(5, 4, 60);
  symmetric->Set(5, 5, 70);

  symmetric->Set(20);
  symmetric->Set(25);

  symmetric->Display();
  cout << endl;

  symmetric->DisplayInner();
  cout << endl;
}