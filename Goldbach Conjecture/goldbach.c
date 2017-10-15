/*
 * File Name: goldbach.c
 * Author: Pradeep Singh
 * Date: 10/14/2017
 * Language: C
 * Purpose: To check Goldbach Conjecture for a list of positive integers.
 * Description:
 
 * Program usage is as:
 
 */

/* Include following header files */

#include <stdio.h>      // for printf() and scanf()

/* Function declaration */

/* Declaring function named isodd.
 * This function tells whether the given integer is odd or not.
 */
 
_Bool isodd(int M);                                             //

/* Declaring function named isprime.
 * This function tells whether the given integer is prime or not.
 */

_Bool isprime(int M);                                           //

/* Declaring function named isGoldbach.
 * This function tells whether the given integer is Goldbach or not.
 */

void isGoldbach(int M, int *passfail, int *prime1, int *prime2); //

/* Declaring function named printResults.
 * This function is used to print.
 */

void printResults(int N, int integers[N], int reason[N][3]);     //

/* Main() starts here */

int main(){
  ftpr = fopen();
  
  /* make end != EOF, and initialize sum to zero... */
  float fnum, fsum=0;
  int end=EOF+1, icount;
  float avg;

  printf("let's add some numbers. Please\n");
  printf("enter some numbers, CTL-D to quit:\n\n");

/* remember to say "address of" with scanf() */

  icount = 0;
  end = scanf("%f", &fnum);
  while (end != EOF) {
    printf("running sum: %f+%f=", fsum, fnum);
    fsum += fnum;
    icount++;
    printf("%f\n", fsum);
    end = scanf("%f", &fnum);
  }

  fclose (ftpr);
  work(N);
  return;
}

void work (int N){
int integers[N];
int reason[N][3];

ftpr = fopen("integers", );
if (!ftpr) return;

for (ii=0; ii<N; ii++){
  fscanf(ftpr,"%d", &intergers[ii]);
  
  isGoldbach (integers[ii], &reason[ii][0], &reason[ii][1], &reason[ii][2]);
  
  }
  
 printResults(N,intergers,reasons);
 
 return;
 }






