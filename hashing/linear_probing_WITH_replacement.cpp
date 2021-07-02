// Program for open addressing with linear probing with replacement
// Here is if there is a element which is to be inserted and if element which
// already present there does not have same hash as that of index that element
// is repalced with element which is to be inserted and then using linear
// probing method we find next empty spot for deleted item

#include <array>
#include <iostream>

#define SIZE 10
class hashtable {
  std::array<int, SIZE> arr;

  int linear_probe(int);
  int hash(int);

public:
  hashtable();
  void search(int);
  void insert(int);
  void remove(int);
  void display();
};

int hashtable::hash(int element) { return (element % 10); }

void hashtable::search(int element) { int hash_index = hash(element); }
// Finds the next index and return the index of a empty location to store
// element If hashtable is full it returns -1 as index
int hashtable::linear_probe(int index) {

  for (int i = (index + 1) % SIZE; i != index; i = (i + 1) % SIZE) {
    if (arr.at(i) == -1) {
      return i;
    }
  }
  return -1;
}

hashtable::hashtable() {
  for (size_t i = 0; i < arr.size(); i++) {
    arr.at(i) = -1;
  }
}

void hashtable::display() {
  for (auto &x : arr) {
    std::cout << x << " ";
  }
  std::cout << "\n";
}

void hashtable::insert(int element) {

  int hash_index = hash(element);

  // If value at hash_index is empty
  if (arr.at(hash_index) == -1) {
    arr.at(hash_index) = element;
  } else {
    if (hash_index == hash(arr.at(hash_index))) {

      int location = linear_probe(hash_index);

      if (location == -1) {
        std::cout << "Hashtable is fulll!\n";
      } else {
        arr.at(location) = element;
      }
    } else {
      int temp = arr.at(hash_index);
      int location = linear_probe(hash_index);

      if (location == -1) {
        std::cout << "Hashtable is full!\n";
      } else {
        arr.at(hash_index) = element;
        arr.at(location) = temp;
      }
    }
  }
}

// Works correctly
int main() {
  hashtable h;
  h.insert(99);
  h.insert(89);
  h.display();
  h.insert(10);
  h.display();
  h.insert(100);
  h.display();
  h.insert(11);
  h.display();

  h.insert(99);

  h.insert(99);
  h.insert(89);
  h.insert(89);
  h.display();
  h.insert(10);
  h.display();
  h.insert(100);
  h.display();
  h.insert(11);
  h.display();
  return 0;
}
