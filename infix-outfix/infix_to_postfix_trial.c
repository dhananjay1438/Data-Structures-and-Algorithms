#include <stdbool.h>
#include <stdio.h>

#define SIZE 100
char stack[SIZE];
int top = -1;

int find_length(char *str) {
  int length = 0;
  while (str[length] != '\0')
    length++;
  return length;
}

int operator_precedence(char element) {
  switch (element) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
  default:
    return -1;
  }
}
void infix_to_postfix(char *str, int length) {

  int current_operator_precedence = -1;
  int top_operator_precedence = -1;
  for (int i = 0; i < length; i++) {
    // Add code to handle upper cases as well
    if (str[i] >= 'a' || str[i] <= 'z') {
      printf("%c", str[i]);
    } else if (str[i] == '+' || str[i] == '-' || str[i] == '*' ||
               str[i] == '/' || str[i] == '^') {
      current_operator_precedence = operator_precedence(str[i]);
      top_operator_precedence = operator_precedence(stack[top]);
    }
  }
}

int main(void) {

  char str[SIZE];
  printf("Enter a expression:");
  scanf("%s", str);
  infix_to_postfix(str, find_length(str));

  return 0;
}
