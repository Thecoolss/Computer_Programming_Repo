#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void root_privileged_print(const char *message, long user) {
  if (user == 0xbada55) {
    printf("Root says: %s\n", message);
  }
  if (user == 0xdeadbeef) {
    printf("Users do not have access to this function\n");
  }
}
void injection() {
  long stack_start;
  long *stack_walker = &stack_start;

  for (int i = 1; i < 50; ++i) {
    printf("%p\n", stack_walker +i);
    if (*(stack_walker + i) == 0xdeadbeef) {
      *(stack_walker + i) = 0xbada55;
      printf("%p\n", stack_walker + i);
      break;
    }
    if (*(stack_walker - i) == 0xdeadbeef) {
      *(stack_walker - i) = 0xbada55;
       printf("%p\n", stack_walker - i);
      break;
    }
  }
}
int main() {
  volatile long user = 0xdeadbeef;
  printf("%p\n", &user);
  injection();
  root_privileged_print("ALL YOUR BASE ARE BELONG TO US", user);
  return 0;
}
