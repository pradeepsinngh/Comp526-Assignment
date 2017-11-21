Last login: Tue Nov 21 01:26:34 on ttys000
Pradeeps-MacBook-Pro:~ pradeepsingh$ ssh -l singh ophelia2.sdsu.edu
ssh: connect to host ophelia2.sdsu.edu port 22: Operation timed out
Pradeeps-MacBook-Pro:~ pradeepsingh$ ssh -l singh ophelia2.sdsu.edu
singh@ophelia2.sdsu.edu's password: 
Last login: Tue Nov 21 00:23:20 2017 from ip68-8-48-31.sd.sd.cox.net
[singh@ophelia2 ~]$ clear




























[singh@ophelia2 ~]$ cd assign6
[singh@ophelia2 assign6]$ ls
makefile  matvec  matvec.F90
[singh@ophelia2 assign6]$ make
gfortran -o matvec -lblas matvec.F90
[singh@ophelia2 assign6]$ ./matvec
 Please enter matrix dimension n (matrix A is nxn): 
831
 Time taken to compute matvecR() -- tR =  7.99900014E-03 seconds
 Time taken to compute matvecC() -- tC =  2.00000033E-03 seconds
 Time taken to compute  dgemv() -- tB =  9.98999923E-04 seconds
 ------------------------------------------------------------------------------
 Timing ratio for the row-based and column-based multiplication w.r.t dgemv() 
 ratR: tR/tB =   8.0070076    
 ratC: tC/tB =   2.0020025    
 Note: Ratio greater than one means that method is slower than dgemv() based multiplication
 --------------------------------------------------------------------------------
 The error in row-based multiplication method is: yR =    0.0000000000000000     
 The error in column-based multiplication method is: yC =    0.0000000000000000     
[singh@ophelia2 assign6]$ lear
-bash: lear: command not found
[singh@ophelia2 assign6]$ clear













[singh@ophelia2 assign6]$ vi matvec.F90
[singh@ophelia2 assign6]$ make
gfortran -o matvec -lblas matvec.F90
[singh@ophelia2 assign6]$ ./matvec
 Please enter matrix dimension n (matrix A is nxn): 
999
 Time taken to compute matvecR() -- tR =  1.59979984E-02 seconds
 Time taken to compute matvecC() -- tC =  2.99900025E-03 seconds
 Time taken to compute  dgemv() -- tB =  3.00000235E-03 seconds
 ------------------------------------------------------------------------------
 Timing ratio for the row-based and column-based multiplication w.r.t dgemv() 
 ratR: tR/tB =   5.3326621    
 ratC: tC/tB =  0.99966598    
 Note: Ratio greater than one means that method is slower than dgemv() based multiplication
 --------------------------------------------------------------------------------
 The error in row-based multiplication method is: yR =    0.0000000000000000     
 The error in column-based multiplication method is: yC =    0.0000000000000000     
[singh@ophelia2 assign6]$ vi matvec.F90
[singh@ophelia2 assign6]$ make
gfortran -o matvec -lblas matvec.F90
[singh@ophelia2 assign6]$ ./matvec
 Please enter matrix dimension n (matrix A is nxn): 
934 
 Time taken to compute matvecR() -- tR =  1.39980000E-02 seconds
 Time taken to compute matvecC() -- tC =  2.99999863E-03 seconds
 Time taken to compute  dgemv() -- tB =  1.99900195E-03 seconds
 ------------------------------------------------------------------------------
 Timing ratio for the Row and Column based multiplication w.r.t dgemv(): 
 ratR: tR/tB =   7.0024943    
 ratC: tC/tB =   1.5007483    
 Note: Ratio greater than one means that method is slower than dgemv() based multiplication.
 --------------------------------------------------------------------------------
 The error in row-based multiplication method is: yR =   0.0000000000000000     
 The error in column-based multiplication method is: yC =   0.0000000000000000     
[singh@ophelia2 assign6]$ vi matvec.F90
[singh@ophelia2 assign6]$ clear

[singh@ophelia2 assign6]$ make
gfortran -o matvec -lblas matvec.F90
[singh@ophelia2 assign6]$ ./matvec
 Please enter matrix dimension n (matrix A is nxn): 
934
 Time taken to compute matvecR() -- tR =  1.29979998E-02 seconds
 Time taken to compute matvecC() -- tC =  1.99999847E-03 seconds
 Time taken to compute  dgemv() -- tB =  1.99900195E-03 seconds
 ------------------------------------------------------------------------------
 Timing ratio for the Row and Column based multiplication w.r.t dgemv(): 
 ratR: tR/tB =   6.5022445    
 ratC: tC/tB =   1.0004985    
 Note: Ratio greater than one means that method is slower than dgemv() based multiplication.
 --------------------------------------------------------------------------------
 The error in row-based multiplication method is: yR =   0.0000000000000000     
 The error in column-based multiplication method is: yC =   0.0000000000000000     
[singh@ophelia2 assign6]$ clear














































[singh@ophelia2 assign6]$ exit
logout
Connection to ophelia2.sdsu.edu closed.
Pradeeps-MacBook-Pro:~ pradeepsingh$ ssh -l singh ophelia2.sdsu.edu
singh@ophelia2.sdsu.edu's password: 
Last login: Tue Nov 21 01:25:34 2017 from ip68-8-48-31.sd.sd.cox.net
[singh@ophelia2 ~]$ ls
assign1  assign2  assign3  assign4  assign5  assign6  examples.copy
[singh@ophelia2 ~]$ cd assign6
[singh@ophelia2 assign6]$ ls
makefile  matvec  matvec.F90
[singh@ophelia2 assign6]$ vi matvec.F90



















































