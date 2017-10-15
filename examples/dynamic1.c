* dynamic2.c -- James Otto, 9/28/15. based on a previous program, sinx.c --
                for plotting a built-in fn using gnuplot -- variations on sin(x) are
                possible, depending on which of the hardcoded functions is
                actually called (see the #define FUN macro...).

                this version uses 1D arrays which are allocated dynamically (based
                on user input of grid size) using so-called allocation on "the heap",
                that is by way of function call stack frames... but this has its
                problems... in particular unexpected code crashes are to be
                EXPECTED... !!

             compute function values on the interval [a,b] and print the
             results in gnuplot format, ie, as

                x0 y0
                x1 y1
                x2 etc,

             one coordinate pair per line of the output file

             a subsequent code, dynamic2.c -- uses "allocation on the heap"   */

#include <stdio.h>
#include <math.h>   // for sin()
#include <errno.h>  // for perror()

/* remember to link in the math library:
     $ gcc -o dynamic1 dynamic1.c -lm                */

#define FUN f1  //string substitution PRIOR to compile...alternatively, f2...

/* user defined variations on the sine function */
float f1(float z);
float f2(float x);
void work(int N);

/* helper fn for printing to a file */
void printvals(FILE *ofile, int N, float dvals[], float fvals[]);

int main(void) {
   int N;

/* prompt the user for the grid size */
  printf("please enter N the number of grid subintervals -- this\n");
  printf("determines the granularity for fn plotting: ");

/* read the value from STDIN -- note variation on scanf() */
  fscanf(stdin, "%d", &N);

/* all the WORK is done in this helper function -- a mechanism (with drawbacks)
   for "dynamic" allocation of storage arrays... it works, but...              */
  work(N);        // called w/ number of subintervals...
   return 0;       // return from main()
}


//---------------------------------------------------------------------------
//void work(int N) -- N is the number of grid subintervals -- in particular
//                    there are N+1 gridpoints x0 thru xN...
void work(int N) {
  int ii;
  float aa, bb, hh;
  int M=N+1;
  float dvals[M], fvals[M];  //herein lays the DANGER -- so if allocation
                             //fails when this function is called...

/* ofile is file pointer or "file handle" */
  FILE * ofile;

/* name of disk file for output of fn values */
  const char *ofname = "sindata";

/* define the working interval, which we'll discretize using N+1 points,
   aa=x0 thru xN=bb                                                      */
  aa = 0.0;
  bb = 2.0*acos(-1.0); //inverse cosine for accurate "pi" value

/* open sine data file for writing -- check for success...*/
//  ofile = fopen("sindata", "w");
  ofile = fopen(ofname, "w");
  if (!ofile) { // see "man perror()"...
    perror("something bad...");
    return;
  }

   printf("results for %d gridpoints will be written to the file \"%s\"\n", N+1, ofname);

/* start at the left endpoint -- there are N+1 points total,
   namely x0 thru xN -- in which case the interval [a,b] is
divided into N equal subintervals of length h=(b-a)/N      */
  hh = (bb-aa)/(M-1);

/* step through the gridpoints left to right performing the
   required function evaluations                              */
  for (ii=0; ii<M; ii++) {
    dvals[ii] = aa + ii*hh;
    fvals[ii] = FUN(dvals[ii]);
  }

  printvals(ofile, M, dvals, fvals);
  return;                              //end main()

  return;
}

//------------------------------------------------------------------------
/* f1() and f2() -- helper functions for function evaluation, one possible
   variation on the function to be plotted. each takes a float as input
   and return a float, the function evalutated at the input value           */

float f1(float x) {
  return 2.0* (float) sin(x);
}

/* a helper function for function evaluation, a 2nd
   variation on the function to be plotted                */
float f2(float x) {
  return (float) sin(2.0*x);
}

//---------------------------------------------------------------------------
/* printvals() -- helper fn for printing domain and fn values for gnuplot

        o file *ofile is an open file handle for the output
        o int N is how many fn values
        o float dvals[] contains the N domain values to be printed
        o float fvals[] contains the N fn values to be printed      */

void printvals(FILE *ofile, int N, float dvals [], float fvals[]) {
  int ii;
  for (ii=0; ii<N; ii++) {
    fprintf(ofile, "%f %f\n", dvals[ii], fvals[ii]);
  }
}

