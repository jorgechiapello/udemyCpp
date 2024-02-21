#include <iostream>
using namespace std;

static int swaps = 0;

int getRightChildPos(int index) { return (index * 2) + 1; };
int getLeftChildPos(int index) { return index * 2; };

void swap(int &a, int &b) {
  // printf("swap: %d and %d\n", a, b);
  int temp = a;
  a = b;
  b = temp;
  swaps++;
}

class Heap {
private:
  int *A;
  int size;
  int lastPos;

public:
  Heap(int size);
  bool isFull();
  bool isEmpty();
  void Display();
  void Push(int elem);
  void Heapify();
  void Pop(int elem);
  void Insert(int elem);
  void Delete(int elem);
};

Heap::Heap(int size) {
  this->A = new int[size];
  this->size = size;
  lastPos = 0;
};

bool Heap::isFull() { return lastPos == size; };

bool Heap::isEmpty() { return lastPos == 0; };

void Heap::Display() {
  if (isEmpty()) {
    printf("Heap is empty\n");
    return;
  }
  for (int i = 1; i <= lastPos; i++) {
    printf("%d ", A[i - 1]);

    int leftChildPos = getLeftChildPos(i);
    int rightChildPos = getRightChildPos(i);

    if (leftChildPos <= lastPos) {
      printf("Left child: %d ", A[leftChildPos - 1]);
    }
    if (rightChildPos <= lastPos) {
      printf("Right child: %d", A[rightChildPos - 1]);
    }
    cout << endl;
  }
}

void Heap::Push(int elem) {
  if (isFull()) {
    printf("Heap is full");
    return;
  }
  A[lastPos] = elem;
  lastPos++;
}

void Heap::Pop(int elem) {
  int targetIndex = -1;

  for (int i = 0; i < lastPos; i++) {
    if (A[i] == elem) {
      targetIndex = i;
    }
  }
  if (targetIndex > -1) {
    A[targetIndex] = A[lastPos - 1];
    lastPos--;
  }
}

void Heap::Heapify() {
  for (int currentPos = lastPos / 2; currentPos > 0; currentPos--) {
    int parentPos = currentPos;
    while (parentPos <= lastPos / 2) {
      int leftChildPos = getLeftChildPos(parentPos);
      int rightChildPos = getRightChildPos(parentPos);

      int largestPos = parentPos;
      if (leftChildPos <= lastPos && A[leftChildPos - 1] > A[largestPos - 1]) {
        largestPos = leftChildPos;
      }
      if (rightChildPos <= lastPos &&
          A[rightChildPos - 1] > A[largestPos - 1]) {
        largestPos = rightChildPos;
      }

      if (largestPos != parentPos) {
        swap(A[parentPos - 1], A[largestPos - 1]);
        parentPos = largestPos;
      } else {
        break;
      }
    }
  }
}

void Heap::Insert(int elem) {
  A[lastPos] = elem;
  lastPos++;
  int parent = lastPos / 2;
  int target = lastPos;

  while (parent >= 1 && A[parent - 1] < A[target - 1]) {
    swap(A[parent - 1], A[target - 1]);
    target = parent;
    parent = target / 2;
  };
}

void Heap::Delete(int elem) {
  int targetIndex = -1;

  for (int i = 0; i < lastPos; i++) {
    if (A[i] == elem) {
      targetIndex = i;
    }
  }

  if (targetIndex > -1) {
    A[targetIndex] = A[lastPos - 1];
    lastPos--;
    int targetPos = targetIndex + 1;

    while (targetPos <= lastPos / 2) {
      if (A[targetPos - 1] > A[targetPos * 2] &&
          A[targetPos - 1] > A[targetPos * 2 - 1]) {
        break;
      }

      if (A[targetPos * 2 - 1] < A[targetPos * 2]) {
        swap(A[targetPos - 1], A[targetPos * 2]);
        targetPos = targetPos * 2;
      } else {
        swap(A[targetPos - 1], A[targetPos * 2 - 1]);
        targetPos = targetPos * 2 - 1;
      }
    }
  };
}

int main() {
  Heap *maxHeap = new Heap(32);

  maxHeap->Push(10);
  maxHeap->Push(12);
  maxHeap->Push(8);
  maxHeap->Push(9);
  maxHeap->Push(15);
  maxHeap->Push(11);
  maxHeap->Push(13);
  maxHeap->Push(17);
  maxHeap->Push(78);
  maxHeap->Push(65);
  maxHeap->Push(38);
  maxHeap->Push(34);
  maxHeap->Push(39);
  maxHeap->Push(40);
  maxHeap->Push(57);
  maxHeap->Push(89);
  maxHeap->Push(100);
  maxHeap->Push(101);
  maxHeap->Push(102);
  maxHeap->Push(103);
  maxHeap->Push(104);
  maxHeap->Push(1);
  maxHeap->Push(2);
  maxHeap->Push(3);
  maxHeap->Push(4);
  maxHeap->Push(5);

  int initialSwaps = swaps;
  cout << "Heapify\n";
  maxHeap->Heapify();

  cout << "Number of swaps with Heapify: " << (swaps - initialSwaps) << endl;

  cout << "Regular inserts\n";
  swaps = 0;
  initialSwaps = swaps;
  Heap *maxHeap2 = new Heap(32);
  maxHeap2->Insert(10);
  maxHeap2->Insert(12);
  maxHeap2->Insert(8);
  maxHeap2->Insert(9);
  maxHeap2->Insert(15);
  maxHeap2->Insert(11);
  maxHeap2->Insert(13);
  maxHeap2->Insert(17);
  maxHeap2->Insert(78);
  maxHeap2->Insert(65);
  maxHeap2->Insert(38);
  maxHeap2->Insert(34);
  maxHeap2->Insert(39);
  maxHeap2->Insert(40);
  maxHeap2->Insert(57);
  maxHeap2->Insert(89);
  maxHeap2->Insert(100);
  maxHeap2->Insert(101);
  maxHeap2->Insert(102);
  maxHeap2->Insert(103);
  maxHeap2->Insert(104);
  maxHeap2->Insert(1);
  maxHeap2->Insert(2);
  maxHeap2->Insert(3);
  maxHeap2->Insert(4);
  maxHeap2->Insert(5);

  cout << "Number of swaps with inserts: " << (swaps - initialSwaps) << endl;

  cout << "Remove node with Heapify" << endl;
  swaps = 0;
  initialSwaps = swaps;
  cout << "Pop 15" << endl;
  maxHeap->Pop(15);
  maxHeap->Display();

  cout << "Heapify\n";
  maxHeap->Heapify();
  maxHeap->Display();
  cout << "Number of swaps with Heapify: " << (swaps - initialSwaps) << endl;

  cout << "Remove node with regular delete" << endl;
  swaps = 0;
  initialSwaps = swaps;
  cout << "Delete(12)\n";
  maxHeap->Delete(12);
  maxHeap->Display();
  cout << "Number of swaps with regular delete: " << (swaps - initialSwaps)
       << endl;
}