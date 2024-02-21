#include <iostream>
using namespace std;

struct Node {
  int elem;
  Node *next;
  Node(int elem) { this->elem = elem; }
  Node(int elem, Node *node) {
    this->elem = elem;
    this->next = node;
  }
  bool isLast() {
    return (this->next == NULL || this->next == 0 || !this->next);
  }
};
class LinkedList {
public:
  Node *firstPtr;

  LinkedList() { this->firstPtr = NULL; }

  LinkedList(int elem) {
    Node *node = new Node(elem);
    this->firstPtr = node;
  }
  ~LinkedList() { delete firstPtr; }

  bool isEmpty() { return (firstPtr == NULL || firstPtr == 0 || !firstPtr); }

  void Push(int newElem) {
    if (this->isEmpty()) {
      this->firstPtr = new Node(newElem);
      return;
    }

    Node *current = this->firstPtr;
    Node *prev = NULL;

    while (current && current->elem < newElem) {
      prev = current;
      current = current->next;
    }

    prev->next = new Node(newElem, current);
  }

  void Display() {
    if (this->isEmpty()) {
      printf("List is empty");
      return;
    }

    int index = 0;
    Node *current = this->firstPtr;

    while (true) {
      printf("index: %d, element: %d\n", index, current->elem);
      index++;
      if (current->isLast())
        break;
      current = current->next;
    }
  }

  bool isSorted() {
    if (this->isEmpty()) {
      return true;
    }

    int value = this->firstPtr->elem;
    Node *current = this->firstPtr;

    while (true) {
      if (value > current->elem) {
        return false;
      }

      if (current->isLast())
        break;

      current = current->next;
    };
    return true;
  }
};

LinkedList *MergeSortedLists(LinkedList *list1, LinkedList *list2) {
  LinkedList *list3 = new LinkedList();

  if (list1->isEmpty() && list2->isEmpty())
    return list3;

  Node *ptr1 = list1->firstPtr;
  Node *ptr2 = list2->firstPtr;

  if (ptr1->elem < ptr2->elem) {
    list3->Push(ptr1->elem);
    ptr1 = ptr1->next;
  } else {
    list3->Push(ptr2->elem);
    ptr2 = ptr2->next;
  }

  Node *ptr3 = list3->firstPtr;

  while (ptr1 && ptr2) {
    if (ptr1->elem < ptr2->elem) {
      ptr3->next = new Node(ptr1->elem);
      ptr3 = ptr3->next;
      ptr1 = ptr1->next;
    } else {
      ptr3->next = new Node(ptr2->elem);
      ptr3 = ptr3->next;
      ptr2 = ptr2->next;
    }
  }

  while (ptr1) {
    ptr3->next = new Node(ptr1->elem);
    ptr3 = ptr3->next;
    ptr1 = ptr1->next;
  }

  while (ptr2) {
    ptr3->next = new Node(ptr2->elem);
    ptr3 = ptr3->next;
    ptr2 = ptr2->next;
  }

  return list3;
};

int main() {
  LinkedList *list = new LinkedList(10);
  list->Push(50);
  list->Push(11);
  list->Push(14);
  list->Push(11);
  list->Push(17);
  list->Push(51);
  list->Display();
  cout << "isSorted: " << list->isSorted() << endl;

  LinkedList *list2 = new LinkedList(38);
  list2->Push(40);
  list2->Push(41);
  list2->Push(43);
  list2->Display();

  LinkedList *list3 = MergeSortedLists(list, list2);
  list3->Display();
}