// Simple hashing program for linear probing with no replacement
// If there is element who's hash is not the same as of the index
// even then we do not replace the element we simply use linear probing
// method to find next empty spot
#include <array>
#include <iostream>

#define SIZE 11
class hashtable {

  std::array<int, SIZE> arr;

  int hash(int);
  int find_empty_index_from(int);

public:
  hashtable();
  void insert(int);
  void remove(int);
  void search(int);
  void display();
};

hashtable::hashtable() { std::fill_n(arr.begin(), SIZE, -1); }

int hashtable::find_empty_index_from(int element) {

  for (int i = ((element + 1) % SIZE); i != element; i = (i + 1) % SIZE) {
    if (arr.at(i) == -1) {
      return i;
    }
  }
  return -1;
}
int hashtable::hash(int element) {
  int val = (element + 5) * (element + 5);
  val /= 16;
  val += element;
  val = val % 11;
  return val;
}

void hashtable::insert(int element) {
  int hash_index = hash(element);

  // Position is empty so enter
  if (arr.at(hash_index) == -1) {
    arr.at(hash_index) = element;
  }
  // Else it is not empty
  else {
    // There's a element stored at that hash location so find empty location
    // with linear probing
    int location = find_empty_index_from(hash_index);

    // If array is full
    if (location == -1) {
      std::cout << "Array with hashes is full!!!\n";
      return;
    } else {
      arr.at(location) = element;
    }

    // If there's an element already there but hashes of both elements is
    // different
  }
}

void hashtable::remove(int element) {
  int hash_index = hash(element);

  if (arr.at(hash_index) == element) {
    std::cout << "Element deleted: (" << arr.at(hash_index) << ")\n";
    // Just set the index to -1
    arr.at(hash_index) = -1;
    return;
  }
  // Find if element exists via linear porbing
  else {

    for (int i = (hash_index + 1) % SIZE; i != hash_index; i = (i + 1) % SIZE) {
      if (arr.at(i) == element) {
        std::cout << "Element deleted: (" << arr.at(i) << ")\n";
        arr.at(i) = -1;
        return;
      }
    }
  }

  std::cout << "Element: " << element << " not found!\n";
}

void hashtable::search(int element) {

  int hash_index = hash(element);

  if (arr.at(hash_index) == element) {
    std::cout << "Element such as " << element << " present\n";
    return;
  } else {
    for (int i = (hash_index + 1) % SIZE; i != hash_index; i = (i + 1) % SIZE) {
      if (arr.at(i) == element) {
        std::cout << "Element such as " << element << " present\n";
        return;
      }
    }
  }
  std::cout << "No element such as " << element << " present\n";
}

void hashtable::display() {

  for (auto &val : arr) {
    std::cout << val << " ";
  }
  std::cout << std::endl;
}

int main(void) {

  hashtable h;

  h.insert(43);
  h.insert(23);
  h.insert(1);
  h.insert(0);
  h.insert(15);
  h.insert(31);
  h.insert(4);
  h.insert(7);
  h.insert(11);
  h.insert(3);

  h.display();
  return 0;
}
