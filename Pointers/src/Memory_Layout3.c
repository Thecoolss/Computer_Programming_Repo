#include<stdlib.h>
#include<stdio.h>
int main()
{
  int* heap_arr=(int*) malloc(1000*sizeof(int));
  printf("Size of heap_arr: %zu\n", sizeof(heap_arr));
  free(heap_arr);

  int stack_arr[1000];
  printf("Size of stack_arr: %zu\n", sizeof(stack_arr));  
  return 0;
}

/*
OUTPUT:
Size of heap_arr: 8
Size of stack_arr: 4000

Explanation:
heap_arr is occupying 8 bytes only because it stores the address of the first int of the allocated array on the heap not the whole array.

When sizeof is applied to a statically-sized array defined on the stack (like stack_arr[1000]), the compiler knows the full size of the array at compile time. Since it's an array of 1000 integers, and an int is 4 bytes, the total size is 1000×4=4000 bytes.

*/