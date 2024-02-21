#include <iostream>
using namespace std;

int getLenght(char a[]) {
  int res = 0;
  while (a[res] != '\0')
    res++;
  return res;
}

char *reversingInmutble(char A[]) {
  int size = getLenght(A);
  char *ptr = new char[size];

  for (int i = 0; i < size; i++) {
    ptr[i] = A[size - i - 1];
  }
  return ptr;
}

void reversingMutble(char A[]) {
  int j = getLenght(A) - 1;

  for (int i = 0; i < j; i++, j--) {
    char temp = A[i];
    A[i] = A[j];
    A[j] = temp;
  }
}

int main() {
  char A[] = "hello";
  int size = getLenght(A);
  char *ptr = reversingInmutble(A);

  for (int i = 0; i < size; i++) {
    cout << ptr[i];
  }
  cout << endl;

  for (int i = 0; i < size; i++) {
    cout << A[i];
  }
  cout << endl;

  reversingMutble(A);
  for (int i = 0; i < size; i++) {
    cout << A[i];
  }
  cout << endl;
}