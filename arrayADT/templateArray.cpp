#include <iostream>
using namespace std;

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

template <class T> class Array {
private:
  int *A;
  int size;
  int length;

public:
  Array() {
    size = 10;
    length = 0;
    A = new T[10];
  }
  Array(int size) {
    size = size;
    length = 0;
    A = new T[size];
  }
  ~Array() { delete[] A; }

  void Display();
  void Append(T elem);
  void Insert(int index, T elem);
  T Delete(int index);
  T LinearSearch(T elem);
  T Get(int index);
  void Set(int index, T elem);
};

template <class T> void Array<T>::Display() {
  printf("Elements are: ");
  for (int i = 0; i < length; i++)
    printf("%d ", A[i]);

  printf("\n");
}

template <class T> void Array<T>::Append(T elem) {
  if (length < size) {
    A[length++] = elem;
  } else
    printf("Not possible to keep adding elements");
};

template <class T> void Array<T>::Insert(int index, T elem) {
  if (index >= 0 && index <= length) {
    for (int i = length; i > index; i--) {
      A[i] = A[i - 1];
      length++;
    }
    A[index] = elem;
  }
};

template <class T> T Array<T>::Delete(int index) {
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

template <class T> T Array<T>::LinearSearch(T elem) {

  for (int i = 0; i < length; i++) {
    if (A[i] == elem)
      return i;
  }
  return -1;
}

template <class T> T Array<T>::Get(int index) {
  if (index >= 0 && index < length)
    return A[index];

  return -1;
};

template <class T> void Array<T>::Set(int index, T elem) {
  if (index >= 0 && index < length)
    A[index] = elem;
};

int main() {
  Array<int> array = Array<int>();

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

  array.Append(22);
  array.Append(33);
  array.Append(44);
  array.Append(55);

  printf("Get element %d: %d\n", 1, array.Get(1));

  array.Display();
  cout << "Set element 6 with 100" << endl;
  array.Set(5, 100);
  array.Display();
}