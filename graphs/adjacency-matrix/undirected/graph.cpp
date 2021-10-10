#include <iostream>
#include <queue>
#include <stack>
#include <vector>

class Graph {
  std::vector<std::vector<int>> graph;
  const unsigned SIZE;

public:
  Graph(unsigned);
  void connect(unsigned, unsigned);
  void dfs(unsigned);
  void show_graph();
  void bfs(unsigned);
};
Graph::Graph(unsigned size) : SIZE(size) {
  for (unsigned i = 0; i < SIZE; i++) {
    std::vector<int> temp;
    for (unsigned j = 0; j < SIZE; j++) {
      temp.push_back(0);
    }
    graph.push_back(temp);
  }
}
void Graph::show_graph() {
  for (auto &vec : graph) {
    for (auto &item : vec) {
      std::cout << item << " ";
    }
    std::cout << "\n";
  }
}

void Graph::connect(unsigned i, unsigned j) {
  if (i < SIZE && j < SIZE) {
    graph[i][j] = 1;
    graph[j][i] = 1;
  }
}

void Graph::dfs(unsigned start) {
  std::stack<unsigned> stack;
  std::vector<bool> visited(SIZE, false);
  std::cout << "DFS: ";
  stack.push(start);
  while (!stack.empty()) {
    start = stack.top();
    stack.pop();
    if (!visited[start]) {
      visited[start] = true;
      std::cout << start << " ";
    }
    for (unsigned i = 0; i < SIZE; i++) {
      if (!visited[i] && graph[start][i] == 1) {
        stack.push(i);
      }
    }
  }
  std::cout << "\n";
}

void Graph::bfs(unsigned start) {
  std::queue<unsigned> queue;
  std::vector<bool> visited(SIZE, false);

  std::cout << "BFS: ";

  queue.push(start);
  while (!queue.empty()) {
    start = queue.front();
    queue.pop();

    if (!visited[start]) {
      visited[start] = true;
      std::cout << start << " ";
    }

    for (unsigned i = 0; i < SIZE; i++) {
      if (!visited[i] && graph[start][i] == 1) {
        queue.push(i);
      }
    }
  }
  std::cout << "\n";
}
int main(void) {
  Graph g(10);
  //  g.show_graph();
  g.connect(0, 1);
  g.connect(1, 9);
  g.connect(9, 7);
  g.connect(0, 5);
  g.connect(0, 8);
  // g.show_graph();
  g.dfs(0);
  g.bfs(0);
  return 0;
}
