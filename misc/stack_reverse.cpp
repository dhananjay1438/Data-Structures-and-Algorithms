#include <iostream>
#include <stack>

int main(void) {

  std::stack<char> stack;

  std::string str;
  std::cin >> str;
  std::string reversed;

  for (size_t i = 0; i < str.length(); i++) {
    stack.push(str[i]);
  }

  while (!stack.empty()) {
    reversed.push_back(stack.top());
    stack.pop();
  }
  if (reversed == str) {
    std::cout << "String is palindrome";
  } else {
    std::cout << "String is not palindrome";
  }

  return 0;
}
