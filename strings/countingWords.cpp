#include <iostream>
using namespace std;

void printString(char array[]) {
  for (int i = 0; array[i] != '\0'; i++) {
    printf("%c", array[i]);
  }
}

int countingWords(char array[]) {
  bool flag = 0;
  int c = 0;
  for (int i = 0; array[i] != '\0'; i++) {
    if (array[i] != ' ') {
      flag = 1;
    } else {
      if (flag)
        c++;
      flag = 0;
    }
  }
  if (flag)
    c++;
  return c;
}

int main() {
  char C[] = "How are you ? ";
  printString(C);
  cout << endl;
  int w = countingWords(C);
  printf("Number of words: %d\n", w);
}