!
! File Name: matvec.F90
! Author: Pradeep Singh
! Date: 11/18/2017
! Description: The program "matvec.F90" produces executable matvec via makeile to perform matrix-vector
!              multiplication y = Ax, for a n x n matrix A, represented in double precision.
!
!              Matrix vector product is calculated in 3 ways:
!                       o programmed row-based,
!                       o programmed column-based
!                       o column-based blas library
!
!             The user is prompted to enter the matrix dimensionn size n. Based on n, and subroutine loadvalues()
!             matrix A and vector x is initialized with floating values.
!
!             The time to perform matrix product is calculated and stored in tR, tC and tB. Using these timing, ratio
!             of timings of matvecR() and matvecC() w.r.t to timing of dgmev() is calculated. If ratio is greater than 1,
!             that means respective method is slower than dgemv().
!
!             Program also computes the correctness of row and col based multiplication methods by computing the difference
!             between dgemv() result and row/col based result. This result is stored in a vector (the error vector should
!             be approximately zero vector). Then, function infnorm() is used to compute the norms of error vector.
!
!             Error estimates, timings along with the ratios, ratR = tR/tB and ratC = tC/tB, is printed to STDOUT
!
!             Program usage is as:
!                                 $ make
!                                 $ ./matvec
!
! Below is the list of subroutines called within the main function
!
! SUBPROGRAM CALLS: matvecR(n,A,x,yR)
!                   matvecC(n,A,x,yC)
!                   dgemv('N',n,n,1.0d0,A,n,x,1,0.0d0,yB,1)
!                   laodvalues(n,A,x)
!                   infnorm(n,xx)
!
! Following variables are initialized and used the program
!
!    real timeStart and timeEnd -- used to compute times with cpu_time()
!    real tR, tC, tB -- time to complete row, column, and dgemv() respectively
!    integer n -- dimension of square matrix A
!    integer kk -- counter
!    integer astatus -- status
!    double precision A(:,:) -- A matrix
!    double precision x(:) -- x vector
!    double precision yR(:), yC(:), yB(:) -- results for row, column, dgemv
!    double precision infnorm -- infinity norm function

!-----------------------------------------------------------------------
! Program starts here
!-----------------------------------------------------------------------

program matvec
implicit none

! variable declaration
double precision, allocatable   :: A(:,:), x(:), yR(:), yC(:), yB(:)
integer                         :: n, kk, astatus
real                            :: timeStart, timeEnd, tR, tC, tB
double precision                :: infnorm
! prompt the user for the dimension (n) of the square matrix A
print *, "Please enter matrix dimension n (matrix A is nxn): "
read *,  n

!-------------------------------------------------------------------------
! Allocate
!--------------------------------------------------------------------------
! give the "matrix" and "vectors" some values and check for success or failure.

allocate(A(n,n),STAT=astatus)
if ( astatus .ne. 0) then
  print *, "failed to allocate matrix A"
  stop
end if

allocate(x(n),   STAT=astatus)
if ( astatus .ne. 0) then
  print *, "failed to allocate vector x"
  stop
end if

allocate(yR(n),   STAT=astatus)
if ( astatus .ne. 0) then
  print *, "failed to allocate vector yR"
  stop
end if

allocate(yC(n),   STAT=astatus)
if ( astatus .ne. 0) then
  print *, "failed to allocate vector yC"
  stop
end if

allocate(yB(n),   STAT=astatus)
if ( astatus .ne. 0) then
  print *, "failed to allocate vector yB"
  stop
end if

!--------------------------------------------------------------------------------------

! loading floating point values in the matrix A and vector x using subroutine loadvalues
call loadvalues(n, A, x)

!-------------------------------------------------------------------------
! Time for Mat-Vec Row based method
!--------------------------------------------------------------------------

call cpu_time(timeStart)                 ! start time  of matvecR() subroutine
call matvecR(n,A,x,yR)                   ! call matvecR -- row-based method
call cpu_time(timeEnd)                   ! end time of matvecR() subroutine
tR = timeEnd - timeStart                 ! compute difference in time
print *, "Time taken to compute matvecR() -- tR =", &
      timeEnd - timeStart, "seconds"

!------------------------------------------------------------------
! Time for Mat-Vec Col based method
!--------------------------------------------------------------------------

call cpu_time(timeStart)                ! start time  of matvecC() subroutine
call matvecC(n,A,x,yC)                  ! call column-based user method
call cpu_time(timeEnd)                  ! end time of matvecC() subroutine
tC = timeEnd - timeStart                ! compute difference in time
print *, "Time taken to compute matvecC() -- tC =", &
      timeEnd - timeStart, "seconds"

!------------------------------------------------------------------------
! Time for DGEMV()
!--------------------------------------------------------------------------

call cpu_time(timeStart)                ! start time of dgemv()

! dgemv() is predefined function supplied by the BLAS library for
! column-based matrix multiplication.
! arguments of the dgemv() is in accordance with the dgemv() defined in the library

call dgemv('N',n,n,1.0d0,A,n,x,1,0.0d0,yB,1)
call cpu_time(timeEnd)                 ! end time of dgemv()
tB = timeEnd - timeStart              ! compute time difference
print *, "Time taken to compute  dgemv() -- tB =", &
      timeEnd - timeStart, "seconds"


!-----------------------------------------------------------------------
! Print the time ratios
!-------------------------------------------------------------------------------------------

if (tB .eq. 0.0d0) then
  print *, "WARNING: looks like we have a zero timing result, maybe the problem size is too fine-grained"
else

! time ratio for row and column-based method w.r.t dgemv based method
  print *, "------------------------------------------------------------------------------"
  print *, "Timing ratio for the Row and Column based multiplication w.r.t dgemv(): "
  print *, "ratR: tR/tB =", tR/tB !ratio of matvecR() time over dgemv() time



