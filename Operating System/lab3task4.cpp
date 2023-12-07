#include <stdio.h>
#include <stdbool.h>

void checkPrimeNumber(int num) {
  bool isPrime = true;

  if (num <= 1) {
    isPrime = false;
  } else {
    for (int i = 2; i <= num / 2; i++) {
      if (num % i == 0) {
        isPrime = false;
        break;
      }
    }
  }

  if (isPrime) {
    printf("%d is a prime number.\n", num);
  } else {
    printf("%d is not a prime number.\n", num);
  }
}

int main() {
  int num;

  printf("Enter the number: ");
  scanf("%d", &num);

  checkPrimeNumber(num);

  return 0;
#include <stdio.h>
#include <stdbool.h>

void checkPrimeNumber(int num) {
  bool isPrime = true;

  if (num <= 1) {
    isPrime = false;
  } else {
    for (int i = 2; i <= num / 2; i++) {
      if (num % i == 0) {
        isPrime = false;
        break;
      }
    }
  }

  if (isPrime) {
    printf("%d is a prime number.\n", num);
  } else {
    printf("%d is not a prime number.\n", num);
  }
}

int main() {
  int num;

  printf("Enter the number: ");
  scanf("%d", &num);

  checkPrimeNumber(num);

  return 0;
}