#include <iostream>
using namespace std;

struct NodeGraph {
  int elem;
  int *edges;
  int sizeEdges;
  NodeGraph(int elem, int edges[], int sizeEdges) {
    this->edges = edges;
    this->sizeEdges = sizeEdges;
    this->elem = elem;
  }
};

int main() {
  // Nodo 1 => 2,3,4
  // 2 => 1,3
  // 3 => 1,2,3,4
  // 4 => 1,3,5
  // 5 => 3,4
  int vertices = 5;
  int edges = 7;

  int node1Edges[3] = {2, 3, 4};
  NodeGraph *node1 = new NodeGraph(1, node1Edges, 3);

  int node2Edges[2] = {1, 2};
  NodeGraph *node2 = new NodeGraph(1, node2Edges, 2);

  int node3Edges[4] = {1, 2, 4, 5};
  NodeGraph *node3 = new NodeGraph(1, node3Edges, 4);

  int node4Edges[3] = {1, 3, 5};
  NodeGraph *node4 = new NodeGraph(1, node4Edges, 3);

  int node5Edges[2] = {3, 4};
  NodeGraph *node5 = new NodeGraph(1, node5Edges, 2);

  NodeGraph **graph = new NodeGraph *[5];
  graph[0] = node1;
  graph[1] = node2;
  graph[2] = node3;
  graph[3] = node4;
  graph[4] = node5;

  int size = 5 + (2 * edges) + 2;
  int compact[size];

  for (int i = 0; i < size; i++) {
    compact[i] = 0;
  }

  int edgesPointer = 1 + vertices + 1;
  compact[edgesPointer - 1] = size - 1;

  for (int i = 0; i < vertices; i++) {
    compact[i + 1] = edgesPointer;
    for (int j = 0; j < graph[i]->sizeEdges; j++) {
      compact[edgesPointer++] = graph[i]->edges[j];
    }
  }

  for (const int x : compact) {
    printf("%d ", x);
  }
}