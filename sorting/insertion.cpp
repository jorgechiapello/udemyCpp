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

void InsertionSort(int *array, int size) {
  int partition = 1;
  for (int i = 1; i < size; i++) {
    int aux = array[i];
    int prev = i - 1;
    int current = i;

    while (prev >= 0) {
      comps++;
      if (!(array[current] > array[prev])) {
        break;
      }
      swap(array[current], array[prev]);
      prev--;
      current--;
    }
    array[current] = aux;
  }
}

int main() {

  // Ordernar de mayor a menor

  // peor caso, ordenada pero al reves. 66 comparaciones (n(n-1))/2, O(n^2)
  int A[] = {3, 25, 36, 44, 47, 54, 58, 62, 77, 81, 84, 86};
  int size = sizeof(A) / sizeof(int);
  InsertionSort(A, size);
  Display(A, size);
  cout << endl << "swaps: " << swaps << endl;
  cout << "comparaciones: " << comps << endl;

  swaps = comps = 0;
  // Mejor caso, ya ordenada. 11 comparaciones, O(n)
  int A2[] = {86, 84, 81, 77, 62, 58, 54, 47, 44, 36, 25, 3};
  int size2 = sizeof(A2) / sizeof(int);
  InsertionSort(A2, size2);
  Display(A2, size2);
  cout << endl << "swaps: " << swaps << endl;
  cout << "comparaciones: " << comps << endl;

  swaps = comps = 0;
  int A3[] = {76, 43, 22, 91,  58, 34, 19,  67,  11,  28, 56, 39, 4,  61, 25,
              50, 16, 72, 3,   68, 31, 89,  5,   41,  20, 77, 12, 55, 29, 60,
              9,  37, 23, 65,  18, 49, 88,  13,  47,  70, 2,  83, 38, 64, 15,
              71, 24, 52, 10,  79, 35, 84,  6,   53,  26, 63, 17, 44, 21, 75,
              14, 57, 30, 66,  8,  36, 82,  48,  80,  40, 97, 32, 59, 27, 74,
              7,  51, 42, 87,  92, 45, 78,  33,  85,  69, 94, 46, 81, 54, 95,
              62, 99, 73, 100, 90, 98, 102, 103, 121, 115};
  int size3 = sizeof(A3) / sizeof(int);
  InsertionSort(A3, size3);
  Display(A3, size3);
  cout << endl << "swaps: " << swaps << endl;
  cout << "comparaciones: " << comps << endl;
}