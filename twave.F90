!
! Name: twave.F90
! Author: Pradeep Singh
! Date: 11/3/2017
! Language: Fortran
! Description:
!



! Program usage is as -


program twave

implicit none

  integer, parameter              :: NN = 100
  integer                         :: ii
  double precision                :: aa, bb, pi, hh
  double precision, dimension(NN) :: xx, yy
  double precision, external      :: fnval


  aa = 0.0d0           ! double precision zero !!
  pi = dacos(-1.0d0)   ! more of the same...
  bb = 2.0d0*pi
  hh = (bb-aa)/dfloat(NN-1)

! heads up -- F90 array indexing starts w/ 1 (!!)
  do ii=1,NN
    xmct = xx - c* tval
    yy = funval(xmct)
  end do


 ! "call" to printer helper
   call funval(NN, xx, yy)

 stop
 end program twave
!-------------------------------------------------------------

!----------------------------------------------------------------------
! double precision function funval(ax) -- evaluate a hardcoded function
!                                        at the domain value ax

! this is VERY different from a C-language function. fortran
! has always used PASS-BY-REFERENCE by way of implicit ptrs
! to function and subroutine parameters.. so notice that
! "ax" and "bx" here are NOT strictly LOCAL...
!  .....................program accordingly!
!
! NOTE: again, with the explicit type-ing -- "implicit none"
!       below
!   params:
!              o ax -- double precision point of fn evaluation (in)
!   return value:
!              o fnval -- double precision function value
double precision function funval(xx)
  implicit none

  double precision, intent(IN) :: xx

! IMPORTANT -- double precision "funval" come "for free" w/ the
!              function definition -- ie., as the NAME of the fn...


! return "fnval", the sum
  return
end function funval
!--------------------------------------------------------------------
