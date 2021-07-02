#include <stdio.h>

int main(void) {

  char arr[100];
  printf("Enter string:");
  scanf("%s", arr);

  int length = 0;
  while (arr[length] != '\0') {
    length++;
  }

  printf("%d ", length);
  return 0;
}
