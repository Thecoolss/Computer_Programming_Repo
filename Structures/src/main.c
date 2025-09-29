#include "rectangle.h"
#include <stdio.h>

int main(void) {
   
    Rectangle r1 = {10, 5};

    printf("--- Initial Rectangle ---\n");
    printf("Rectangle 1 (r1): width = %d, height = %d\n", r1.w, r1.h);

    int a = area(r1);
    printf("Area of r1: %d\n", a);
    
    printf("\n--- Growing r1 by 5 in width and 2 in height ---\n");
    grow(&r1, 5, 2);

    printf("Rectangle 1 (r1) after grow: width = %d, height = %d\n", r1.w, r1.h);
    printf("New Area of r1: %d\n", area(r1));

    printf("\n--- Shrinking r1 by -20 in width and -10 in height ---\n");
    grow(&r1, -20, -10);

    printf("Rectangle 1 (r1) after shrink: width = %d, height = %d\n", r1.w, r1.h);
    printf("New Area of r1: %d\n", area(r1));

  

    return 0;
}