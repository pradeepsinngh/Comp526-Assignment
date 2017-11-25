!
! Name: twave.F90
! Author: Pradeep Singh
! Date: 11/3/2017
! Language: Fortran
! Purpose: To plot data for a time-shifted function f(x - ct) on [0,L]
! 

program twave

implicit none

  character(len=32)               :: argu
  integer, parameter              :: NN = 100
  integer                         :: ii
  double precision                :: tval, c, L
  double precision                :: aa, bb, pi, hh
  double precision, dimension(NN) :: xx, yy
  double precision, external      :: funval

! examine number of command line args, check for correct number 
  count = command_argument_count()
  if (count .ne. 3) then
    print *, "usage: $ getargu dfloat dfloat dfloat"
    stop
   end if

! processing for float arg -- convert to double precision
   call get_command_argument(1,argu)
   read(argu,*) tval
   print *, "double float conversion: ", tval

! processing for float arg -- convert to double precision
   call get_command_argument(2,argu)
   read(argu,*) c
   print *, "double float conversion: ", c

! processing for float arg -- convert to double precision
   call get_command_argument(3,argu)
   read(argu,*) L
   print *, "double float conversion: ", L
  
  aa = 0.0d0           ! double precision zero !!
  pi = dacos(-1.0d0)   ! more of the same...
  bb = L
  hh = (bb-aa)/dfloat(NN-1)
  
  do ii=1,NN
    xx(ii) = aa + (ii-1)*hh
  end do

! heads up -- F90 array indexing starts w/ 1 (!!)
  do ii=1,NN
    xmct = xx(ii) - c * tval
    yy(ii) = funval(xmct)
  end do
  
 ! "call" to printer helper
  call funval(NN, xx, yy)

  stop
end program twave

!----------------------------------------------------------------------
! double precision function funval(ax) -- evaluate a hardcoded function
!                                        at the domain value ax
!   params:
!              o ax -- double precision point of fn evaluation (in)
!   return value:
!              o fnval -- double precision function value

double precision function funval(xx)
  implicit none

  double precision, intent(IN) :: xx

! IMPORTANT -- double precision "funval" come "for free" w/ the
!              function definition -- ie., as the NAME of the fn...

  yy = dsin(xx)
  print *, xx, yy

! return "fnval", the sum
  return
end function funval
!--------------------------------------------------------------------

! that's all folks
