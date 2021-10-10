#pragma once
#include <array>

#define SIZE 10
class Graph {
  std::array<std::array<int, SIZE>, SIZE> graph;
  Graph();
};
Graph::Graph() {
  for (size_t i = 0; i < SIZE; i++) {
    for (size_t j = 0; j < SIZE; j++) {
      graph[i][j] = -1;
    }
  }
}
