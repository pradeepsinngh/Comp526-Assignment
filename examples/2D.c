/* 2D.c -- James Otto, 10/9/17 -- program to demonstrate the
           syntax of 2D arrays -- aggregate 2 1D arrays of student
           data into a single 2D array w/ 2 rows, studata[2][N].

           then pass the 2D array to a special function designed
           for printing student data.                            */

#include <stdio.h>

/* prototype for fn that prints student data */
void printdata(int nstuds, int studata[][nstuds]);

int main(void) {
  int redids[7] = {801, 824, 889, 806, 811, 912, 856}; //
  int msats[7]   = {550, 611, 600, -1, 590, 581, -1};  // -1 means missing data
  int ii, nstuds=7;
  int studata[2][7]; // 2D array -- 2 rows, 7 cols

/* aggregate the student data into the 2D array */
  for (ii=0; ii<7; ii++) {
    studata[0][ii] = redids[ii];
    studata[1][ii] = msats[ii];
  }

/* call a helper routine on the aggregted data */
  printdata(7, studata);

  return 0;
}

/* void printdata(nstuds, studata)
          input:
                    o int nstuds -- number of students with records
                    o int studata-- 2d array with 2 rows and nstuds cols
                       containing
                     -- student ids in 1st row
                     -- math scores in 2nd row*
          output: none
          * a math score of -1 flags a missing grade

          prints student data to standard out, 1 line per student      */

void printdata (int nstuds, int studata[][nstuds]) {
  int ii;
  int iflag=0; //flag the number of students w/ missing scores

  for (ii=0; ii<nstuds; ii++) {
if (studata[1][ii] != -1) {
       printf("student %d had a math score of %d\n", studata[0][ii], studata[1][ii]);
     } else {
       iflag++;
     }
  }
  if (iflag) {
    printf("%d students had missing math scores\n", iflag);
  }
  return;
}

