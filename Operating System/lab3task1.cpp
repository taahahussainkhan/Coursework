#include <stdio.h>

int main() {
  int length=0;
int  width=0;
int area=0;

  printf("What is the length of the rectangle? ");
  scanf("%d", &length);

  printf("What is the width of the rectangle? ");
  scanf("%d", &width);

  area = length * width;

  printf("The area of the rectangle is %d.\n", area);

  return 0;
}