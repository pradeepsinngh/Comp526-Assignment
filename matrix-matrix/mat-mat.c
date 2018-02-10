
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
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int main()
{

   int **mat1, **mat2, **result, i, j, k;              /* define variables */

   struct timeval start, end;
   gettimeofday(&start, NULL);                         /* start measuring time */

/* Dynamic memory allocation for Matrices*/
/* Allocate memory for matrix rows and columns = 1000 X 1000 */

/* Matrix -- 1 */
   mat1 = (int **) malloc(1000 * sizeof(int *));       /* allocating memory to rows */
   for (i=0;i<1000;i++)                                /* allocating memory to col */
       mat1[i] = (int *) malloc(1000 * sizeof(int));

/* Matrix -- 2 */
   mat2 = (int **) malloc(1000 * sizeof(int *));       /* allocating memory to rows */
   for (i=0;i<1000;i++)                                /* allocating memory to col */
       mat2[i] = (int *) malloc(1000 * sizeof(int));

/* Result Matrix */
   result = (int **) malloc(1000 * sizeof(int *));     /* allocating memory to rows */
   for (i=0;i<1000;i++)                                /* allocating memory to col */
       result[i] = (int *) malloc(1000 * sizeof(int));
