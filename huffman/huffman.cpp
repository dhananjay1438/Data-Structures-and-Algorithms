#include <iostream>
#include <map>
#include <vector>

class Node {
public:
  Node *left;
  int character;
  int frequency;
  Node *right;
  Node(int, int);
};
Node::Node(int character, int frequency)
    : left(nullptr), character(character), frequency(frequency),
      right(nullptr) {}
class Huffman {};

class MinHeap {
  inline int LEFT(int);
  inline int RIGHT(int);
  std::vector<Node *> elements;
  void min_heapify(unsigned);
  void heapify();

public:
  MinHeap();
  void insert(Node *);
};

void MinHeap::insert(Node *element) {
  elements.push_back(element);
  unsigned index = static_cast<unsigned>(elements.size() - 1);
  min_heapify(index);
}

// Pushing 1 null element so we can access heap from 1st index to make it easier
MinHeap::MinHeap() { elements.push_back(nullptr); }
int MinHeap::LEFT(int i) { return i * 2; }

int MinHeap::RIGHT(int i) { return i * 2 + 1; }

int main(void) {

  std::string input;
  std::map<char, int> map;
  MinHeap min_heap;

  std::cin >> input;

  for (auto &ch : input) {
    map[ch]++;
  }

  for (auto &item : map) {
    min_heap.insert(new Node(item.first, item.second));
  }

  return 0;
}
