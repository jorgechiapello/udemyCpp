#include <iostream>
using namespace std;

// Only works for lower case letters
int main() {
  char A[] = "hello, how are you?zz";
  int mem = 0;
  int dup = 0;

  for (int i = 0; A[i] != '\0'; i++) {
    if (A[i] > 96 && A[i] < 123) {
      int l = A[i] - 97;
      int mask = 1;
      mask = mask << l;

      int isDup = mem & mask;
      if (isDup > 0) {
        // if duplicate, add to storage of duplicates
        dup = dup | mask;
      }

      // guardo en el registro de letras usadas
      mem = mem | mask;
    }
  }

  // print in a different instance to avoid printing duplicate
  // letters more than once
  for (int i = 0; i < 26; i++) {
    int mask = 1;
    mask = mask << i;
    int aux = dup & mask;

    if (aux > 0) {
      printf("char: %c\n", i + 97);
    }
  }
}