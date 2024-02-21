#include <iostream>
using namespace std;

static int swaps = 0;
static int comps = 0;

void Display(int *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
}

void swap(int &a, int &b) {
  int aux = a;
  a = b;
  b = aux;
  swaps++;
}
int *Merging(int *A, int low, int mid, int high) {
  // printf("low: %d, mid: %d, high: %d\n", low, mid, high);
  int size = high - low + 1;
  int *C = new int[size];

  int a = low;
  int b = mid + 1;
  int i = 0;

  while (a <= mid && b <= high) {
    comps++;
    swaps++;
    if (A[a] < A[b]) {
      C[i++] = A[a++];
    } else {
      C[i++] = A[b++];
    }
  }
  while (a <= mid) {
    C[i++] = A[a++];
    swaps++;
  }

  while (b <= high) {
    C[i++] = A[b++];
    swaps++;
  }

  for (int i = 0; i < size; i++) {
    A[i + low] = C[i];
    swaps++;
  }
  return A;
};

int *MergeSort(int *array, int size) {
  int compSize = 2;
  int mid = 0;
  int *C;
  int lastMid = mid;

  while (compSize <= size) {
    for (int i = 0; i < size; i += compSize) {

      int maxIdx = i + compSize - 1;
      if (maxIdx >= size - 1) {
        maxIdx = size - 1;
        lastMid = i - 1;
      };

      mid = (i + maxIdx) / 2;

      Merging(array, i, mid, maxIdx);
    }

    compSize = compSize * 2;
  };

  Merging(array, 0, lastMid, size - 1);
  return array;
};

int main() {
  int A[] = {47, 36, 86, 77, 84, 62, 44, 58, 54, 3, 25, 81};
  int sizeA = sizeof(A) / sizeof(int);

  MergeSort(A, sizeA);
  Display(A, sizeA);
  // No realmente swaps pero contamos cuantas veces tenemos que mover elementos
  cout << endl << "swaps: " << swaps << endl;
  cout << "comparaciones: " << comps << endl;

  swaps = comps = 0;
  int B[] = {76, 43, 22, 91,  58, 34, 19,  67,  11,  28, 56, 39, 4,  61, 25,
             50, 16, 72, 3,   68, 31, 89,  5,   41,  20, 77, 12, 55, 29, 60,
             9,  37, 23, 65,  18, 49, 88,  13,  47,  70, 2,  83, 38, 64, 15,
             71, 24, 52, 10,  79, 35, 84,  6,   53,  26, 63, 17, 44, 21, 75,
             14, 57, 30, 66,  8,  36, 82,  48,  80,  40, 97, 32, 59, 27, 74,
             7,  51, 42, 87,  92, 45, 78,  33,  85,  69, 94, 46, 81, 54, 95,
             62, 99, 73, 100, 90, 98, 102, 103, 121, 115};
  int sizeB = sizeof(B) / sizeof(int);

  MergeSort(B, sizeB);
  Display(B, sizeB);
  // No realmente swaps pero contamos cuantas veces tenemos que mover elementos
  cout << endl << "swaps: " << swaps << endl;
  cout << "comparaciones: " << comps << endl;
}