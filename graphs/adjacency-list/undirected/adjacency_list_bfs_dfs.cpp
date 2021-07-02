#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#define SIZE 10

struct node {
  int vertex;
  struct node *next;
  node(int);
};

node::node(int data) : vertex(data) {}

class Graph {
  std::vector<struct node *> graph;
  std::array<bool, SIZE> visited;

public:
  Graph();
  void connect(int, int);
  void show(int);
  void dfs_recursive(int);
  void dfs_iterative(int);
  void bfs_iterative(int);
};

Graph::Graph() {
  for (int i = 0; i < SIZE; i++) {
    graph.push_back(NULL);
  }
  for (int i = 0; i < SIZE; i++) {
    visited.at(i) = false;
  }
}

void Graph::connect(int x, int y) {
  node *traverse = graph.at(x);
  if (traverse == NULL) {
    graph.at(x) = new node(y);
  } else {
    while (traverse->next != NULL) {
      traverse = traverse->next;
    }
    traverse->next = new node(y);
  }
  traverse = graph.at(y);

  if (traverse == NULL) {
    graph.at(y) = new node(x);
  }

  else {
    while (traverse->next != NULL) {
      traverse = traverse->next;
    }
    traverse->next = new node(x);
  }
}

void Graph::show(int x) {

  node *traverse = graph.at(x);

  std::cout << x << " ";
  while (traverse != NULL) {
    std::cout << traverse->vertex << " ";
    traverse = traverse->next;
  }
}

void Graph::bfs_iterative(int x) {
  std::stack<int> stack;
  std::vector<bool> visited(10, false);

  stack.push(x);

  while (!stack.empty()) {
    int current = stack.top();
    stack.pop();
    node *traverse = graph.at(current);
    if (!visited.at(current)) {
      std::cout << current << " ";
      visited.at(current) = true;
    }

    while (traverse != NULL) {
      if (!visited.at(traverse->vertex)) {
        std::cout << "" << traverse->vertex << " ";
        visited.at(traverse->vertex) = true;
        stack.push(traverse->vertex);
      }
      traverse = traverse->next;
    }
  }
}

void Graph::dfs_recursive(int vertex) {

  if (!visited.at(vertex)) {
    std::cout << vertex << " ";
    visited.at(vertex) = true;
  }
  node *traverse = graph.at(vertex);

  while (traverse != NULL && visited.at(traverse->vertex)) {
    traverse = traverse->next;
  }
  if (traverse != NULL) {
    std::cout << traverse->vertex << " ";
    visited.at(traverse->vertex) = true;
    dfs_recursive(traverse->vertex);
  }
}

void Graph::dfs_iterative(int x) {

  std::stack<int> stack;
  std::vector<bool> visited(10, false);

  stack.push(x);

  while (!stack.empty()) {
    int current = stack.top();
    stack.pop();

    if (!visited.at(current)) {
      std::cout << current << " ";
      visited.at(current) = true;
    }
    node *traverse = graph.at(current);
    while (traverse != NULL) {
      if (!visited.at(traverse->vertex)) {
        std::cout << traverse->vertex << " ";
        visited.at(traverse->vertex) = true;
        dfs_iterative(traverse->vertex);
        traverse = traverse->next;
      }
    }
  }
}

int main(void) {
  Graph g;
  g.connect(0, 1);
  g.connect(0, 4);
  g.connect(1, 2);
  g.connect(1, 3);
  g.connect(1, 4);
  g.connect(2, 3);
  g.connect(3, 4);

  ///  g.show(0);
  ///  std::cout << "\n";
  ///  g.show(1);
  ///  std::cout << "\n";
  ///  g.show(2);
  ///  std::cout << "\n";
  ///  g.show(3);
  ///  std::cout << "\n";
  ///  g.show(4);
  ///  std::cout << "\n";

  g.show(0);
  std::cout << "\n";
  g.show(1);
  std::cout << "\n";
  g.show(2);
  std::cout << "\n";
  g.show(3);
  std::cout << "\n";
  g.show(4);
  std::cout << "\n";
  g.dfs_recursive(3);

  return 0;
}
