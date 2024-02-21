#include <iostream>
using namespace std;

static int sizeH = 10;

int Hash(int value) { return value % sizeH; }

int Probe(int array[], int size, int value) {
  int i = 0;

  while (array[Hash(Hash(value) + i)] != 0) {
    i++;
    if (size == i) {
      return -1;
      break;
    }
  }

  return Hash(Hash(value) + i);
};

void Display(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\n", array[i]);
  }
}

int Insert(int array[], int size, int value) {
  int pos = Hash(value);

  if (array[pos] != 0) {
    pos = Probe(array, size, value);
    if (pos == -1) {
      return -1;
    }
  }

  array[pos] = value;

  return pos;
};

int Search(int array[], int size, int value) {
  int pos = Hash(value);

  int i = 0;
  while (array[Hash(Hash(value) + i)] != value) {
    i++;
    if (size == i) {
      return -1;
      break;
    }
  }

  return array[Hash(Hash(value) + i)];
}

int main() {
  int *A = new int[sizeH];

  for (int i = 0; i < sizeH; i++) {
    A[i] = 0;
  }

  Insert(A, sizeH, 10);
  Insert(A, sizeH, 77);
  Insert(A, sizeH, 67);
  Insert(A, sizeH, 88);
  Insert(A, sizeH, 19);
  Insert(A, sizeH, 11);
  Insert(A, sizeH, 12);
  Insert(A, sizeH, 83);
  Insert(A, sizeH, 22);
  Insert(A, sizeH, 227);
  Insert(A, sizeH, 46);

  Display(A, sizeH);
  cout << "value: " << Search(A, sizeH, 19) << endl;
  cout << "value: " << Search(A, sizeH, 300) << endl;
}