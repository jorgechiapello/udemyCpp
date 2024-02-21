#include <iostream>
using namespace std;

static int swaps = 0;
static int comps = 0;

void swap(int &a, int &b) {
  int aux = a;
  a = b;
  b = aux;
  swaps++;
}

void Display(int *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
}

void BubbleSort(int *array, int size) {
  for (int n = 0; n < size; n++) {
    for (int i = 0; i < size - n - 1; i++) {
      comps++;
      if (array[i] > array[i + 1]) {
        swap(array[i], array[i + 1]);
      }
    }
  }
}

int main() {
  int A[] = {76, 43, 22, 91,  58, 34, 19,  67,  11,  28, 56, 39, 4,  61, 25,
             50, 16, 72, 3,   68, 31, 89,  5,   41,  20, 77, 12, 55, 29, 60,
             9,  37, 23, 65,  18, 49, 88,  13,  47,  70, 2,  83, 38, 64, 15,
             71, 24, 52, 10,  79, 35, 84,  6,   53,  26, 63, 17, 44, 21, 75,
             14, 57, 30, 66,  8,  36, 82,  48,  80,  40, 97, 32, 59, 27, 74,
             7,  51, 42, 87,  92, 45, 78,  33,  85,  69, 94, 46, 81, 54, 95,
             62, 99, 73, 100, 90, 98, 102, 103, 121, 115};
  int size = sizeof(A) / sizeof(int);
  cout << "size: " << size << endl;
  BubbleSort(A, size);
  Display(A, size);
  cout << endl << "swaps: " << swaps << endl;
  cout << "comparaciones: " << comps << endl;
}