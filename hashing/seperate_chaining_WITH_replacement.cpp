#include <algorithm>
#include <array>
#include <exception>
#include <iomanip>
#include <iostream>

#define SIZE 10

class method_not_implemented : public std::runtime_error {

public:
  method_not_implemented() : runtime_error("Not implemented") {}
};
class hashtable {

  std::array<int, SIZE> arr;
  std::array<int, SIZE> chain;

  int hash(int);
  int find_empty_index_from(int);

public:
  hashtable();
  void display();

  void insert(int);
  void remove(int);
  void search(int);
};

hashtable::hashtable() {
  std::fill_n(arr.begin(), SIZE, -1);
  std::fill_n(chain.begin(), SIZE, -1);
}

int hashtable::hash(int element) { return (element % SIZE); }

int hashtable::find_empty_index_from(int index) {
  for (int i = (index + 1) % SIZE; i != index; i = (i + 1) % SIZE) {
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

    if (location == -1) {
      std::cout << "Hastable if full!\n";
      return;
    }

    int hash_of_element_at_hash_index = hash(arr.at(hash_index));
    if (hash_of_element_at_hash_index == hash_index) {
      int i = hash_index;
      while (chain.at(i) != -1) {
        i = chain.at(i);
      }
      chain.at(i) = location;
      arr.at(location) = element;

    } else {

      int i = hash_of_element_at_hash_index;
      while (arr.at(chain.at(i)) != arr.at(hash_index)) {
        i = chain.at(i);
      }
      // Change the chain pointer of last element which used to point to the
      // element which is curently being moved.
      //
      // Inserting value which was at wrong index at empty index found with
      // linear probing.
      //
      // Inserting value to be inserted in its correct position.
      //
      // Replacing the chain pointer stored with the value which is moved to its
      // new poisition.
      //
      // Replacing chain pointer to -1 for newly added element at index
      // 'hash_index'.
      chain.at(i) = location;
      arr.at(location) = arr.at(hash_index);
      arr.at(hash_index) = element;
      chain.at(location) = chain.at(hash_index);
      chain.at(hash_index) = -1;
    }
  }
}

void hashtable::remove(int element) {
  int hash_index = hash(element);

  if (arr.at(hash_index) == -1) {
    std::cout << "Element " << element << " not found\n";
    return;
  }

  // If first element is the element to be deleted
  if (arr.at(hash_index) == element) {
    arr.at(hash_index) = -1;
    chain.at(hash_index) = -1;
  } else {
    // If any of rest of the elements (except last element) is the element to be
    // deleted
    int parent = hash_index;
    int i = chain.at(hash_index);
    while (chain.at(i) != -1) {
      if (arr.at(i) == element) {
        arr.at(i) = -1;
        chain.at(parent) = chain.at(i);
        chain.at(i) = -1;
        return;
      }
      parent = i;
      i = chain.at(i);
    }
    // If last element is the element to be deleted
    if (arr.at(i) == element) {
      arr.at(i) = -1;
      chain.at(parent) = chain.at(i);
    }
  }
}

void hashtable::search(int element) {
  int hash_index = hash(element);

  if (arr.at(hash_index) == -1) {
    std::cout << "Element " << element << " is not present\n";
    return;
  }

  int i = hash_index;
  while (chain.at(i) != -1) {
    if (arr.at(i) == element) {
      std::cout << "Element " << element << " found\n";
      return;
    }
    i = chain.at(i);
  }

  if (arr.at(i) == element) {
    std::cout << "Element " << element << " found\n";
  } else {
    std::cout << "Element " << element << " is not present\n";
  }
}

int main(void) {

  hashtable h;

  h.insert(10);
  h.insert(20);
  h.insert(30);
  h.insert(40);
  h.insert(52);
  h.insert(62);
  h.insert(99);
  h.insert(19);
  h.insert(37);
  h.insert(47);

  h.display();

  h.remove(40);
  h.display();

  h.insert(72);
  h.display();
  h.remove(72);
  h.display();
  return 0;
}
