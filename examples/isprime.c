/* isprime.c -- jim s. otto, 10-10-16
   tests numbers entered on the command line for primeness...
   demonstrates how to use the command line args argc and argv and
   the built-in conversion fn atoi(). and there is a nested loop
   structure.                                                       */

#include <stdio.h>
#include <stdlib.h> /* for atoi() -- converts strings to ints */

int main(int argc, char *argv[]) {

  int M, ii, kk, z;

/* argc comes in as the number of command line arguments -- saying the
   program name when you run program counts as 1 of the arguments...
   the arguments themselves are pointed to (as strings) by the elements
   of the pointer array argv[]... for example, argv[0] points to the
   program name... etc... (see below)                                    */
//  printf("argc= %d\n", argc);
  if (argc < 2) {
   printf("usage: $ isprime list-of-integers\n");
   return 0;
  }

/* loop over the command line args -- which come into the program as strings --
   and testing each one (as an integer) for primeness -- note, NESTED LOOP
   structure here (for-loop inside a for-loop)
                                                                        */
  for(ii=1; ii<argc; ii++) {
    M = atoi(argv[ii]); // ascii-to-integer conversion, C built-in fn
    if (M < 2) {
      printf("%d is not prime; 2 is the first prime...\n", M);
      continue;
    }

    /* brute force check for even factors...                            */
    for (kk=2; kk<=M/2; kk++) {
      z = M % kk; // does kk divide M?
      if (!z) {
        printf("%d is not prime: %d = %d x %d\n", M, M, kk, M/kk);
        M = 0;  //NOTE: this itself would terminate the for-loop, but ...
                //that's sort of obscure -- so let's explicitly break-out,
        break;  //explicit break-out...
      }
    } // else, no divisors...
    if (M) printf("%d is prime\n", M);
  }

  return 0;
}
~                                                                                                                                         
~                                                                                                                                     
