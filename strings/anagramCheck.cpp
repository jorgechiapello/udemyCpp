#include <iostream>
using namespace std;

int getLetterMask(char A[]) {
  int mem;
  for (int i = 0; A[i] != '\0'; i++) {
    if (A[i] > 96 && A[i] < 123) {
      int l = A[i] - 97;
      int mask = 1;
      mask = mask << l;
      // guardo en el registro de letras usadas
      mem = mem | mask;
    }
  }
  return mem;
}

int main() {
  char A[] = "name";
  char B[] = "name";

  int mA = getLetterMask(A);
  int mB = getLetterMask(B);

  printf("mA: %d\n", mA);
  printf("mB: %d\n", mB);

  
}