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
   
  printResults(N, integers, reasons)
  
  }
 

/* This function returns 1 if M is odd, otherwise 0.
 * function: _Bool isodd(int M);
 
             int M -- argument value
 */
 
_Bool isodd(int M){
   
   if (M % 2 == 0){
     return 1;
   }
   else {
     return 0;
   }
}

/* This function returns 1 if M is prime, otherwise 0.
 * function: _Bool isprime(int M);
 
             int M -- argument value
 */

_Bool isprime(int M){
  int R1=1, R2=M;
  if (M > 1 && (M % R1 = 0) && (M % R2 = 0)){
    return 1;
  } 
  else{
    return 0;
  }
}
 
/* This function returns 1 if M is prime, otherwise 0.
 * function: void isGoldbach(int M, int *passfail, int *prime1, int *prime2);
 
             int M -- argument value
             int *passfail -- reference to 0 or 1, depending upon whether M fail/ pass the test
             int *prime1 -- first prime number
             int *prime2 -- second prime number
 */

isGoldbach(integers[i], &reason[1][0], &reason[i][1], &reason[1][2]{

M = 10;

for(ii = 2; ii < M/2; ii++){
  if(isprime(ii) && isprime(M-ii)){
    
    *prime1 = ii;
    *prime2 = M-11;
    *passfail = 3;
    return;
  }
}

*passfail = 0;
return;

}

void printResults(int N, int integers[N], int reason[N][3])     //


/* This function prints grid points and their derivative values in the file
 * function: void printfnvals(FILE *fptr, int nvals, float xvals[], float fpvals[])
         FILE *fptr      -- Pointer to filename for displaying output
         int nvals       -- the size of the interior gridpoints
         float xvals[]   -- point to the address of second index of gridpoint (input)
         float fpvals[]  -- point to the address of second index (output)
 */
 
 
printResults(N,intergers[N],reasons[N][3]){
       
  int ii;    // Initalizing integer variable to count number of times loop will run

  for(ii=0; ii<M; ii++){
    i
     fprintf(fptr, "%0.2f %0.2f \n", integers[ii], reason[ii]);   // Writing in the file
  }
}
 
 return;
 }

// that's all folks.
