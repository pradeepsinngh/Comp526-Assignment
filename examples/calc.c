
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

}
