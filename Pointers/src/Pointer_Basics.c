#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y){
 int temp=*x;
 *x=*y;
 *y=temp;
}

int main()
{
  int a,b;
  scanf("%d%d",&a,&b);
  swap(&a,&b);
  printf("a: %d, b:%d",a,b);
  return 0;
}