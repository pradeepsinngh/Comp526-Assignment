/* add3.c -- James Otto, 9/25/16 -- this program uses a function
        to add 3 numbers. but add() has no return value -- it uses
        an extra pointer param instead.
        but see original, add2.c

        C-language ALWAYS uses pass-by-value in function calls:
        the VALUE of any input parameter is copied to a local
        variable -- that's local to the function...               */


#include <stdio.h>

/* fn DECLARATION -- note DUMMY variables, so compare w/ fn DEFINITION
   below                                                                */
void add(float *dsum, float dvar1, float dvar2, float dvar3);

int main(void) {
  float aa, bb, cc, sum; // variables local to main()
  float *sptr = &sum;

// input...
  printf("please enter 3 numbers to add:\n");
  scanf("%f %f %f", &aa, &bb, &cc);

/* add the 3 numbers */
  add( sptr, aa, bb, cc);

  printf("%f + %f + %f = %f\n", aa, bb, cc, sum);

  return 0; //end main()
}

//----------------------------------------------------------------------

/* fn add() for adding 3 numbers -- function values passed "by value" so
                                 -- there is no side effect back in the
                                 -- calling fn, that is, in main().
    o input:
        0) sum:  float*, to write the sum to
        1) xx:  float, 1st number in sum
        2) yy:  float, 2nd number in sum
        3) zz:  float, 3rd number in sum

    o returns sum by way of 1st pointer param...                        */

  void add(float *sum, float xx, float yy, float zz) { //LOCAL variables,
                                            //so local to add()
   *sum = xx+yy+zz;
    return ;             // return from add()
}
