#include <iostream>
using namespace std;

class Element {
public:
  int i;
  int j;
  int number;
  Element(int i, int j, int number) {
    this->i = i;
    this->j = j;
    this->number = number;
  }
};

class CoordinateList {
public:
  int rows;
  int columns;
  int size;
  int length;
  Element **elements;

  CoordinateList(int rows, int columns, int size) {
    this->rows = rows;
    this->columns = columns;
    this->size = size;
    this->elements = new Element *[size];
    this->length = 0;
  }

  ~CoordinateList() {
    for (int i = 0; i < this->length; i++) {
      // Free the memory allocated for each Element
      delete this->elements[i];
    }
    // Free the array of Element pointers
    delete[] this->elements;
  }

  void Set(int i, int j, int number) {
    this->elements[this->length] = new Element(i, j, number);
    this->length++;
  }

  Element *Get(int index) { return this->elements[index]; }

  void Display() {
    int k = 0;
    for (int i = 0; i < this->rows; i++) {
      for (int j = 0; j < this->columns; j++) {
        if (k < this->length && this->elements[k]->i == i &&
            this->elements[k]->j == j) {
          if (this->elements[k]->number < 10) {
            printf(" %d ", this->elements[k]->number);
          } else {
            printf("%d ", this->elements[k]->number);
          }
          k++;
        } else {
          printf(" 0 ");
        }
      }
      cout << endl;
    }
  }

  void DisplayInner() {
    for (int index = 0; index < this->length; index++) {
      Element *e = this->elements[index];
      printf("i: %d, j: %d, number: %d\n", e->i, e->j, e->number);
    }
  };

  void DisplayMetada() {
    printf("rows: %d, columns: %d, length: %d\n", this->rows, this->columns,
           this->length);
  }

  CoordinateList operator+(CoordinateList &m);
};

CoordinateList CoordinateList::operator+(CoordinateList &mat2) {
  if (columns != mat2.columns) {
    return CoordinateList(0, 0, 0);
  }

  CoordinateList *newCoord =
      new CoordinateList(this->rows, this->columns, this->size + mat2.size);

  int m1I = 0;
  int m2I = 0;

  while (m1I < length && m2I < mat2.length) {
    if (this->Get(m1I)->i < mat2.Get(m2I)->i) {
      newCoord->Set(this->Get(m1I)->i, this->Get(m1I)->j,
                    this->Get(m1I)->number);
      m1I++;
    } else if (this->Get(m1I)->i > mat2.Get(m2I)->i) {
      newCoord->Set(mat2.Get(m2I)->i, mat2.Get(m2I)->j, mat2.Get(m2I)->number);
      m2I++;
    } else {
      if (this->Get(m1I)->j < mat2.Get(m2I)->j) {
        newCoord->Set(this->Get(m1I)->i, this->Get(m1I)->j,
                      this->Get(m1I)->number);
        m1I++;
      } else if (this->Get(m1I)->j > mat2.Get(m2I)->j) {
        newCoord->Set(mat2.Get(m2I)->i, mat2.Get(m2I)->j,
                      mat2.Get(m2I)->number);
        m2I++;
      } else {
        newCoord->Set(this->Get(m1I)->i, this->Get(m1I)->j,
                      this->Get(m1I)->number + mat2.Get(m2I)->number);
        m1I++;
        m2I++;
      }
    }
  }

  for (; m1I < this->length; m1I++) {
    newCoord->Set(this->Get(m1I)->i, this->Get(m1I)->j, this->Get(m1I)->number);
  }

  for (; m2I < mat2.length; m2I++) {
    newCoord->Set(mat2.Get(m2I)->i, mat2.Get(m2I)->j, mat2.Get(m2I)->number);
  }

  return *newCoord;
}

int main() {
  int size = 6;
  CoordinateList *coord = new CoordinateList(5, 7, size);
  coord->Set(1, 1, 1);
  coord->Set(2, 3, 2);
  coord->Set(3, 2, 3);
  coord->Set(3, 4, 4);
  coord->Set(5, 6, 5);
  coord->Set(5, 7, 6);

  coord->Display();
  cout << endl;
  coord->DisplayInner();
  cout << endl;

  CoordinateList *coord2 = new CoordinateList(5, 7, size);
  coord2->Set(1, 2, 1);
  coord2->Set(2, 3, 2);
  coord2->Set(3, 2, 3);
  coord2->Set(3, 4, 4);
  coord2->Set(5, 6, 5);
  coord2->Set(6, 7, 6);

  coord2->Display();
  cout << endl;
  coord2->DisplayInner();
  cout << endl;

  CoordinateList coord3 = *coord + *coord2;
  coord3.Display();
  cout << endl;
  coord3.DisplayInner();
  coord3.DisplayMetada();
}