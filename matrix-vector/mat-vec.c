/*
 * File Name: mat-vec.c
 * Author: Pradeep Singh
 * Date : 2/7/2018
 * Description: Matrix - Vector Multiplication
 *              This program generate a 1000 X 1000 matrix and a vector of 1000 elements  with random 
 *              numbers between 0 and 1 using function srand() and rand(). We use malloc() to dynamically 
 *              allocate memory for matrix and vector. And, finally product of two is computed using for loops
 *              and result is stored in result vector. Once computation is done, we de-allocate the memory
 *              from both matrices and vector using free().
 *
 *              Program usage: - gcc -o mat-vec mat-vec.c                               // compile
 *                             - ./mat-vec                                              // run
 *                             - time ./mat-vec                                         // run with time function
 *                             - valgrind --tool=memcheck --leak-check=yes ./mat-vec    // check memory leaks
 *                             - gcc -Wall -o mat-vec mat-vec.c                         // check warnings
 *                             - gcc -O1 mat-vec.c -o mat-mat                           // optimization, replace -O1 with -O2/ -O3
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

int main()
{
   float **mat, *vec, *result;
   float a = 1.0;
   int i, j;                                            /* define varibales */

   struct timeval start, end;
   gettimeofday(&start, NULL);                          /* start measuring time */

   /* Dynamic memory allocation for Matrices and Vector*/
   /* Allocate memory for matrix rows and columns = 1000 X 1000 */

   /* Matrix -- 1 */
   mat = (float **) malloc(1000 * sizeof(float *));        /* allocating memory to rows */
   for (i=0;i<1000;i++)                                    /* allocating memory to col */
       mat[i] = (float *) malloc(1000 * sizeof(float));

   /* Vector */
   vec = (float *) malloc(1000 * sizeof(float *));         /* allocate memory for vector */

   /* Result Vector */
   result = (float *) malloc(1000 * sizeof(float *));      /* allocate memory for result vector */

   /* Generating matrix elements with random numbers between 0 and 1 */
   srand(time(NULL));                                           /* srand() sets the seed for rand() */
   for (i=0; i <1000; i++){
       vec [i] = (float) rand()/ (float) (RAND_MAX/a);          /* rand() generates the random number */
       for (j=0; j < 1000; j++){
           mat [i][j] = (float) rand()/ (float) (RAND_MAX/a);
       }
   }

   /* Computing the Matrix - Vector product and storing it in result matrix */
   for (i = 0; i < 1000; i++) {
       result [i] = 0;
       for (j = 0; j < 1000; j++) {
           result [i]= result [i] + mat [i][j] * vec [j];
       }
   }

  gettimeofday(&end, NULL);                             /* stop measuring time */

   /* Print the time elapsed */
   printf("\n Time Elapsed: %fs \n", ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0));

   /* Free the allocated memory for  matrices and vector using free() */

   for (i = 0; i < 1000; i++){
       free(mat[i]);
   }

   free(mat);
   free(vec);
   free(result);

   mat = NULL;
   vec = NULL;
   result = NULL; 

   return 0;
} 
