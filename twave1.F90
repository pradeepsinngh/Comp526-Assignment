!
! Name: twave.F90
! Date: 11/2/2017
! Author: Pradeep Singh
! Purpose:
! Discription:

program twave

implicit none

  character(len=32)               :: argu
  integer, parameter              :: NN = 100
  integer                         :: ii
  double precision                :: tval, c, L, xmct
  double precision                :: aa, bb, pi, hh
  double precision, dimension(NN) :: xx, yy
  integer                         :: count
  double precision, external      :: funval

! examine number of command line args, check for correct number
  count = command_argument_count()
  if (count .ne. 3) then
    print *, "usage: $ twave dfloat dfloat dfloat"
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

  do ii=1,NN
    xmct = xx(ii) - c * tval
    yy(ii) = funval(xmct)
  end do

  open(unit=1, file="data.t", action="write", status="new")
  do ii=1,NN
    write(unit=1,fmt="(3(F10.7,1x))") xx, yy
  end do

  stop

stop
end program twave

!----------------------------------------------------------------------
double precision function funval(xx)
  implicit none

  double precision, intent(IN) :: xx
  double precision             :: yy

  yy = FUNCHOICE(xx)

  return
end function funval
!-------------------------------------------------------------------


