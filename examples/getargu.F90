 getargu.F90 -- James Otto, 11/25/19 -- test getting and conversion
!                of command line arguments in GNU Fortran
! to be run as:
!                    $ getargu chstring integer float
!
! where an attempt will be made to perform a conversion of each command
! line string to the indicated type respectively.

      program getargu
      implicit none

      integer             :: i, count, arg2
      double precision    :: arg3
      character(len=32)   :: argu

! examine number of command line args, check for correct number (see
! above)
      count = command_argument_count()
      if (count .ne. 3) then
        print *, "usage: $ getargu chstring integer dfloat"
        stop
      end if

! processing for char string arg
      call get_command_argument(1,argu)
      print *, "char string: ", argu

! processing for integer arg -- convert to integer
      call get_command_argument(2,argu)
      read(argu,*) arg2
      print *, "integer conversion: ", arg2

! processing for float arg -- convert to double precision
      call get_command_argument(3,argu)
      read(argu,*) arg3
      print *, "double float conversion: ", arg3

      stop
      end program getargu
