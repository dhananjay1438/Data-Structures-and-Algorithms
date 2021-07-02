#include <cstring>
#include <iostream>

#define SIZE 10
class mystack {
private:
  char arr[SIZE];
  int top;

public:
  mystack();
  bool isEmpty();
  bool isFull();
  char pop();
  void push(char);
  char get_top_value();
};

mystack ::mystack() { top = -1; }
bool mystack::isEmpty() {
  if (top == -1)
    return true;
  else
    return false;
}

bool mystack::isFull() {
  if (top == SIZE - 1)
    return true;
  else
    return false;
}
char mystack::pop() {
  if (!isEmpty()) {
    return arr[top--];
  }
  return '\0';
}
void mystack::push(char element) {

  if (!isFull())
    arr[++top] = element;
  else
    printf("Stack is already full");
}

int operator_priority(char ch) {
  switch (ch) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 4;
  }
  return -1;
}

char mystack::get_top_value() { return arr[top]; }

bool is_operator(char ch) {
  if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
    return true;
  else
    return false;
}
int main(void) {
  std::string str;
  std::cout << "Enter expression:";
  std::cin >> str;
  mystack stack;

  int len = str.length();
  for (int i = 0; i < len; i++) {
    // If char is a letter
    if (std::tolower(str[i]) >= 'a' && std::tolower(str[i]) <= 'z') {
      std::cout << str[i];
      // If char is opeartor
    } else if (is_operator(str[i])) {
      if (stack.isEmpty()) { // If it is first operator to be added
        stack.push(str[i]);
        // If priority of opeartor to be added is greater than that of at the
        // top then simply push the value
      } else if (operator_priority(str[i]) >
                 operator_priority(stack.get_top_value())) {
        stack.push(str[i]);
        // If priority of operator to be added is greater than that of at the
        // top pop operators until operator to be added has higher priority than
        // that of the top element (priority should be '>' and not '>=' to stop
        // popping)
      } else {
        do {
          std::cout << stack.pop();
        } while (operator_priority(str[i]) <=
                     operator_priority(stack.get_top_value()) &&
                 !stack.isEmpty());
        stack.push(str[i]);
      }

      // If char is opening parenthesis or closing parenthesis
    } else {
      if (str[i] == '(')
        stack.push(str[i]);
      // If it is closing parenthesis pop all the items until openining
      // parenthesis '(' is found
      else {
        if (stack.get_top_value() == '(') {
          stack.pop();
        } else {
          do {
            std::cout << stack.pop();
          } while (stack.get_top_value() != '(' && !stack.isEmpty());
          stack.pop();
        }
      }
    }
  }
  while (!stack.isEmpty())
    std::cout << stack.pop();
}
