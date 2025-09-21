#include "name_length.h"
#include<string.h>
int name_length(const char* name){
  int n=strlen(name),c=0;
  for (int i=0;i<n;++i)
      if (name[i]==' ')
        ++c;

  return n-c;

}