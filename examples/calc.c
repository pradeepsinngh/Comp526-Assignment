
/* calc.c -- J. Otto, 11/10/16 -- takes up where io3.c left off...
   in adding a SEQUENCE of numbers from STDIN -- a new control
   loop, and if-else clause...  next program -- calc2.c         */

#include <stdio.h>

int main(void) {

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

/* or: */

/* the "break" here breaks out of the nearest enclosing
   control loop, etc...                                  */
/* while (1) {
    end = scanf("%f", &fnum);
    if (end == EOF) {
      break;
    }
    fsum += fnum;
  }                                                      */

  printf("\nthe final sum= %f\n", fsum);

/* could be function call... */
  if (!icount) {
    printf("empty sum -- not printing an average.\n");
  } else {
/* "cast" integers to floating point values for the division */
    avg = fsum / ((float) icount);
    printf("the final average= %f\n", avg);
  }

/* return from main() */
  return 0;

------------------------------------------------------------------------------------
dyanamic1.c
-------------------------------------------------------------------------------------
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

