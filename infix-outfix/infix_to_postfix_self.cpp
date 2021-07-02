#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <vector>

char is_operator(char ch) {

  char operators[] = {'+', '-', '*', '/', '^'};
  return std::find(std::begin(operators), std::end(operators), ch) !=
         std::end(operators);
  // if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
  //  return true;
  // else
  //  return false;
}
int precedence(char ch) {
  switch (ch) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
  }
  return -1;
}

int main(void) {

  std::stack<char, std::vector<char>> stack;

  std::string str;
  std::cout << "Enter expression: ";
  std::cin >> str;

  for (size_t i = 0; i < str.length(); i++) {
    if (std::tolower(str[i]) >= 'a' && std::tolower(str[i]) <= 'z') {
      std::cout << str[i];
      // Check if char is operator
    } else if (is_operator(str[i])) {
      if (stack.empty()) {
        stack.push(str[i]);
      } else if (precedence(str[i]) > precedence(stack.top())) {
        stack.push(str[i]);
      } else {
        do {
          std::cout << stack.top();
          stack.pop();
        } while (precedence(str[i]) <= precedence(stack.top()) &&
                 !stack.empty());
        stack.push(str[i]);
      }
    }
    // If char is '(' or ')'
    else {
      // IF char is '('
      if (str[i] == '(')
        stack.push(str[i]);
      // If char is ')'
      else {
        // IF '(' is right before ')'
        if (stack.top() == '(') {
          stack.pop();
        } else {
          do {
            std::cout << stack.top();
            stack.pop();
          } while (stack.top() != '(' && !stack.empty());
          stack.pop();
        }
      }
    }
  }
  while (!stack.empty()) {
    std::cout << stack.top();
    stack.pop();
  }
  return 0;
}
