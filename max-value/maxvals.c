/*
 * File Name: maxvals.c
 * Author: Pradeep Singh
 * Date: 9/16/2017
 * Language: C
 * Purpose: To find and print the largest/ maximum element between
 * two float arrays of numbers defined in an external file "arraycode.c".
 */

/* Header file stdio.h is included for printf() function */

#include <stdio.h>

/* nvals1 and nvals2 are integers which represent the number of
 * elements in arrays. These are defined externally in "arraycode.c"
 * and are accessed by using extern.
 */

extern int nvals1;
extern int nvals2;

/* *array1 and *array2 are pointers to arrays defined outside this
 * program in "arraycode.c" and are accessed using extern.
 */

extern float *array1;
extern float *array2;

/* main() function to calculate the maximum element between two arrays */

int main(){
  int ii=0,jj=0;            /* int variables to count number of times loop will run */
  float max1=0.0,max2=0.0;  /* float variables to compare with each element of arrays */
  float max=0.0;            /* float variable to compare maximum value between max1 and max2 */

/* first loop to calculate maximum/largest element in first array */

  for (ii;ii<nvals1;ii++) {   /* run loop for nvals1 times */
    if (array1[ii]>max1) {    /* compare if each element of array is greater than max1 */
      max1=array1[ii];        /* assign value of that element to max1 */
    }
  }

/* second loop to calculate maximum/largest element in second array */

  for (jj;jj<nvals2;jj++) {  /* run loop for nvals2 times */
    if (array2[jj]>max2) {   /* compare if each element of array is greater than max2 */
      max2=array2[jj];       /* assign value of that element to max2 */
    }
  }

/* Let's assume max1 is maximum/largest initially.
 * Using if/else statement, compare if max2 is larger or max1.
 */

  max=max1;          /* assume, max1 is largest */
  if (max2>max1){    /* If max2 > max1, then max2 is largest */
    max=max2;        /* else, max1 is largest. Assign max2 value to max. */
  }

/* print the array values/elements for each array using printf()
 * and also print the larget/maximum element among both the arrays.
 
  printf("The elements of first array =\n");
  for(ii=0;ii<nvals1;ii++) {    /* loop to print first array elements */
    printf("%f ", array1[ii]);
  }

  printf("\n\nThe elements of second array =\n");
  for(jj=0;jj<nvals2;jj++) {  /* loop to print second array elements */
    printf("%f ", array2[jj]);
  }

/* Using printf(), print the largest element among both arrays. */

  printf("\n\nThe largest element among both arrays =\n");
  printf("%f\n",max);

  return 0;
}

