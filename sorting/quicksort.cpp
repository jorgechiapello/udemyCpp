#include <iostream>
using namespace std;

static int swaps = 0;
static int comps = 0;

void swap(int &a, int &b) {
  // printf("swap %d for %d\n", a, b);
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

int partition(int A[], int l, int h) {
  int pivot = A[l];
  int i = l, j = h;

  do {
    while (A[i] <= pivot) {
      i++;
      comps++;
    };

    while (A[j] > pivot) {
      j--;
      comps++;
    };
    if (i < j)
      swap(A[i], A[j]);
  } while (i < j);

  swap(A[l], A[j]);
  return j;
}

void QuickSort(int A[], int l, int h) {
  int j;
  if (l < h) {
    j = partition(A, l, h);
    QuickSort(A, l, j);
    QuickSort(A, j + 1, h);
  }
}

int main() {
  int A[] = {3, 25, 36, 44, 47, 54, 58, 62, 77, 81, 84, 86};
  int size = sizeof(A) / sizeof(int);
  QuickSort(A, 0, size - 1);
  Display(A, size);
  cout << endl << "swaps: " << swaps << endl;
  cout << "comparaciones: " << comps << endl;

  swaps = comps = 0;
  cout << "B" << endl;
  int B[] = {47, 36, 86, 77, 84, 62, 44, 58, 54, 3, 25, 81};
  int size2 = sizeof(B) / sizeof(int);
  QuickSort(B, 0, size2 - 1);
  Display(B, size2);
  cout << endl << "swaps: " << swaps << endl;
  cout << "comparaciones: " << comps << endl;

  swaps = comps = 0;
  cout << "C" << endl;
  int C[] = {76, 43, 22, 91,  58, 34, 19,  67,  11,  28, 56, 39, 4,  61, 25,
             50, 16, 72, 3,   68, 31, 89,  5,   41,  20, 77, 12, 55, 29, 60,
             9,  37, 23, 65,  18, 49, 88,  13,  47,  70, 2,  83, 38, 64, 15,
             71, 24, 52, 10,  79, 35, 84,  6,   53,  26, 63, 17, 44, 21, 75,
             14, 57, 30, 66,  8,  36, 82,  48,  80,  40, 97, 32, 59, 27, 74,
             7,  51, 42, 87,  92, 45, 78,  33,  85,  69, 94, 46, 81, 54, 95,
             62, 99, 73, 100, 90, 98, 102, 103, 121, 115};
  int size3 = sizeof(C) / sizeof(int);
  QuickSort(C, 0, size3 - 1);
  Display(C, size3);
  cout << endl << "swaps: " << swaps << endl;
  cout << "comparaciones: " << comps << endl;
}