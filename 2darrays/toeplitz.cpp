#include <iostream>
using namespace std;

// Store first row and first column starting from second element
int calculateSize(int n) { return n + n - 1; }

class Toeplitz {
private:
  int *A;
  // Store first row and first column starting from second element
  int calculateIndex(int i, int j) {
    //(5x5) 1 2 3 4 5 | 6 7 8 9
    if (i <= j) {
      return j - i;
    }
    return n + (i - j) - 1;
  }

public:
  int n;
  int length;
  Toeplitz() {
    n = 5;
    length = 0;
    A = new int[calculateSize(n)];
  }
  Toeplitz(int n) {
    this->n = n;
    length = 0;
    A = new int[calculateSize(n)];
  }
  ~Toeplitz() { delete[] A; }

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
  Toeplitz *toeplitz = new Toeplitz(5);

  toeplitz->Set(12);
  toeplitz->Set(13);
  toeplitz->Set(14);
  toeplitz->Set(15);
  toeplitz->Set(16);
  toeplitz->Set(17);
  toeplitz->Set(18);
  toeplitz->Set(19);
  toeplitz->Set(20);

  toeplitz->Display();
  cout << endl;

  toeplitz->DisplayInner();
  cout << endl;
}