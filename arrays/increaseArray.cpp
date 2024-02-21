#include <iostream>
using namespace std;

int main() {

  // Once an array is defined, we can't change its size
  int *ptr1 = new int[5];
  ptr1[0] = 10;
  ptr1[1] = 1;
  ptr1[2] = 2;
  ptr1[3] = 3;
  ptr1[4] = 4;

  // we have to create a new array
  int *ptr2 = new int[10];

  // and copy over all the elements into it
  for (int i = 0; i < 5; i++) {
    ptr2[i] = ptr1[i];
  }
  cout << "Starting: \n ptr1: " << ptr1 << ", ptr2: " << ptr2 << endl;
  // then change the pointer to the new array
  // by freeing the original pointer
  free(ptr1);
  cout << "free(ptr1); \n ptr1: " << ptr1 << ", ptr2: " << ptr2 << endl;

  // copying the second pointer into the first one
  ptr1 = ptr2;
  cout << "ptr1 = ptr2;\n ptr1: " << ptr1 << ", ptr2: " << ptr2 << endl;

  // Giving NULL to the original pointer
  ptr1 = NULL;
  cout << "ptr1 = NULL;\nptr1: " << ptr1 << ", ptr2: " << ptr2 << endl;
}