#include <iostream>
using namespace std;

void printAddress(int A[]) { cout << "printAddress: " << A << endl; };

int **initArray(int f, int c) {
  int **ptr = new int *[f];
  for (int i = 0; i < f; i++) {
    ptr[i] = new int[c];
    for (int j = 0; j < c; j++) {
      ptr[i][j] = i * c + j + 1;
      printf("ptr2[%d][%d]: %d\n", i, j, ptr[i][j]);
    }
  }

  return ptr;
};

int main() {
  int f = 4;
  int c = 2;

  int A[f][c];

  cout << "address of A: " << A << endl;
  cout << A[0] << ", " << A[1] << ", " << A[2] << ", " << A[3] << endl;
  cout << &A[0][0] << ", " << &A[0][1] << endl;
  cout << "sizeof(int): " << sizeof(int) << endl;
  cout << "sizeof(A): " << sizeof(A) << endl;
  cout << "Number of elements: " << sizeof(A) / sizeof(int) << endl;

  cout << "*A: " << *A << endl;
  cout << "&A: " << &A << endl;

  int **array2D = initArray(f, c);
  cout << "array2D: " << array2D << endl;
  cout << "*array2D: " << *array2D << endl;

  printf("array2D[%d]: %p \n", 0, array2D[0]);
  printf("array2D[%d]: %p \n", 1, array2D[1]);
  int diff = array2D[0] - array2D[1];
  // La distancia en bytes desde una direccion a otra
  printf("array2D[0] - array2D[1]: %d \n", diff * -1);
}