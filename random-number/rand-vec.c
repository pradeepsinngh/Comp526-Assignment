/*
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

   int vec[10];
   int i = 0;

   srand(time(NULL));
   for (; i < 10; i++){
      vec [i] = rand() % 2 + 0;
      printf("%i", vec[i]);
   }
   return 0;

}   
