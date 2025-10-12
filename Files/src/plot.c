#include "plplot/plplot.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void plot(const char* filename){
  FILE* file=fopen(filename,"r");
  if(file==NULL){
    perror("Error opening file");
    return ;
  }
  PLFLT* x=(PLFLT*)malloc(20*sizeof(PLFLT));
  PLFLT* y=(PLFLT*)malloc(20*sizeof(PLFLT));
  char **labels=(char**)malloc(20*sizeof(char*));
  
}

int main()
{
  plot("word_counts.txt");

  return 0;
}