//*
 * File Name: goldbach.c
 * Author: Pradeep Singh
 * Date: 10/14/2017
 * Language: C
 * Purpose: To check Goldbach Conjecture for a list of positive integers.
 * Description:
                1. The program "goldbach.c" takes a input file, which consist of
                   positive integers and tell's whether the given input numbers
                   are goldbach or not.

                2. The main() reads the input file named "integers" and keep(store)
                   a count of number of integers available to test.

                3. Then, function work() (a helper routine) again reads the file and
                   store the numbers in an array format: integers[N].

                4. Function isGoldbach() tells the caller about whether the given interger M
                   fails or passes the Goldbach test.

                5. Other functions like isodd(), isprime() are also used to determine
                   whether the given number is goldbach or not. Their usage is described below.

                6. Then, function printResults() is called from helper routine, which
                   prints the result for every integer as: "pass" or "fail".

                7. If the result for a number is "pass", the reason for which it satisfies
                   the Goldbach test is also printed. Moreover, if the reason is "sum of 2 primes",
                   then the 2 primes are also printed.

  * Program usage is as:

                      Step1: make             // complies code
                      Step2: ./goldbach

  */

/* Include following header files */

#include <stdio.h>      // for printf() and scanf()
#include <math.h>       // for math functions
#include <stdlib.h>

/* Function declaration */

/* Declaring function named "isodd".
 * This function tells whether the given integer is odd or not.
 */

_Bool isodd(int M);

/* Declaring function named "isprime".
 * This function tells whether the given integer is prime or not.
 */


_Bool isprime(int M);

/* Declaring function named "isGoldbach".
 * This function tells whether the given integer is Goldbach or not.
 */

void isGoldbach(int M, int *passfail, int *prime1, int *prime2);

/* Declaring function named "printResults".
 * This function is used to print the result.
 */

void printResults(int N, int integers[N], int reason[N][3]);

/* Declaring function named "work".
 * It's an helper routine, which is gonna help main() in conducting
 * Goldbach test.
 */

int work(int N);

/* ------------------------------------------------------------------------- */

/* Main() starts here */

int main(void){

  int *reason;            //pointer to array that holds condition for goldbach conjecture
  int *integers;          //pointer to array that holds input data
  int *prime1, *prime2;   //pointer to array that stores 2 numbers that when added give's
                          //an even number which is goldbach
  int *passfail;          //pointer to hold two values (1 or 0) depending upon whether the
                          //given input number passes/fails the goldbach test
  int read;               //to read from file
  int count = 0;          //variable to count number of integers in input file

  FILE * fptr;            //pointer to points to intergers in i/p file
  fptr = fopen("integers","r"); // open "integers" file for reading

  if (!fptr){              //check, if the file (intergers) is opening or not

    printf("\n Something is wrong! Could not open file\n");
    return(0);
  }

/* While loop to count number of positive numbers in i/p file (intergers) */

  while(fscanf(fptr,"%d",&read) != EOF){

    count++;
  }

 }

  close(fptr);            // close the file

  work(count);            // call to work function

  return;
}



/*------------------ Function's definition starts from here---------------------------- */

/* work(N) - Helper function for reading and stroing the input
             numbers in an array: integer[N]

             It also calls the isGoldbach() and printResults() for
             processing and printing the results.

             Note: There are many calls to isGoldbach(), but there is
             only call to printResults().

            Input: N -- Number of integers to be tested.

            Output: Prints the result, whether the given number is
                    goldbach or not, along with the reason.
 */


int work (int N){

  int integers[N];
  int reason[N][3];
  int i;

  FILE *fptr;
  fptr = fopen("integers","r");

  for (i = 0 ; i < N ; i++){

    fscanf(fptr, "%d", &integers[i]);

    isGoldbach(integers[i],&reason[i][0],&reason[i][1],&reason[i][2]);
  }

  fclose(fptr);

  printResults(N, integers, reason);

return 0;
}

/* This function returns 1 if M is odd, otherwise 0.
 * function: _Bool isodd(int M);

        Input: int M -- argument value

        Output: 1 (If argument is odd)
                0 (If argument is not odd)
*/

