#include <iostream>
#include <vector>

struct node {
  int vertex;
  struct node *next;
  node(int);
};

node::node(int t_vertex) : vertex(t_vertex), next(NULL) {}

class Graph {

  std::vector<node *> vertex;
  std::vector<bool> visited;

public:
  void connect(int, int);
};
int main(void) { return 0; }
