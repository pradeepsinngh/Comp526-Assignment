!
! DESCRIPTION -- this early program passes float arrays of
!                o N gridpoints
!                o N function evaluations
! to a subroutine for printing the pairs in gnuplot format
!
!      we use a level of INDIRECTION in the function call (see
!       fnval() ) for function evaluation to support changing the
!       function easily via re-compile -- the change should be made
!       in this fn
!
!      note: the DISTINCTION in F90 between subroutines and
!            functions -- we have to declare the latter as
!            "external" variables...
!
!      note: ".F90" -- it's important to use the EXACT
!        fortran 90 file extension -- to get the right
!        preprocessor handling...
!
! these are comments (!!)

! simple example program with a function call to print a function
! using gnuplot format

! some compilers force you to start statements after column 6...
! but not "gfortran" if you name your program with .F90 extension
! comments start with a "!"...

! reference in function afunx() -- modify the function choice
#define FUNC dsin

      program afunx
! we don't allow implicit type assignment for our variables, so
! state the type of EVERY variable and EVERY function
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
        xx(ii) = aa + (ii-1)*hh
        yy(ii) = FUNC(xx(ii))
      end do


 ! "call" to printer helper
      call printvals(NN, xx, yy)

      stop
      end program afunx
!-------------------------------------------------------------

!----------------------------------------------------------------------
! double precision function fnval(ax) -- evaluate a hardcoded function
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
      double precision function fnval(ax)
      implicit none

      double precision :: ax

! IMPORTANT -- double precision "fnval" come "for free" w/ the
!              function definition -- ie., as the NAME of the fn...

      fnval = FUNC(ax)   ! note, function call, so y = f(x)

! return "fnval", the sum
      return
      end function fnval
!--------------------------------------------------------------------
! subroutine printvals() -- print N grid and function values, for
!                           the N gridpoints input in array xx
!                           use gnuplot format
!    params:
!             o integer N -- the size of array xx       (in)
!             o double precision xx -- array of size N  (in)
!                 -- the domain values
!             o double precision yy -- array of size N  (in)
!                 -- the range values
     subroutine printvals(N, xx, yy)
     implicit none

     integer                       :: N, ii
     double precision, intent(IN)  :: xx(N)     ! NOTE-- parens here
     double precision, intent(IN)  :: yy(N)     ! NOTE-- parens here
     
     
     do ii=1,N
       print *, xx(ii), yy(ii)
     end do

     end subroutine printvals