_Bool isodd(int M){

  int result;
  result = M % 2;

  if (result)
    return 1;
  else
    return 0;

}



/* This function returns 1 if M is prime, otherwise 0.
 * function: _Bool isprime(int M);

        Input: int M -- argument value

        Output: 1 (If argument is prime)
                0 (If argument is not prime)

 */

_Bool isprime(int M){

  _Bool result=1;
  int i;

  if ((M!=2)&&(M!=3)){  // if the input is 2 or 3 is already a prime - no need to check

    for( i = 2; i <= M/2 ; i++ )
      if ( !(M % i) )
        return 0;
  }
  return 1;
}


/* function: void isGoldbach(int M, int *passfail, int *prime1, int *prime2);

             int M -- argument value
             int *passfail -- reference to 0 or 1, depending upon whether M fail/ pass the test

             *passfail = 1, if M < 3
             *passfail = 2, if M is odd
             *passfail = 3, if M is sum of 2 primes

             If, *passfail = 3, therefore respective 2 primes are gievn by:
             int *prime1 -- first prime number
             int *prime2 -- second prime number
 */

void isGoldbach(int M, int *passfail, int *prime1, int *prime2 ){

  if (M < 3){                    //if M is less than 3, passfail[0] is 1 and the number is Goldbach

    *passfail = 1;

  }
  else if ( isodd(M) ){           //if M is odd, then passfail[0] = 2 and the number is Goldbach

    *passfail= 2;

  }
  else if(!isodd(M)){
    int i;

/* Loop to see if 2 prime numbers exist, which when added gives an goldbach number or not. */

    for ( i = 2; i <= (M/2); i++){

      if(isprime(i) && isprime( M-i)){

        *passfail = 3;
        *prime1= i;
        *prime2 = M-i;

      }
    }
  }

  else      // Otherwise, number didn't passed the test. Therefore, it's not an Goldbach.

    *passfail=0;      // return 0;
}



/* function to print the number and it's result (whether it's goldbach or not)

   void printfResults(int N, int integers[N], int reason[N][3]

   Inputs:
          int N: number of integers to be tested
          int integers[N]: Number to be tested
          int reason[N][3]: reason for the result

         If,
           reason = 1, M is less than 3
           reason = 2, M is odd
           reason = 3, M is sum of 2 primes

  Output: Print's the result on the screen. Tells whether the number is Goldbach or not.

          If it's Goldbach, then it also prints the reason for the same (eg: M is less than 3 etc).

           Otherwise, just print's that the number failed the test and it is not a Goldbach.
 */

void printResults(int N, int integers[N],int reason[N][3]){

  system("clear \n");
  printf(" Following numbers passes/ fails the Goldbach test: \n");
  printf("\n\n");

  printf("Number    Reason                   Result\n");
  printf("-----    ---------         -------------------------- \n\n");

  int i;
  for (i=0; i<N; i++){

    if (reason[i][0] == 0){ // If this happens, that means the number doesn't
                            // satisfy Goldbach test.(which apparently will never happen)

      printf ("M = %g does not satisfy Goldbach test \n", integers[i]);

    }
    else{

      if ( reason[i][0] == 1 )
        printf ("M = %d, is less than 3   (is Goldbach) \n", (int)integers[i]);
       else if ( reason[i][0] == 2 )
         printf ("M = %d, is odd           (is Goldbach) \n", (int)integers[i]);
       else if ( reason[i][0] == 3 )
         printf ("M = %d  = %d + %d        (the sum of primes, is Goldbach) \n", (int)integers[i], reason[i][1], reason[i][2] );

    }
  }
}
















































/* Main() starts here */

int main(){
  int *reason;            //pointer to array that holds condition for goldbach conjecture
  int *intergers;         //pointer to array that holds input data
  int *prime1, *prime2;   //pointer to array that stores 2 numbers that when added give's 
                          //an even number which is goldbach
  int *passfail;          //pointer to hold two values (1 or 0) depending upon given input
                          //number passes/fails the goldbach test
  int read;               //to read from file
  int count = 0;          //variable to count number of intergers in input file
 
  FILE * fptr;            //pointer to points to intergers in i/p file
  fptr = fopen("intergers","r"); // open "intergers" file for reading
 
  if (!fptr){              //see if file (intergers) is opening or not
	  
    print("\n Something is wrong! Could not open file\n");
    return(0);
  }
 
/* While loop to count number of positive numbers in i/p file (intergers) */
 
  while(fscanf(fptr,"%d",&read) != EOF){
  
    count++;
  }
  
  close(fptr);      // close the file

  work(counter);          // call to work function
 
  return;
}

