#include <iostream>
using namespace std;

struct Rectangle {
  int length;
  int breadth;
  int color;
};

// crea un nuevo rectangulo
int areaByValue(struct Rectangle r) {
  // size of object
  cout << "size of r: " << sizeof(r) << endl;
  int res = r.length * r.breadth;
  // changes in object doesn't affect original rectangle
  r.breadth = 30000;
  cout << "new breadth for r: " << r.breadth << endl;
  return res;
}

// usa el pointer del rectangulo
int areaByReference(struct Rectangle &r) {
  // afecta al original
  r.breadth = 1000;
  return r.breadth * r.length;
}

int main() {

  Rectangle *rectangle = new Rectangle;
  rectangle->breadth = 10;
  rectangle->length = 10;

  cout << "areaByValue: " << endl;
  int res = areaByValue(*rectangle);
  cout << "area: " << res << endl;

  // Unchanged
  cout << "rectangle->breadth: " << rectangle->breadth << endl;

  cout << "areaByReference: " << areaByReference(*rectangle) << endl;
}