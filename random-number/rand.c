#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

  srand(time(NULL));
  int a;
   for (int i =0; i < 1000; i++) {
       a = rand() % 2 + 0.1;
       printf(" %i", a);
   }
   return 0;
}     
