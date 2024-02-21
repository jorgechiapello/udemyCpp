#include <iostream>
using namespace std;

int areStringEqual(char array1[], char array2[]) {
  int i = 0;

  while (array1[i] != '\0' || array2[i] != '\0') {
    if (array1[i] != array2[i]) {
      return 0;
      break;
    }
    i++;
  }

  i++;
  if (array1[i] == '\0' && array2[i] == '\0')
    return 0;

  return 1;
}

int main() {
  char E1[] = "hello";
  char E2[] = "hello";
  printf("Are 'hello' and 'hello' equal? %d\n", areStringEqual(E1, E2));

  char E3[] = "Hello, how are you?";
  char E4[] = "Hello, how are you doing?";
  printf(
      "Are 'Hello, how are you?' and 'Hello, how are you doing?' equal? %d\n",
      areStringEqual(E3, E4));
}