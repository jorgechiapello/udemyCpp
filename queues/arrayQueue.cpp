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
  this->size = size;
  rear = front = -1;
  elems = new int[size];
}

Queue::~Queue() { delete[] elems; }
bool Queue::isEmpty() { return rear == front; }
bool Queue::isFull() { return rear == size - 1; }

void Queue::Enqueue(int elem) {
  if (isFull()) {
    printf("Queue is full\n");
    return;
  }
  rear++;
  elems[rear] = elem;
};

int Queue::Dequeue() {
  int x = -1;
  if (isEmpty()) {
    printf("Queue is empty\n");
  } else {
    front++;
    x = elems[front];
  }
  if (isEmpty())
    resetPointers();
  return x;
};

void Queue::Display() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return;
  }
  for (int i = front + 1; i <= rear; i++) {
    printf("elem: %d, index: %d\n", elems[i], i);
  }
}

void Queue::resetPointers() { front = rear = -1; }

int main() {
  Queue *queue = new Queue(6);
  printf("isEmpty: %d\n", queue->isEmpty());
  printf("isFull: %d\n", queue->isFull());
  queue->Display();

  queue->Enqueue(10);
  queue->Enqueue(14);
  queue->Enqueue(17);
  queue->Enqueue(20);
  queue->Enqueue(22);
  queue->Enqueue(24);
  queue->Enqueue(27);
  queue->Display();
  cout << "After dequeue" << endl;
  queue->Dequeue();
  queue->Display();

  cout << "After full dequeue" << endl;
  queue->Dequeue();
  queue->Dequeue();
  queue->Dequeue();
  queue->Dequeue();
  queue->Dequeue();
  cout << "Enqueue after having a full queue (should queue with index 0)"
       << endl;
  queue->Enqueue(27);

  queue->Display();
}