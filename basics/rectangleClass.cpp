#include <iostream>
using namespace std;

class Rectangle {
private:
  int length;
  int breadth;

public:
  Rectangle(int l, int b) {
    length = l;
    breadth = b;
  }
  int area() { return breadth * length; }

  void changeLength(int l) { length = l; }
};

int main() {
  // Classes only work for C++
  Rectangle *ptr = new Rectangle(10, 4);

  cout << "area: " << ptr->area() << endl;
}