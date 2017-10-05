/*
 * File Name: plot.c
 * Author: Pradeep Singh
 * Date: 10/1/2017
 * Language: C
 * Purpose: To plot derivative of a function
 * Description: - The program generate data for plotting the approximate
                  derivative of a function.

                - Derivative is computed using Taylor's central difference formula,
                  which is defined in a function called "fprime".

                - The main() function computes a grid and performs base function
                  evaluation for that grid. Then it passes the function
                  evaluated values to fprime() for computing it derivatives.

                - Subsequently, main() calls a function printfnvals() to
                  print the grid and function values of the derivative.

                - The only user-supplied run time choice is the filename
                  provided on the command line, where "filename" is the
                  name of a file, or possibly "stdout".

                - Program usage is as,
                  Step 1 - $ make                            // complie code
                  Step 2 - $ ./plot filename (or) ./plot stdout
                  Step 3 - $ gnuplot                         // open gnuplot
                  Step 4 - gnuplot> plot "filename" w lines  // plot using gnuplot
*/

/* Following header files are included */

#include<stdio.h>                // for printf() and fprintf()
#include<math.h>                 // for built-in math functions
#include<string.h>               // for string comparisons

/* Macros definition */

#define FNCHOICE cosf           // Candidate base function selection.
                                // It can be also changed to "sinf" or "quadratic"
#define FNSTRING "cosf"         // Function choice in string format
#define GRIDPOINTS 100          // Total number of gridpoints


/* Declaring function named fprime.
 * This function calculates derivative of the chosen function.
 */

void fprime(int size, float hh, float fvals[], float fpvals[]);

/* Declaring function named printfnvals.
 * This function prints the grid points and the derivative values
 * of the chosen function at those grid points.
 */

void printfnvals(FILE *fptr, int nvals, float xvals[], float yvals[]);

/* Declaring function named quadratic.
 * This function calculates quadratic value of the input value.
 */

float quadratic(float x);

/* The main() begins here */

int main(int argc, char *argv[]){

  int ii;                    // int variable to count number of times loop will run
  FILE *fptr;                // initializing file pointer
  int N = GRIDPOINTS-1;      // N is the number of grid points on the axis
  float xx[GRIDPOINTS];      // array "xx" will have grid values (domain values)
  float yy[GRIDPOINTS];      // array "yy" will have function values at respective grid point
  float zz[GRIDPOINTS];      // array "zz" will have derivative values at respective grid point
  float a,b;                 // a and b are interval values and are dependent on function
  float hh;                  // hh is the step size, it dependes on a, b and N

/* Domain limit/interval, which is dependent on the selected base function.
 * If the base function is cosf or sinf, then interval is [a,b] = [0,2*pi]
 * and if the base function is quadratic, then interval is [a,b] = [-1,1]
 */

  a = 0.0;                  // for sinf or cosf
  b = 2.0*M_PI;             // M_PI is the standard definition of "pi" defined in math.h

  if (!strcmp(FNSTRING,"quadratic")){  // if the base function is quadratic
    a = -1.0;
    b = 1.0;
  }

/* interval [a,b] is divided into N equal subintervals of length h = (b-a)/(N) */
  hh = (b - a)/(float)(N-1);      // step size

/* This for loop does two things. Firstly, it computes the grid values
 * and then it calculates the function values on the respective grid values.
 */

  for(ii=0; ii<=N; ii++){      // counter "ii" runs from 0 to N
    xx[ii] = a + ii*hh;        // array "xx" gets grid values
    yy[ii] = FNCHOICE(xx[ii]); // array "yy" gets function values at each grid point
  }

/* Getting derivative values from function fprime */

  fprime(GRIDPOINTS, hh, yy, zz);   // Storing the derivative values


/* Processing the command line args to figure out where to write the results */
   if (argc != 2) {
     printf("usage: plot filename\n");
     printf("where \"filename\" is the name of a file to write the results to\n");
     printf("in case \"stdout\" is given the results are written to STDOUT\n");
     return 0;
   }

   if (!strcmp(argv[1],"stdout")) {
     fptr = stdout;                // output on the console
   } else {
       fptr = fopen(argv[1], "w");  // try to open given file for writing
       if (!fptr) {
         printf("could not open %s for writing\n", argv[1]); //open failed
         return 0;
       }
     }

/* This function is used to display the result on console (using STDOUT)
 * or to write on a file (eg: "data.out") depending on user choice.
 */

   printfnvals(fptr, GRIDPOINTS-2, &xx[1], &zz[1]);   // Passing the arguments

return 0;          // return 0;
}                  // end of main function

/* This function calculates and returns the derivative value
 * function: void fprime(int size, float hh, float fvals[], float fpvals[])

         int size             -- the size of the gridpoints
         float hh             -- step size
         float fvals[size]    -- floating point function values (input)
         float fpvals[size-2] -- floating point derivative values (output)
*/

void fprime(int size, float hh, float fvals[], float fpvals[]){

  int ii;    // initializing integer variable to count number of times loop will run

  for(ii=1; ii<size-1; ii++){     // for loop to calculate derivative at iith index
     fpvals[ii] = (float)(fvals[ii+1]-fvals[ii-1])/(float)(2.0*hh);  // Taylor's approximation formula
  }
}


/* This function prints grid points and their derivative values in the file
 * function: void printfnvals(FILE *fptr, int nvals, float xvals[], float fpvals[])

         FILE *fptr      -- Pointer to filename for displaying output
         int nvals       -- the size of the interior gridpoints
         float xvals[]   -- point to the address of second index of gridpoint (input)
         float fpvals[]  -- point to the address of second index (output)
 */

void printfnvals(FILE *fptr, int nvals, float xvals[], float fpvals[]){

  int ii;    // Initalizing integer variable to count number of times loop will run

  for(ii=0; ii<nvals; ii++){
     fprintf(fptr, "%0.2f %0.2f \n", xvals[ii], fpvals[ii]);   // Writing in the file
  }
}

/* This function calculates the quadratic value for the given input */

float quadratic(float xx){
  return xx*xx;      // return the computed value
}

// that's all folks
