#include <iostream>
using namespace std;

int isLowerCase(char letter) {
  if (96 < letter && letter < 123) {
    return true;
  }
  return false;
}

int isUpperCase(char letter) {
  if (64 < letter && letter < 89) {
    return true;
  }
  return false;
}

int isVowel(char letter) {
  if (64 < letter && letter < 89) {
    letter = letter + 32;
  }

  if (letter == 97 || letter == 101 || letter == 105 || letter == 111 ||
      letter == 117) {
    return 1;
  }
  return 0;
}

void printString(char array[]) {
  for (int i = 0; array[i] != '\0'; i++) {
    printf("%c", array[i]);
  }
}

int getLentgh(char array[]) {
  int l = 0;
  while (array[l] != '\0') {
    l++;
  }
  return l;
}

char *allUpperCase(char array[]) {
  for (int i = 0; array[i] != '\0'; i++) {
    // Tiene que fijarse en el ASCII code para ver si es
    // minuscula: "a" es 97 y "z" es 122
    if (isLowerCase(array[i])) {
      array[i] = array[i] - 32;
    }
  }
  return array;
}

char *changeLetterCase(char array[]) {
  for (int i = 0; array[i] != '\0'; i++) {
    // Tiene que fijarse en el ASCII code para ver si es
    // minuscula: "a" es 97 y "z" es 122
    if (islower(array[i])) {
      array[i] = array[i] - 32;
    }
    // Tiene que fijarse en el ASCII code para ver si es
    // minuscula: "A" es 65 y "Z" es 90
    else if (isUpperCase(array[i])) {
      array[i] = array[i] + 32;
    }
  }
  return array;
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
  char A[] = "hola";
  printf("%c: %d, ", 'o', 'o');
  printf("%c: %d\n", 'a', 'a');

  printString(A);
  cout << endl;

  printf("length: %d\n", getLentgh(A));

  printf("All upper case: ");
  allUpperCase(A);
  printString(A);
  cout << endl;

  char B[] = "ChApA";
  printString(B);
  cout << endl;
  printf("Change case: ");
  changeLetterCase(B);
  printString(B);
  cout << endl;

  char C[] = "How are you ? ";
  printString(C);
  cout << endl;
  int w = countingWords(C);
  printf("Number of words: %d\n", w);

  printf("Is 'a' vowel? %d\n", isVowel('a'));
  printf("Is 'B' vowel? %d\n", isVowel('B'));

  printf("Is 'B' upper case? %d\n", isUpperCase('B'));
  printf("Is 'b' upper case? %d\n", isUpperCase('b'));
}