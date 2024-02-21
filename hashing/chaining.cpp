#include <iostream>
using namespace std;

static int sizeH = 10;

struct Node {
  int value;
  Node *next;
  Node() {}
  Node(int value) {
    this->value = value;
    next = NULL;
  }
  ~Node() { delete next; }
};

struct HashTable {
public:
  int size;
  Node **HT;
  HashTable(int size) {
    this->size = size;
    this->HT = new Node *[this->size];
  }
};

int Hash(int value) { return value % sizeH; }

int Insert(HashTable *hashTable, int value) {
  int pos = Hash(value);
  Node *newNode = new Node(value);

  if (!hashTable->HT[pos]) {
    hashTable->HT[pos] = newNode;
  } else {
    hashTable->HT[pos]->next = newNode;
  }

  return pos;
};

Node *Search(HashTable *hashTable, int value) {
  int pos = Hash(value);

  if (hashTable->HT[pos] == NULL) {
    return NULL;
  }

  Node *current = hashTable->HT[pos];

  while (current != NULL) {
    if (current->value == value) {
      return current;
      break;
    }
    current = current->next;
  }

  return NULL;
};

void Display(HashTable *hashTable, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d: %p\n", i, hashTable->HT[i]);
    Node *current = hashTable->HT[i];

    while (current) {
      printf("elem: %d\n", current->value);
      current = current->next;
    }
  }
}

int main() {
  HashTable *ht = new HashTable(sizeH);
  Insert(ht, 15);
  int pos = Insert(ht, 25);
  Display(ht, sizeH);
  cout << endl;
  Node *snode = Search(ht, 25);
  if (snode) {
    cout << "Found! " << snode->value << endl;
  }
}