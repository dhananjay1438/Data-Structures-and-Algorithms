#include <array>
#include <iostream>
#include <string>

#define SIZE 256
typedef struct node {
  std::string key;
  int value;
  struct node *next;
  node(std::string, int);
} node;

node::node(std::string key, int value) {

  this->key = key;
  this->value = value;
  next = nullptr;
}
class Hashtable {

  std::array<node *, SIZE> arr;
  int hash(std::string str) { return static_cast<int>(str[0]); }

public:
  Hashtable() { std::fill_n(arr.begin(), SIZE, nullptr); }

  void insert(std::string str, int value) {
    int hash_index = hash(str);
    if (arr[hash_index] == nullptr) {
      arr[hash_index] = new node(str, value);
    } else {
      node *traverse = arr[hash_index];

      while (traverse->next != nullptr) {
        traverse = traverse->next;
      }
      traverse->next = new node(str, value);
    }
  }
  void diplay(std::string str) {

    int hash_index = hash(str);

    if (arr[hash_index] == nullptr) {
      std::cout << "Not found!\n";
    } else {
      node *traverse = arr[hash_index];
      while (traverse != NULL) {
        if (str.compare(traverse->key) == 0) {
          std::cout << traverse->value << "\n";
          break;
        }
        traverse = traverse->next;
      }
    }
  }
};
int main(void) {
  Hashtable h;
  h.insert("sai", 10);
  h.insert("dhananjay", 1000);
  h.insert("meeee", 31);

  h.diplay("dhananjay");
  h.diplay("dhanu");
  return 0;
}
