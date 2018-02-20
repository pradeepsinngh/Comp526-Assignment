/*
 * File Name: mat-mat.c
 * Author: Pradeep Singh
 * Date : 2/7/2018
 * Description: Matrix - Matrix Multiplication 
 *              This program generate two 1000 X 1000 matrices with random numbers between 0 and 1.
 *              using function srand() and rand(). We use malloc() to dynamically allocate memory for 
 *              all the matrices. And, finally product of two matrices is computed using nested for loops
 *              and result is stored in result matrix. Once computation is done, we de-allocate the memory 
 *              from all the matrices using free().
 *
 *              Program usage: - gcc -o mat-mat mat-mat.c                               // compile
 *                             - ./mat-mat                                              // run
 *                             - time ./mat-mat                                         // run with time function
 *                             - valgrind --tool=memcheck --leak-check=yes ./mat-mat    // check memory leaks
 *                             - gcc -Wall -o mat-mat mat-mat.c                         // check warnings
 *                             - gcc -O1 mat-mat.c -o mat-mat                           // optimization, 
 *                                                                                      // replace -O1 with -O2 and - O3
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int main()
{

   float **mat1, **mat2, **result;
   float a = 1.0;                                     /* define varibales */
   int i, j, k;

   struct timeval start, end;
   gettimeofday(&start, NULL);                         /* start measuring time */

   /* Dynamic memory allocation for Matrices*/
   /* Allocate memory for matrix rows and columns = 1000 X 1000 */

   /* Allocating memory to rows of all 3 matrices */
   mat1 = (float **) malloc(1000 * sizeof(float *));
   mat2 = (float **) malloc(1000 * sizeof(float *));
   result = (float **) malloc(1000 * sizeof(float *));

   /* Allocating memory to cols of all 3 matrices */
   for (i=0;i<1000;i++){
       mat1[i] = (float *) malloc(1000 * sizeof(float));
       mat2[i] = (float *) malloc(1000 * sizeof(float));
       result[i] = (float *) malloc(1000 * sizeof(float));
   }

   /* Generating matrix elements with random numbers between 0 and 1 */
   srand(time(NULL));                                         /* srand() sets the seed for rand() */
   for (i = 0; i < 1000; i++) {
      for (j = 0; j < 1000; j++) {
         mat1 [i][j] = (float) rand()/ (float) (RAND_MAX/a);  /* rand() generates random numbers b/w 0 & 1 */
         mat2 [i][j] = (float) rand()/ (float) (RAND_MAX/a);
      }
   }

   /* Nested loops to compute the product of 2 matrices. Result is stored in result matrix */
   for (i = 0; i < 1000; i++) {
       for (j = 0; j < 1000; j++) {
           for (k =0; k < 1000; k++) {
               result[i][j] = 0;
               result[i][j] = result[i][j] + mat1[i][k] * mat2[k][j];
           }
       }
   }

   gettimeofday(&end, NULL);    /* function to measure execution time */

   /* Print the time elapsed */
   printf("\n Time Elapsed: %fs \n", ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0));

   /* Free the allocated memory for all three matrices using free() */  
   for (i = 0; i < 1000; i++){
       free(mat1[i]);
       free(mat2[i]);
       free(result[i]);
   }
 
   free(mat1);
   free(mat2);
   free(result);

   mat1 = NULL;
   mat2 = NULL;
   result = NULL;

   return 0;
}
