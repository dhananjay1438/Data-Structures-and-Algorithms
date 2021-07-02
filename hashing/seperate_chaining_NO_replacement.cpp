#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>

#define SIZE 10

class hashtable {

  std::array<int, SIZE> arr;
  std::array<int, SIZE> chain;

  int hash(int);
  int find_empty_index_from(int);

public:
  hashtable();

  void insert(int);
  void remove(int);
  void search(int);
  void display();
};

hashtable::hashtable() {
  std::fill_n(arr.begin(), SIZE, -1);
  std::fill_n(chain.begin(), SIZE, -1);
}

int hashtable::hash(int element) { return (element % SIZE); }

int hashtable::find_empty_index_from(int element) {

  for (int i = (element + 1) % SIZE; i != element; i = (i + 1) % SIZE) {
    if (arr.at(i) == -1) {
      return i;
    }
  }
  return -1;
}

void hashtable::display() {
  for (auto &x : arr) {
    std::cout << std::setw(3) << x << " ";
  }
  std::cout << "\n";

  for (auto &x : chain) {
    std::cout << std::setw(3) << x << " ";
  }
  std::cout << "\n";
}

void hashtable::insert(int element) {
  int hash_index = hash(element);

  if (arr.at(hash_index) == -1) {
    arr.at(hash_index) = element;
  } else {
    int location = find_empty_index_from(hash_index);

    while (chain.at(hash_index) != -1) {
      hash_index = chain.at(hash_index);
    }
    chain.at(hash_index) = location;
    arr.at(location) = element;
  }
}
void hashtable::search(int element) {

  int hash_index = hash(element);

  if (arr.at(hash_index) == -1) {
    std::cout << "Element " << element << " not present\n";
    return;
  }

  while (chain.at(hash_index) != -1) {
    if (arr.at(hash_index) == element) {
      std::cout << "Element found\n";
      return;
    }
    hash_index = chain.at(hash_index);
  }
  if (arr.at(hash_index) == element) {
    std::cout << "Element found\n";
  } else {
    std::cout << "Not found\n";
  }
}
int main(void) {

  hashtable h;

  h.insert(10);
  h.insert(20);
  h.insert(30);
  h.insert(91);
  h.insert(84);

  h.display();

  h.search(41);
  h.search(30);
  h.search(84);
  return 0;
}
