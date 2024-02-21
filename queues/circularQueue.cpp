#include <iostream>
using namespace std;

class Queue {
private:
  int size;
  int front;
  int rear;
  int *elems;

public:
  Queue(int size);
  ~Queue();
  bool isEmpty();
  bool isFull();
  void Enqueue(int elem);
  int Dequeue();
  void Display();
  void resetPointers();
};

Queue::Queue(int size) {
  this->size = size + 1;
  rear = front = 0;
  elems = new int[size];
}

Queue::~Queue() { delete[] elems; }
bool Queue::isEmpty() { return rear == front; }
bool Queue::isFull() {
  // cout << "rear: " << rear << ", front: " << front << endl;
  // cout << "(rear + 1) % size: " << (rear + 1) % size << endl;
  if ((rear + 1) % size == front) {
    return true;
  }
  return false;
}

void Queue::Enqueue(int elem) {
  if (isFull()) {
    printf("Queue is full\n");
  } else {
    rear = (rear + 1) % size;
    elems[rear] = elem;
  }
};

int Queue::Dequeue() {
  int x = -1;
  if (isEmpty()) {
    printf("Queue is empty\n");
  } else {
    front = (front + 1) % size;
    x = elems[front];
  }
  if (isEmpty())
    resetPointers();
  return x;
};

void Queue::Display() {
  if (isEmpty()) {
    printf("Is Empty\n");
    return;
  }

  int i = front + 1;
  do {
    cout << elems[i];
    if (i != rear) {
      cout << " <- ";
    }
    i = (i + 1) % size;
  } while (i != (rear + 1) % size);
  cout << endl;
}

void Queue::resetPointers() { front = rear = -1; }

int main() {
  Queue *queue = new Queue(3);
  printf("isEmpty: %d\n", queue->isEmpty());
  printf("isFull: %d\n", queue->isFull());
  queue->Display();
  cout << endl;

  queue->Enqueue(10);
  queue->Enqueue(12);
  queue->Enqueue(14);
  queue->Display();
  printf("isFull: %d\n", queue->isFull());
  cout << endl;

  queue->Dequeue();
  queue->Enqueue(20);
  queue->Display();
  printf("isFull: %d\n", queue->isFull());
  cout << endl;

  cout << "Dequeue" << endl;
  queue->Dequeue();
  queue->Display();
  printf("isFull: %d\n", queue->isFull());
  cout << endl;
}