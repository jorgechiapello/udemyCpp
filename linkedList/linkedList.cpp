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
  ~LinkedList() {
    Node *p = this->firstPtr;
    while (this->firstPtr) {
      this->firstPtr = this->firstPtr->next;
      delete p;
      p = this->firstPtr;
    }
  }

  bool isEmpty() { return (firstPtr == NULL || firstPtr == 0 || !firstPtr); }

  void Push(int newElem) {
    Node *inserted = new Node(newElem);

    if (this->isEmpty()) {
      this->firstPtr = inserted;
      return;
    }

    Node *last = this->firstPtr;

    while (!last->isLast()) {
      last = last->next;
    }
    last->next = inserted;
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

  int Count() {
    int count = 0;

    Node *current = this->firstPtr;

    while (true) {
      count++;
      if (current->isLast())
        break;
      current = current->next;
    }
    return count;
  }

  int Sum() {
    int sum = 0;

    Node *current = this->firstPtr;

    while (true) {
      sum += current->elem;
      if (current->isLast())
        break;
      current = current->next;
    }
    return sum;
  }

  int Max() {
    if (this->firstPtr == NULL || this->firstPtr == 0) {
      return -1;
    }

    int max = this->firstPtr->elem;

    Node *current = this->firstPtr;

    while (true) {
      if (max < current->elem) {
        max = current->elem;
      }
      if (current->isLast())
        break;
      current = current->next;
    }
    return max;
  }

  int Min() {
    if (this->firstPtr == NULL || this->firstPtr == 0) {
      return -1;
    }

    int min = this->firstPtr->elem;

    Node *current = this->firstPtr;

    while (true) {
      if (min > current->elem) {
        min = current->elem;
      }
      if (current->isLast())
        break;
      current = current->next;
    }
    return min;
  }

  Node *Search(int searched) {
    int index = 0;
    if (this->firstPtr == NULL || this->firstPtr == 0) {
      return NULL;
    }

    Node *current = this->firstPtr;

    while (true) {
      if (current->elem == searched) {
        return current;
      }
      index++;
      if (current->isLast())
        break;
      current = current->next;
    }

    return NULL;
  }

  void Insert(int elem, int index) {
    Node *newNode = new Node(elem);

    if (index == 0) {
      newNode->next = this->firstPtr;
      this->firstPtr = newNode;
      return;
    }
    Node *targetNode = this->firstPtr;

    for (int i = 0; i < index - 1; i++) {
      if (!targetNode->next) {
        break;
      }
      targetNode = targetNode->next;
    }
    newNode->next = targetNode->next;
    targetNode->next = newNode;
  }

  void Delete(int index) {
    if (this->isEmpty())
      return;

    if (index == 0) {
      if (this->firstPtr != NULL && this->firstPtr != 0) {
        Node *ptr = this->firstPtr;
        this->firstPtr = this->firstPtr->next;
        delete ptr;
      }
      return;
    }

    Node *targetNode = this->firstPtr->next;
    Node *tailNode = this->firstPtr;

    for (int i = 0; i < index - 1; i++) {
      if (targetNode->isLast()) {
        break;
      }
      tailNode = tailNode->next;
      targetNode = targetNode->next;
    }
    tailNode->next = targetNode->next;
    delete targetNode;
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

  void Reverse() {
    if (this->isEmpty())
      return;
    Node *current = this->firstPtr;
    Node *newNext = NULL;
    Node *prev = NULL;

    while (current != NULL) {
      newNext = current->next;
      current->next = prev;
      prev = current;
      current = newNext;
    }

    this->firstPtr = prev;
  }

  void Concatenate(LinkedList *list2) {
    Node *current = list2->firstPtr;

    while (current) {
      this->Push(current->elem);
      current = current->next;
    }
  }
};

int main() {
  LinkedList *list = new LinkedList(12);
  list->Insert(20, 1);
  list->Display();
  cout << endl;

  list->Push(3);
  list->Push(40);
  list->Push(5);
  list->Push(6);

  list->Display();
  cout << endl << "Count: " << list->Count() << endl;
  cout << "Sum: " << list->Sum() << endl;
  cout << "Max: " << list->Max() << endl;
  cout << "Min: " << list->Min() << endl;
  cout << "Search(5), index: " << list->Search(5)->elem << endl;
  Node *s2 = list->Search(11);

  if (!s2) {
    printf("Search(11), index: NULL\n");
  } else {
    printf("Search(11), index: %d\n", s2->elem);
  }
  cout << endl;
  list->Insert(18, 0);
  list->Insert(19, 4);
  list->Insert(21, 11);
  list->Display();
  cout << endl;
  list->Delete(4);
  list->Display();
  cout << "isSorted: " << list->isSorted() << endl;

  LinkedList *list2 = new LinkedList(1);
  list2->Push(2);
  list2->Push(3);
  list2->Display();
  cout << "isSorted 2: " << list2->isSorted() << endl;
  list2->Reverse();
  list2->Display();
  cout << endl << "Concatenated: " << endl;
  list->Concatenate(list2);
  list->Display();
  list2->Delete(1);
  cout << endl << "Concatenated should remaing the same: " << endl;
  list->Display();
  delete list;
}