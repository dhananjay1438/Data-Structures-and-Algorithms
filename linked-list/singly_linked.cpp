#include <iostream>

struct sll {
  int data;
  struct sll *next;
};
typedef struct sll sll;
class mysll {

private:
  sll *head = NULL;
  sll *last = NULL;

public:
  mysll();
  void insert(int);
  void display();
  ~mysll();
};
mysll::mysll() {
  head = NULL;
  last = NULL;
}
void mysll::insert(int data) {
  sll *temp = new sll;
  temp->data = data;
  temp->next = NULL;
  if (head == NULL) {
    head = temp;
    last = temp;
  } else {
    last->next = temp;
    last = temp;
  }
}
void mysll::display() {
  if (head == NULL)
    std::cout << "Empty!!";
  else {
    sll *temp = head;
    while (temp != NULL) {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
  }
}

mysll ::~mysll() {
  sll *traverse = NULL;
  sll *prev = traverse;
  while (traverse != NULL) {
    prev = traverse;
    traverse = traverse->next;
    delete prev;
  }
  delete last;
}
int main(void) {

  mysll l;
  l.insert(10);
  l.insert(20);
  l.display();

  return 0;
}