int work (int N){

  int integers[N];
  int reason[N][3];
  int i;

  FILE *fptr;
  fptr = fopen("integers","r");

  for (i = 0 ; i < N ; i++){
    
    fscanf(fptr, "%d", &integers[i]);
	  
    isGoldbach(integers[i],&reason[i][0],&reason[i][1],&reason[i][2]);
  }
 
  fclose(fptr);
	
  printResults(N, integers, reason);
 
return 0;
}

/* This function returns 1 if M is odd, otherwise 0.
 * function: _Bool isodd(int M);
 
             int M -- argument value
 */
 
_Bool isodd(int M){

  int result;
  result = M % 2;
	
  if (result)
    return 1;
  else
    return 0;
	
}

/* This function returns 1 if M is prime, otherwise 0.
 * function: _Bool isprime(int M);
 
             int M -- argument value
 */

_Bool isprime(int M){
 
  _Bool result=1;
  int i;
	
  if ((M!=2)&&(M!=3)){  // if the input is 2 or 3 is already a prime - no need to check
  
    for( i = 2; i <= M/2 ; i++ )
      if ( !(M % i) )
        return 0;
   }
  return 1;
}
/* This function returns 1 if M is prime, otherwise 0.
 * function: void isGoldbach(int M, int *passfail, int *prime1, int *prime2);
 
             int M -- argument value
             int *passfail -- reference to 0 or 1, depending upon whether M fail/ pass the test
             int *prime1 -- first prime number
             int *prime2 -- second prime number
 */

void isGoldbach(int M, int *passfail, int *prime1, int *prime2 ){

  if (M < 3){//First test of the Goldbach, if the input is less than 3, passfail[0] is 1 and Goldbach test is successful
	
    *passfail = 1;

  }
  else if ( isodd(M) ){ //if the number is odd so it goes for second condition and passfail[0] (reason) is 2 and goldbach test is successful
        
    *passfail= 2;

  }
  else if(!isodd(M)){ // Goldbach shoud test to see if two prime number exist to satisfy the condition or not

    int i;
  
    for ( i = 2; i <= (M/2); i++){

      if(isprime(i) && isprime( M-i)){
                   
        *passfail = 3;
        *prime1= i;
        *prime2 = M-i;


      }
    }
  }
        // When we are here it means that the Goldbach is not satisfied so it should be finished and return with 0
  else
	  
    *passfail=0;
}

/* This function prints grid points and their derivative values in the file
 * function: void printfnvals(FILE *fptr, int nvals, float xvals[], float fpvals[])
         FILE *fptr      -- Pointer to filename for displaying output
         int nvals       -- the size of the interior gridpoints
         float xvals[]   -- point to the address of second index of gridpoint (input)
         float fpvals[]  -- point to the address of second index (output)
 */
           
void printResults(int N, int intergers[N], int reasons[N][3]){
  
  system("clear \n");
  printf(" This is the result of Goldbach test  \n");
  printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
  printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n");

  printf(" input                Result\n");
  printf(" ------      -------------------------- \n\n");

  int i;
  for (i=0; i<N; i++){
  	  
    if (reason[i][0] == 0){ // in case the Goldbach test is not satisfied 
                
      printf ("M = %g   is not satisfied by Goldbach test \n", integers[i]);
    
    }
    else{
       
      if ( reason[i][0] == 1 )
        printf ("M = %d, is less than 3   (is Goldbach) \n", (int)integers[i]);
       else if ( reason[i][0] == 2 )
         printf ("M = %d, is odd           (is Goldbach) \n", (int)integers[i]);
       else if ( reason[i][0] == 3 )
         printf ("M = %d  = %d + %d        (the sum of primes, is Goldbach) \n", (int)integers[i], reason[i][1], reason[i][2] );
                        
    }
  }
}


// that's all folks.
