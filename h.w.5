!
! File Name: twave.F90
! Author: Pradeep Singh
! Date: 11/3/2017
! Purpose: To plot data for a time-shifted function f(x - ct) on [0,L]
! Description: - The program "twave.F90" takes input as strings (through command line) and
!                converts them into the double precision folating point values. And, in case
!                user didn't provide sufficent/correct input, an error message is displayed.
!
!              - Then, program computes the time-shifted grid points (xmct) and calls the
!                function funval() to calculate function value on those gird points.
!
!              - "twave.F90" opens the "data.t" file and writes the grid points and function
!                values at those grid points to it. Once writing is done, file is closed.
!
!              - Function funval() computes the function value for a given grid point (xx).
!
!              - funval() serves as a proxy for f(x) = sin(x); but it may also be redirected to
!                evaluate a different function by modifying the preprocessor macro and re-compiling
!                the program.

! Program usage is as:
!                      $ make
!                      $ ./twave tval c L
!                      $ gnuplot
!                      gnuplot> plot "data.t" w lines
!

program twave
implicit none

integer, parameter  :: ounit = 9, N = 100
integer             :: i, iostatus, count
double precision    :: xmct, xx, hh,yy, tval, c, L, funval
character(len=32)   :: argu

! examine number of command line args, check for correct number.
! if sufficient args are not provided, print the error message to user.
count = command_argument_count()
if (count .ne. 3) then
   print *, "error: sufficient arguments not provided"
   print *, "provide following arguments in below given format"
   print *, "$ ./twave tval c L"
  stop
end if

! processing for string arg -- convert to double precision floating point
call get_command_argument(1,argu)
read(argu,*) tval
print *, "double float conversion: ", tval

! processing for string arg -- convert to double precision floating pointcall get_command_argument(2,argu)
read(argu,*) c
print *, "double float conversion: ", c

! processing for string arg -- convert to double precision floating point
call get_command_argument(3,argu)
read(argu,*) L
print *, "double float conversion: ", L

! opening file "data.t"
open(ounit, FILE = "data.t", STATUS = "unknown", IOSTAT = iostatus)
if (iostatus /=0) then
  print *, "error: could not open 'data.t'file"
  stop
end if

hh=L/(N-1)  ! step size

! loop to calculate grid points (xx), time-shifted grid points (xmct)
! and function value at time-shifted grid points (yy).
do i=1,N
  xx= (i-1)*hh          ! grid points
  xmct = xx- c*tval     ! time-shifted grid points
  yy=funval(xmct)       ! compuitng function value at time-shifted grid points
  write(ounit,*)xx,yy   ! writing grid points and function value to a file
end do

close (ounit, STATUS = 'keep')   ! close the file

stop
end program twave

!-------------------------------------------------
! double precision function fnval(xx) -- evaluate a hardcoded function
!                                        at the domain value xx
!   params:
!              o xx -- double precision, grid point value
!   return value:
!              o yy -- double precision function value


double precision function funval(xx)
implicit none

double precision, intent(IN)  :: xx
double precision              :: yy
yy = FUNCHOICE(xx)

end function funval


