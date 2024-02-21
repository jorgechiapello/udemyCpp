#include <iostream>
using namespace std;

// Run g++ -Wno-sizeof-array-argument -o arrayPointer ./arrayPointer.cpp
void printSizeArray(int A[]) {
  // Prints the size of the pointer, not the size of the array
  // Because the function is taking a pointer as input
  cout << "size of A inside function: " << sizeof(A) / sizeof(int) << endl;
};

int *initArray(int size) {
  int *p;
  p = new int[size];

  for (int i = 0; i < size; i++) {
    p[i] = i + 1;
  }

  return p;
};

int main() {
  int A[] = {1, 2, 3, 4, 5};
  printSizeArray(A);

  cout << "size of A inside in main: " << sizeof(A) / sizeof(int) << endl;

  int size = 10;
  int *ptr = initArray(size);

  for (int i = 0; i < size; i++) {
    cout << ptr[i] << endl;
  }
}