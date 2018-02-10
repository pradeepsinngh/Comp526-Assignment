/*
 * File Name: mat-vec.c
 * Author: Pradeep Singh
 * Date: 6/2/2018
 * Description: Matrix - Vector Multiplicat
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int main()
{

  int **mat, *vec, **result, i, j;

  struct timeval start, end;

  gettimeofday(&start, NULL);

  mat = (int **) malloc(1000 * sizeof(int *));

  for (i=0;i<1000;i++)
      mat[i] = (int *) malloc(1000 * sizeof(int));

  vec = (int *) malloc(1000 * sizeof(int *));
/*
 * for (i=0;i<1000;i++)
 *     mat2[i] = (int *) malloc(1000 * sizeof(int));
 */
  result = (int **) malloc(1000 * sizeof(int *));

  for (i=0;i<1000;i++)
     result[i] = (int *) malloc(1000 * sizeof(int));

   srand(time(NULL));
   for (i=0; i <1000; i++){
       vec [i] = rand() % 2;
/*     printf("%i \n", vec[i]); */
       for (j=0; j < 1000; j++){
           mat [i][j] = rand() % 2;
/*         printf("%i \n", mat[i][j]); */
       }
   }

   for (i = 0; i < 1000; i++) {
       result [i] = 0;
       for (j = 0; j < 1000; j++) {
           result [i] = result [i] + mat [i][j] * vec [j];
      }
   }

  gettimeofday(&end, NULL);
/* estimate the time taken by program to multiply mat and vec */
  printf("%i \n", ( end.tv_usec - start.tv_usec));

  /* free the allocated memory */
  /* for (i = 0; i < 999; i++) {
       free(result[i]);
       free(mat[i]);
       }
  */

  free(mat);
  free(vec);
  free(result);

   mat = NULL;
   vec = NULL;
   result = NULL; 

   return 0;
} 
