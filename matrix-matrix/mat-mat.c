/*
 * Allocating memory dynamically to generate 1000 X 1000 Matrix
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int main()
{

  int **mat1, **mat2, **result, i, j, k;

  struct timeval start, end;

  gettimeofday(&start, NULL);

  mat1 = (int **) malloc(1000 * sizeof(int *));

  for (i=0;i<1000;i++)
      mat1[i] = (int *) malloc(1000 * sizeof(int));

  mat2 = (int **) malloc(1000 * sizeof(int *));

  for (i=0;i<1000;i++)
      mat2[i] = (int *) malloc(1000 * sizeof(int));

  result = (int **) malloc(1000 * sizeof(int *));

  for (i=0;i<1000;i++)
     result[i] = (int *) malloc(1000 * sizeof(int));

   srand(time(NULL));
   for (i = 0; i < 1000; i++) {
      for (j = 0; j < 1000; j++) {
         mat1 [i][j] = rand() % 2;
         mat2 [i][j] = rand() % 2;
 /*      printf("%i \n", mat2 [i][j]); */
      }
   /* printf("%i \n", mat1 [i][j]); */
   }


   for (i = 0; i < 1000; i++) {
      for (j = 0; j < 1000; j++) {
         for (k =0; k < 1000; k++) {
            result[i][j] = 0;
            result[i][j] = result[i][j] + mat1[i][k] * mat2[k][j];
         /* printf("%i \n", result[i][j]); */
         }
        /* printf("%i \n", result[i][j]);*/
      }
     /* printf("%i \n", result[i][j]); */
  }

  gettimeofday(&end, NULL);

  printf("%i \n", ( end.tv_usec - start.tv_usec));

  free(mat1);
  free(mat2);
  free(result);

  mat1 = NULL;
  mat2 = NULL;
  result = NULL;

  return 0;
}
