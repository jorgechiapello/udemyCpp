#include <iostream>
using namespace std;

struct Node {
  int elem;
  Node *next;
  Node(int elem);
};

Node::Node(int elem) {
  this->elem = elem;
  next = NULL;
}

class LinkedQueue {
private:
  Node *front;
  Node *rear;

public:
  LinkedQueue();
  ~LinkedQueue();
  bool isEmpty();
  void Enqueue(int elem);
  int Dequeue();
  void Display();
};

LinkedQueue::LinkedQueue() { front = rear = NULL; }
LinkedQueue::~LinkedQueue() {
  delete (front);
  delete (rear);
}
bool LinkedQueue::isEmpty() { return front == NULL && rear == NULL; }
void LinkedQueue::Display() {
  if (!isEmpty()) {
    Node *current = front;
    while (current) {
      printf("Elem: %d\n", current->elem);
      current = current->next;
    }
  } else {
    printf("Queue is empty\n");
  }
}
void LinkedQueue::Enqueue(int elem) {
  Node *newNode = new Node(elem);

  if (!front)
    front = newNode;

  if (!rear) {
    rear = newNode;
  } else {
    rear->next = newNode;
    rear = newNode;
  }
}

int LinkedQueue::Dequeue() {
  if (isEmpty()) {
    printf("Queue is empty");
    return -1;
  }
  Node *targetNode = front;
  front = targetNode->next;
  int x = targetNode->elem;
  delete (targetNode);
  return x;
};

int main() {
  LinkedQueue *queue = new LinkedQueue();
  queue->Display();
  queue->Enqueue(10);
  queue->Enqueue(12);
  queue->Display();
  cout << endl;
  queue->Dequeue();
  queue->Display();
}