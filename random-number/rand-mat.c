/*
 * Random Matrix
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

   int mat [5][5];
   int i, o;

   srand(time(NULL));
   for (o = 0; o < 5; o++) {
       for (i = 0; i < 5; i++) {
           mat [o][i] = rand() % 2;
           printf("%i", mat[o][i]);
       }
   }
   return 0;
}
