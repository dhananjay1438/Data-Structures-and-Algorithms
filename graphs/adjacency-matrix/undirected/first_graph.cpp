#include <algorithm>
#include <array>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

class Graph {
  std::array<std::array<int, 5>, 5> graph = {};
  std::array<bool, 5> b_visited = {false};

public:
  void show_graph();
  void connect(int, int);
  void dfs_iterative(int);
  void dfs_recursive(int);
  void bfs_iterative(int);
  void bfs_recursive(int);
};

void Graph::bfs_iterative(int x) {

  std::queue<int> queue;
  queue.push(x);

  while (!queue.empty()) {
    int vertex = queue.front();
    if (b_visited[vertex] == false) {
      b_visited[vertex] = true;
      std::cout << vertex << " ";
    }
    queue.pop();
    for (size_t i = 0; i < graph.size(); i++) {
      if (b_visited[i] == false && graph[vertex][i] == 1) {
        queue.push(i);
      }
    }
  }
}

void Graph::connect(int x, int y) {
  // Undirected graph
  assert(x <= static_cast<int>(graph.size()) &&
         y <= static_cast<int>(graph.size()));
  graph.at(x).at(y) = 1;
  graph.at(y).at(x) = 1;
}

void Graph::show_graph() {
  for (size_t i = 0; i < graph.size(); i++) {
    for (size_t j = 0; j < graph.size(); j++) {
      std::cout << std::setw(5) << graph.at(i).at(j);
    }
    std::cout << "\n";
  }
}

void Graph::dfs_recursive(int x) {

  b_visited[x] = true;
  std::cout << x << " ";

  for (size_t i = 0; i < graph.size(); i++) {
    if (b_visited[i] == false && graph[x][i] == 1) {
      dfs_recursive(i);
    }
  }
}
void Graph::dfs_iterative(int x) {
  assert(x <= static_cast<int>(graph.size()));

  std::stack<int> stack;
  std::vector<std::pair<int, int>> visited;

  std::vector<bool> b_visited(graph.size(), false);

  stack.push(x);

  while (!stack.empty()) {
    auto current = stack.top();
    stack.pop();
    if (b_visited.at(current) == false) {
      std::cout << current << " ";
      b_visited.at(current) = true;
    }

    for (size_t i = 0; i < graph.size(); i++) {
      if (graph.at(current).at(i) == 1 && b_visited.at(i) == false) {
        stack.push(i);
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
  g.show_graph();

  //  g.dfs_iterative(0);
  //  g.dfs_recursive(0);

  g.dfs_iterative(0);
  return 0;
}
