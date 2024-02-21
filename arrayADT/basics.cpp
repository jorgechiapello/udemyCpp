#include <iostream>
using namespace std;

struct Array {
  int A[20];
  int size;
  int length;
};

void Display(Array *array) {
  printf("Elements are: ");
  for (int i = 0; i < array->length; i++)
    printf("%d ", array->A[i]);

  printf("\n");
}

void Append(Array *array, int elem) {
  if (array->length < array->size) {
    array->A[array->length++] = elem;
  } else
    printf("Not possible to keep adding elements");
};

void Insert(Array *array, int index, int elem) {
  if (index >= 0 && index <= array->length) {
    for (int i = array->length; i > index; i--) {
      array->A[i] = array->A[i - 1];
      array->length++;
    }
    array->A[index] = elem;
  }
};

int Delete(Array *array, int index) {
  if (index >= 0 && index <= array->length) {
    int x = array->A[index];

    for (int i = index; i < array->length - 1; i++) {
      array->A[i] = array->A[i + 1];
    }

    array->length--;
    return x;
  }
  return 0;
};

int LinearSearch(Array *array, int elem) {

  for (int i = 0; i < array->length; i++) {
    if (array->A[i] == elem)
      return i;
  }
  return -1;
}

int Get(Array array, int index) {
  if (index >= 0 && index < array.length)
    return array.A[index];

  return -1;
};

void Set(Array *array, int index, int x) {
  if (index >= 0 && index < array->length)
    array->A[index] = x;
};

int Max(Array array) {
  int max = -1;

  for (int i = 0; i < array.length; i++) {
    if (array.A[i] > max) {
      max = array.A[i];
    }
  }
  return max;
};

int Min(Array array) {

  if (array.length == 0)
    return -1;

  int min = array.A[0];

  for (int i = 1; i < array.length; i++) {
    if (array.A[i] < min) {
      min = array.A[i];
    }
  }
  return min;
};

int Sum(Array array) {
  if (array.length == 0)
    return -1;

  int sum = array.A[0];

  for (int i = 1; i < array.length; i++) {
    sum += array.A[i];
  };

  return sum;
};

float Average(Array array) {
  if (array.length == 0)
    return -1;

  float sum = array.A[0];

  for (int i = 1; i < array.length; i++) {
    sum += array.A[i];
  };

  return sum / array.length;
}

void Reverse(Array *array) {
  int i, j;
  int temp;

  for (i = 0, j = array->length - 1; i < j; i++, j--) {
    temp = array->A[j];
    array->A[j] = array->A[i];
    array->A[i] = temp;
  }
}

void LeftShift(Array *array) { Delete(array, 0); }

int IsSorted(Array *array) {
  if (array->length < 2) {
    return 1;
  }

  for (int i = 0; i < array->length - 2; i++) {
    if (array->A[i] >= array->A[i + 1])
      return -1;
  }

  return 1;
}

void InsertSort(Array *array, int elem) {
  if (array->length >= array->size)
    return;

  int i = array->length - 1;

  while (i >= 0 && elem < array->A[i]) {
    array->A[i + 1] = array->A[i];
    i--;
  }

  array->A[i + 1] = elem;
  array->length++;
}

void Sort(Array *array) {
  if (array->length < 2)
    return;

  int low = 0;
  int count = 0;
  while (low < array->length - 1) {
    for (int i = low; i < array->length - 1; i++) {
      count++;
      if (array->A[low] > array->A[i]) {
        swap(array->A[low], array->A[i]);
      }
    }
    low++;
  }
  cout << "pasadas: " << count << "\n";
};

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

Array Merge(Array *array1, Array *array2) {

  Array *array3 = new Array;
  int i, j, k = 0;
  bool f = i < array1->length && j < array2->length;

  while (i < array1->length && j < array2->length) {
    if (array1->A[i] < array2->A[j]) {
      array3->A[k] = array1->A[i];
      i++;
    } else {
      array3->A[k] = array2->A[j];
      j++;
    }
    k++;
  }

  while (i < array1->length) {
    array3->A[k] = array1->A[i];
    i++;
    k++;
  }

  while (j < array2->length) {
    array3->A[k] = array2->A[j];
    j++;
    k++;
  }

  array3->length = array1->length + array2->length;
  array3->size = array1->size + array2->size;
  return *array3;
}
// Array Union() {}
// Array Diff() {}
// Array Inter() {}

int main() {
  struct Array array;
  array.size = 10;
  array.length = 0;

  Append(&array, 1);
  Append(&array, 2);
  Append(&array, 3);
  Append(&array, 4);
  Append(&array, 5);

  Display(&array);

  Insert(&array, 4, 14);

  Display(&array);

  printf("Deleted elem: %d\n", Delete(&array, 0));

  Display(&array);

  int searchElem = 14;
  int sIndex = LinearSearch(&array, searchElem);
  printf("Linear search of %d in position: %d\n", searchElem, sIndex);

  searchElem = 4;
  sIndex = LinearSearch(&array, searchElem);
  printf("Linear search of %d in position: %d\n", searchElem, sIndex);

  printf("Min elem: %d\n", Min(array));
  printf("Max elem: %d\n", Max(array));
  printf("Sum of array: %d\n", Sum(array));
  printf("Average of array: %f\n", Average(array));

  Append(&array, 22);
  Append(&array, 33);
  Append(&array, 44);
  Append(&array, 55);

  Display(&array);
  Reverse(&array);
  Display(&array);

  cout << "Left shift" << endl;
  LeftShift(&array);
  Display(&array);

  cout << "Elements are sorted? " << IsSorted(&array) << endl;

  InsertSort(&array, 45);
  Display(&array);

  cout << "Rearrange" << endl;
  Sort(&array);
  Display(&array);

  struct Array array2;
  array2.size = 10;
  array2.length = 0;

  Append(&array2, 78);
  Append(&array2, 79);
  Append(&array2, 13);
  Append(&array2, 92);
  Append(&array2, 51);

  Array array3 = Merge(&array, &array2);

  cout << "Array3" << endl;
  Display(&array3);
}