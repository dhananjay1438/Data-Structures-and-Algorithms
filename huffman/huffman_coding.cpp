#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <variant>

struct Node {
  Node *_left;
  std::variant<char, int> freq;

  Node *_right;
  Node(int);
  Node(char);
};
Node::Node(int freq) : _left(nullptr), freq(freq), _right(nullptr){};
Node::Node(char freq) : _left(nullptr), freq(freq), _right(nullptr){};
class MaxHeap {
private:
  std::vector<int> heap;
  std::map<char, int> map;
  int index;
  int capcity;

  void _convert_string_to_map(std::string);
  int _parent();
  int _left();
  int _right();
  std::string get_string();

public:
  void insert(int);
  void heapify();
  void build();
  MaxHeap();
};

int MaxHeap::_parent() { return index / 2; }
int MaxHeap::_left() { return index * 2; }
int MaxHeap::_right() { return (index * 2) + 1; }

MaxHeap::MaxHeap() : index(0) {
  std::string str = get_string();
  _convert_string_to_map(str);
  capcity = map.size();
}

void MaxHeap::insert(int data) {
  heap.push_back(data);
  index++;
}

std::string MaxHeap::get_string() {
  std::string str;
  std::cin >> str;
  return str;
}

void MaxHeap::_convert_string_to_map(std::string str) {
  for (size_t i = 0; i < str.length(); i++) {
    map[str[i]] += 1;
  }
}

int main(void) { return 0; }
