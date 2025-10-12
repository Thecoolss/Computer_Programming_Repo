#include<stdio.h>
#include<stdlib.h>
#include "welcome.h"
int main(){
  
  const char* msg=get_welcome_message();
  printf("%s\n",msg);
  return 0;
}
