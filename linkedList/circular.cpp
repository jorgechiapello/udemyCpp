#include <iostream>
using namespace std;

struct Node {
  int elem;
  Node *next;
  Node(int elem) {
    this->elem = elem;
    this->next = this;
  }
  Node(int elem, Node *nextNode) {
    this->elem = elem;
    this->next = nextNode;
  }
};

class CircularLL {
public:
  Node *head;

  CircularLL() { this->head = NULL; }

  CircularLL(int elem) {
    Node *node = new Node(elem);
    this->head = node;
  }
  ~CircularLL() { delete head; }

  bool isEmpty() { return (head == NULL || head == 0 || !head); }

  void Display() {
    if (this->isEmpty()) {
      printf("List is empty");
      return;
    }

    int index = 0;
    Node *current = this->head;
    int started = 0;

    while (current != this->head || !started) {
      started = 1;
      printf("index: %d, element: %d\n", index, current->elem);
      index++;
      current = current->next;
    }
  }

  void Push(int elem) {
    if (this->isEmpty()) {
      Node *newNode = new Node(elem);
      this->head = newNode;
      newNode->next = newNode;
    }

    Node *last = this->head;

    while (last->next != this->head) {
      last = last->next;
    }
    Node *newNode = new Node(elem, this->head);
    last->next = newNode;
  }

  void Insert(int elem, int index) {
    if (this->isEmpty()) {
      this->Push(elem);
    }

    if (index == 0) {
      Node *newNode = new Node(elem, this->head);
      Node *last = this->head;

      while (last->next != this->head) {
        last = last->next;
      }
      last->next = newNode;
      return;
    }

    Node *current = this->head;
    for (int i = 0; i < index - 1; i++) {
      if (current->next == this->head) {
        break;
      }
      current = current->next;
    }
    Node *newNode = new Node(elem, current->next);
    current->next = newNode;
  }

  void Delete(int index) {
    if (this->isEmpty())
      return;

    if (index == 0) {
      if (this->head != NULL && this->head != 0) {
        Node *ptr = this->head;
        this->head = this->head->next;
        delete ptr;
      }
      return;
    }

    Node *targetNode = this->head->next;
    Node *tailNode = this->head;

    for (int i = 0; i < index - 1; i++) {
      if (!tailNode->next)
        break;
      tailNode = tailNode->next;
      targetNode = targetNode->next;
    }
    tailNode->next = targetNode->next;
    delete targetNode;
  }
};

int main() {
  CircularLL *list = new CircularLL();
  list->Push(15);
  list->Push(20);
  list->Push(18);
  list->Insert(10, 1);
  list->Insert(19, 2);

  list->Display();
  list->Insert(30, 200);
  list->Delete(2);
  cout << endl;
  list->Display();
}