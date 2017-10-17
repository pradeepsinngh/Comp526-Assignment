* iseven.c -- James Otto, 10/17/17 -- code to demo use of "return-by-reference"
               function, in a loop, to load data into an array
               -- the "r-b-r" function here is

              void isEven(int *tf, int test)

              which tests the 2nd param for even-ness, passing back the result
                      via the 1st param.

              NOTE: the program structure here serves as mini prototype for
              the isgoldbach C program.                                        */

#include <stdio.h>
#define FIRST 1

void isEven(int *tf, int test);                //test fn decl
void printresults(int size, int data[][size]); //display fn decl

int main(void) {
  int data[2][5] = { {100, 5, 3415, 222, 99},    //1st row: ints to be tested for evenness
                     {  0, 0,    0,   0,  0} };  //2nd row: will be 1/0 -- the test results
  int i, tf, test;

/* test the 1st row, storing result in 2nd row... */
#if FIRST
  printf("using FIRST loop...\n");
  for (i=0; i<5; i++) {
     test = data[0][i];
     isEven(&tf,test);
     data[1][i] = tf;
  }
#else
/* alternatively,                          */
  printf("using ALT loop...\n");
  for (i=0; i<5; i++) {
     isEven(&data[1][i],data[0][i]);
  }
#endif

/* print the results */
  printresults(5, data);

  return 0;
}

/* isEven -- test an integer for evenness
        params:
            int *tf -- pointer used to return 1/0: 1 --> yes, it's even
                                                   0 --> no, it's odd
            int test -- integer to be tested                              */

void isEven(int *tf, int test) {
*tf = 1 - (test % 2);
  return;
}

/* printresults -- display results for even integer test results data structure
        params:
              int size          -- number of columns of data array
              int data[2][size] -- array: 1st row is test ints
                                          2nd row is test result -- 1/0 evenness flag  */
void printresults(int size, int data[][size]) {
  int i;
  char *evenstrings[2] = { "odd", "even" };
  for (i=0; i<size; i++) {
    printf("integer %d is %s\n", data[0][i], evenstrings[data[1][i]]);
  }
  return;
}



