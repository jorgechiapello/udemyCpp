#include <iostream>
using namespace std;

struct Card {
  int face;
  const char *color;
  const char *club;
};

int main() {
  Card card = {10, "black", "diamond"};
  Card *p = &card;

  // In C
  cout << "Using '->'" << p->face << endl;
  cout << p->color << endl;
  cout << p->club << endl;

  cout << "Dereferencing '(*p).'" << (*p).face << endl;
  cout << (*p).color << endl;
  cout << (*p).club << endl;

  // also in C
  Card *mallocPointer;
  mallocPointer = (struct Card *)malloc(sizeof(Card));
  (*mallocPointer).face = 12;

  cout << "malloc: " << (*mallocPointer).face << endl;

  // in C++
  Card *pointerInCpp;
  pointerInCpp = new Card;
  pointerInCpp->club = "spades";
  cout << "Pointer in C++: " << pointerInCpp->club << endl;
}