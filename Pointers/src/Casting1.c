#include<stdio.h>
int main()
{
  int i_val = 1032154688; 
  float f_val_cast = (float)i_val; 
  printf("C-style cast result: %f\n", f_val_cast);



  int* i_ptr = &i_val;
  float f_value=*((float*)i_ptr);
  printf("Value of reintepreted float pointer: %f\n",f_value);

  /*
  To get a float value of 2.0, we need to find the integer representation of 2.0.
  */
  float f2=2.0;
  float* f2p=&f2;
  int v_2=*(int*)f2p;
  printf("%d\n",v_2);
  float* fl_p_2=(float*)&v_2;
  float fl_v_2=*fl_p_2;
  printf("%f\n",fl_v_2);
  return 0;
}