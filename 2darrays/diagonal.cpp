#include <iostream>
using namespace std;

class Diagonal {
private:
  int *A;

public:
  int size;
  int length;
  Diagonal() {
    size = 10;
    length = 0;
    A = new int[10];
  }
  Diagonal(int n) {
    size = n;
    length = 0;
    A = new int[size];
  }
  ~Diagonal() { delete[] A; }

  int Get(int i, int j) {

    if (i != j) {
      return 0;
    }
    return A[i - 1];
  }

  void Set(int i, int j, int number) {
    if (length == size) {
      printf("Matrix is full");
      return;
    }

    if (i == j) {
      A[i - 1] = number;
      length++;
    }
  }
  void Display() {
    for (int i = 0; i < size - 1; i++) {
      printf("%d, ", A[i]);
    }
    printf("%d. ", A[size - 1]);
  }
};

int main() {
  Diagonal *diagonal = new Diagonal(5);

  diagonal->Set(1, 1, 1);
  diagonal->Set(2, 2, 2);
  diagonal->Set(3, 3, 3);
  diagonal->Set(4, 4, 4);
  diagonal->Set(5, 5, 5);

  diagonal->Display();

  cout << endl;

  for (int i = 1; i <= diagonal->length; i++) {
    printf("At position %d: %d\n", i, diagonal->Get(i, i));
  }
}