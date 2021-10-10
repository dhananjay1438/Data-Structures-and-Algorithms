#include <array>
#include <iostream>
#include <queue>

#define SIZE 10
class Graph {
private:
  std::array<std::array<int, SIZE>, SIZE> graph = {};

public:
  void connect(int, int);
  void bfs(int);
};
void Graph::bfs(int vertex) {
  std::queue<int> queue;
  std::array<bool, SIZE> visited;
  for (size_t i = 0; i < visited.size(); i++) {
    visited[i] = false;
  }
  queue.push(vertex);
  while (!queue.empty()) {
    vertex = queue.front();
    if (visited[vertex]) {
      queue.pop();
      continue;
    }

    std::cout << vertex << " ";
    visited[vertex] = true;
    queue.pop();
    for (int i = 0; i < SIZE; i++) {
      if (graph[vertex][i] == 1 && !visited[i]) {
        queue.push(i);
      }
    }
  }
}

void Graph::connect(int i, int j) {
  if (i >= SIZE || j >= SIZE) {
    std::cout << "Graph is smaller than you think!\n";
  } else if (graph[i][j] == 0) {
    graph[i][j] = 1;
    graph[j][i] = 1;
  } else {
    std::cout << "There's an edge already there!\n";
  }
}

int main(void) {
  Graph g;
  g.connect(4, 5);
  g.connect(4, 7);
  g.connect(8, 5);
  g.connect(9, 0);

  g.bfs(11);
  return 0;
}
