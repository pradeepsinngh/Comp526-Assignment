
/* goldbach.c 
This code will test the Goldbach conjecture and shows the related result in the output.

/* Program Description -- The program goldbach checks the Goldbach
                          conjecture for a list of positive integers
                          that are read from a file called integers.
                          This file consists of positive integers
                          separated by whitespace or newlines.

                       -- The main() function begins by reading all the
                          integers in the file and determines the number
                          N of inputs. Then it closes the file.

                       -- main() calls the helper routine work() to reopen the
                          file and read the data to the allocated storage as

                                 int integers[N]

                      -- work() then calls isGoldbach() function that returns the
                         Pass-fail information about how the integer fails or passes the
                         Goldbach test. Subsequently, work() calls a function
                         printResults() to print out the input numbers to
                         STDOUT and state the result for each: "pass" or "fail".

                      -- The program is required to store the input data in an
                         array integers[N] ñ and uses an additional
                         boolean array, passfail[N], and 3 additional integer arrays:
                         reason[N][3], and prime1[N] and prime2[N].

                        o Program usage is as,

                           make
                          ./goldbach
*/

//-----------------------------------------------------------------------------------


// Header files 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


// function declaration for the helper routine work()
int work(int N);

//function declaration for checking Goldbach conjecture
void isGoldbach(int M, int *passfail, int *prime1, int *prime2 );

//function declaration for checking odd numbers
_Bool isodd(int M);

//function declaration for checking prime numbers
_Bool isprime(int M);

// function declaration for printing result in STDOUT
void printResults(int N, int integers[], int reason[N][3]);


/* The main body of the program starts here*/
int main(void){

 /*
     int *integers: points to an array that stores input data.
     int *reason: points to an array that declare Goldbach satisfaction condition.
     int *prime1 and *prime2: if an even number satisfies Goldbach conjecture;
                              these two pointers point to two arrays that store
                              prime numbers which satisfy this condition.
 */
        int *reason, *prime1, *prime2 ;
        int *integers;

        //this boolean variable will store the result of the Goldbach function for each number (1= satisfied, 0= not satisfied)
        int *passfail;

        // input character which will be read from file one at a time
        int input_ch ;

        //number of the integers in the input file
        int counter = 0;

        FILE * fptr; // Defining a pointer which points to the input file integers
        fptr = fopen("integers","r"); // open for reading

        if (!fptr) //checking if the file opened successfully or not
        {
                printf("\n  Error! Could not open integer file\n");
                return(0);
        }

        while(fscanf(fptr,"%d",&input_ch) != EOF) //counting the number of the natural numbers in the input file
        {
                counter++;
        }
        fclose(fptr); //file should be closed after each use


        work(counter);
return;
}




int work(int N) {

         //now we open data file to read, process and store data in the data arrays
	FILE *fptr;
        fptr = fopen("integers","r");
        int integers[N];
        int reason[N][3];
        int i;
        
        //reading the numbers from files and store them in the integers array
        
        for (i = 0 ; i < N ; i++){
                fscanf(fptr, "%d", &integers[i]);
                isGoldbach(integers[i],&reason[i][0],&reason[i][1],&reason[i][2]);
        }
        fclose(fptr);
        printResults(N, integers, reason);
return 0;
}


//this function will check whether the input M is odd or not
_Bool isodd(int M){

/* inputs:
     M     -- integer to be tested

     return values:
           If M is odd then return '1' otherwise return '0'
  */

        int result;
        result = M % 2;
        if (result)
                return 1;
        else
                return 0;
}

//isprime will check if the input number is a prime or not
_Bool isprime(int M)
{
 
/* inputs:
     M     -- integer to be tested

     return values:
          
          If M is not prime then return '0' otherwise return '1'
*/
       _Bool result=1;
        int i;
        if ((M!=2)&&(M!=3)) // if the input is 2 or 3 is already a prime - no need to check
        {
                for( i = 2; i <= M/2 ; i++ )
                        if ( !(M % i) )
                                return 0;
        }
        return 1;
}



void isGoldbach(int M, int *passfail, int *prime1, int *prime2 )
{
 
/* inputs:
     M       -- integer to be tested
     
     return values:
          result
          This variable is given an initial value of '0'. If M pass the Goldbach
          test this value would be changed to '1'.
          In case 1 is returned,"info[0]" indicating the reason "M" passes the
          Goldbach test:
          *passfail = 1 if M < 3
          *passfail = 2 if M is odd
          *passfail = 3 if M is the sum of 2 primes
          In the case that 1 is returned and the reason is 3, then the 2 primes
          that sum to M will be returned in passfail[1] and passfail[2].
  */

       if (M < 3)//First test of the Goldbach, if the input is less than 3, passfail[0] is 1 and Goldbach test is successful
        {
                *passfail = 1;


        }
        else if ( isodd(M) ) //if the number is odd so it goes for second condition and passfail[0] (reason) is 2 and goldbach test is successful
        {
                *passfail= 2;


        }
        else if(!isodd(M)) // Goldbach shoud test to see if two prime number exist to satisfy the condition or not
        {
                int i;


                for ( i = 2; i <= (M/2); i++)
                {
                        if(isprime(i) && isprime( M-i))
                        {

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

//function for printing the results
void printResults(int N, int integers[N], int reason[N][3])
{

/* inputs:
     N          -- number of tested integers.
     integers[] -- This array contain tested integers.

     reason[]   -- This array shows the reason a number pass the Goldbach.
     prime1[]   -- If reason is'3', this the first prime number.
     prime2[]   -- If reason is'3', this the second prime number.

     This function prints out the input numbers and states the result for each.
     If the result is 1 for a number, the reason it satisfies the Goldbach test
     would also be printed, with the possible reasons being one of:
     is less than 3
     is odd
     is the sum of 2 primes.
     In the case that the reason is is the sum of 2 primes, then the 2 primes
     would also be printed.
*/
        system("clear \n");
        printf(" This is the result of Goldbach test  \n");
        printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
        printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n");

        printf(" input                Result\n");
        printf(" ------      -------------------------- \n\n");

        int i;
        for (i=0; i<N; i++)
        {
                if (reason[i][0] == 0) // in case the Goldbach test is not satisfied 
                {
                        printf ("M = %g   is not satisfied by Goldbach test \n", integers[i]);
                }
                else
                {
                        if ( reason[i][0] == 1 )
                                printf ("M = %d, is less than 3   (is Goldbach) \n", (int)integers[i]);
                        else if ( reason[i][0] == 2 )
                                printf ("M = %d, is odd           (is Goldbach) \n", (int)integers[i]);
                        else if ( reason[i][0] == 3 )
                                printf ("M = %d  = %d + %d        (the sum of primes, is Goldbach) \n", (int)integers[i], reason[i][1], reason[i][2] );
                        
                }
        }


}

