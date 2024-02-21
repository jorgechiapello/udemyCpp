#include <iostream>
using namespace std;

template <class T> class Arithmetic {
private:
  T a;
  T b;

public:
  Arithmetic(T a, T b);
  T add();
  T sub();
};

// El uso de :: se llama automatic scope resolution
template <class T> Arithmetic<T>::Arithmetic(T a, T b) {
  this->a = a;
  this->b = b;
}
template <class T> T Arithmetic<T>::add() { return this->a + this->b; }
template <class T> T Arithmetic<T>::sub() { return this->a - this->b; }

int main() {
  Arithmetic<int> *ar1 = new Arithmetic<int>(10, 5);
  Arithmetic<double> ar2 = Arithmetic<double>(9.2, 8.4);

  cout << ar1->add() << endl;
  cout << ar1->sub() << endl;

  cout << ar2.add() << endl;
  cout << ar2.sub() << endl;
}