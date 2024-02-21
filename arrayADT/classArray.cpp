#include <iostream>
using namespace std;

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

class Array {
private:
  int *A;
  int size;
  int length;

public:
  Array() {
    size = 10;
    length = 0;
    A = new int[10];
  }
  Array(int size) {
    size = size;
    length = 0;
    A = new int[size];
  }
  ~Array() { delete[] A; }

  void Display();
  void Append(int elem);
  void Insert(int index, int elem);
  int Delete(int index);
  int LinearSearch(int elem);
  int Get(int index);
  void Set(int index, int x);
  int Max();
  int Min();
  int Sum();
  float Average();
  void Reverse();
  void LeftShift();
  int IsSorted();
  void InsertSort(int elem);
  void Sort();
};

void Array::Display() {
  printf("Elements are: ");
  for (int i = 0; i < length; i++)
    printf("%d ", A[i]);

  printf("\n");
}

void Array::Append(int elem) {
  if (length < size) {
    A[length++] = elem;
  } else
    printf("Not possible to keep adding elements");
};

void Array::Insert(int index, int elem) {
  if (index >= 0 && index <= length) {
    for (int i = length; i > index; i--) {
      A[i] = A[i - 1];
      length++;
    }
    A[index] = elem;
  }
};

int Array::Delete(int index) {
  if (index >= 0 && index <= length) {
    int x = A[index];

    for (int i = index; i < length - 1; i++) {
      A[i] = A[i + 1];
    }

    length--;
    return x;
  }
  return 0;
};

int Array::LinearSearch(int elem) {

  for (int i = 0; i < length; i++) {
    if (A[i] == elem)
      return i;
  }
  return -1;
}

int Array::Get(int index) {
  if (index >= 0 && index < length)
    return A[index];

  return -1;
};

void Array::Set(int index, int x) {
  if (index >= 0 && index < length)
    A[index] = x;
};

int Array::Max() {
  int max = -1;

  for (int i = 0; i < length; i++) {
    if (A[i] > max) {
      max = A[i];
    }
  }
  return max;
};

int Array::Min() {

  if (length == 0)
    return -1;

  int min = A[0];

  for (int i = 1; i < length; i++) {
    if (A[i] < min) {
      min = A[i];
    }
  }
  return min;
};

int Array::Sum() {
  if (length == 0)
    return -1;

  int sum = A[0];

  for (int i = 1; i < length; i++) {
    sum += A[i];
  };

  return sum;
};

float Array::Average() {
  if (length == 0)
    return -1;

  float sum = A[0];

  for (int i = 1; i < length; i++) {
    sum += A[i];
  };

  return sum / length;
}

void Array::Reverse() {
  int i, j;
  int temp;

  for (i = 0, j = length - 1; i < j; i++, j--) {
    temp = A[j];
    A[j] = A[i];
    A[i] = temp;
  }
}

void Array::LeftShift() { Array::Delete(0); }

int Array::IsSorted() {
  if (length < 2) {
    return 1;
  }

  for (int i = 0; i < length - 2; i++) {
    if (A[i] >= A[i + 1])
      return -1;
  }

  return 1;
}

void Array::InsertSort(int elem) {
  if (length >= size)
    return;

  int i = length - 1;

  while (i >= 0 && elem < A[i]) {
    A[i + 1] = A[i];
    i--;
  }

  A[i + 1] = elem;
  length++;
}

void Array::Sort() {
  if (length < 2)
    return;

  int low = 0;

  int runs = 0;
  while (low < length - 1) {
    for (int i = low + 1; i < length - 1; i++) {
      runs++;
      if (A[low] > A[i]) {
        Display();
        swap(A[low], A[i]);
      }
    }
    low++;
  }
  printf("Runs: %d\n", runs);
};

int main() {
  Array array = Array();

  // En callstack
  array.Append(1);
  array.Append(2);
  array.Append(3);
  array.Append(4);
  array.Append(5);

  array.Display();

  array.Insert(4, 14);

  array.Display();

  printf("Deleted elem: %d\n", array.Delete(0));

  array.Display();

  int searchElem = 14;
  int sIndex = array.LinearSearch(searchElem);
  printf("Linear search of %d in position: %d\n", searchElem, sIndex);

  searchElem = 4;
  sIndex = array.LinearSearch(searchElem);
  printf("Linear search of %d in position: %d\n", searchElem, sIndex);

  printf("Min elem: %d\n", array.Min());
  printf("Max elem: %d\n", array.Max());
  printf("Sum of array: %d\n", array.Sum());
  printf("Average of array: %f\n", array.Average());

  array.Append(22);
  array.Append(33);
  array.Append(44);
  array.Append(55);

  array.Display();
  array.Reverse();
  array.Display();

  cout << "Left shift" << endl;
  array.LeftShift();
  array.Display();

  cout << "Elements are sorted? " << array.IsSorted() << endl;

  array.InsertSort(45);
  array.Display();

  cout << "Sort" << endl;
  array.Sort();
  array.Display();

  cout << "Sort 2" << endl;
  array.Sort();
  array.Display();
}