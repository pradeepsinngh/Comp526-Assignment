! twave.F90 -- Shivam Garg, 12/18/2017 --
!
!			This program requires three double precision inputs ('tval', 'c', and 'L').
!			These variables are used to shift the function values using the formula:
!				xmct = x-c*tval, over the interval of [0,L].
!				xpct = x+c*tval, over the interval of [0,L].
!
!			The program twave calls external function 'funval' which choses FUNCHOICE 
!			to operate on the values (i.e. xmct and xpct). The funval file is located 
!			inside /usr/local/apache/cgi-bin/garg/waveqn/ folder.
!
!			The FUNCHOICE is modified in the driver.cgi file which is located inside 
!			/usr/local/apache/cgi-bin/garg/waveqn/ folder.
!			To run the twave.F90 program, driver.cgi follows these commands:
!				gfortran -DFUNCHOICE=sine -DEXTEND=0 -o ./results/twave twave.F90 funval.F90
!				./twave tval c L
!
!			twave.F90 can also be run independently if above two commands are typed on 
!			the console.

!			Currently, twave.F90 supports three different types of function: sine, 
!			gaussian, and cubic. For gaussian and cubic functions, use -DEXTEND=1.
!				gfortran -DFUNCHOICE=gaussian -DEXTEND=1 -o ./results/twave twave.F90 funval.F90
!
!			The output of this program is stored in the 'data.t' file which can also be
!			found in the /usr/local/apache/cgi-bin/garg/waveqn/ folder. This file contains 
!			150 GRIDPOINTS and their corresponding values obtained by operating FUNCHOICE 
!			function on those GRIDPOINTS. 
!			One can plot these points using gnuplot by following these instructions:
!				gnuplot
!				plot 'data.t' w lines
!
!			See also	o driver.cgi
!					o funval.F90
!
!----------------------------------------------------------------------------------------------

!Starting program twave which expects three (double precision type) inputs from the user through 
!the command line. This program writes the float values in the 'data.t' file.
program twave
	implicit none
	
	!This program (twave) calls the external function (funval)
	double precision, external	:: funval
	integer				:: GRIDPOINTS = 100, ii = 0, tot_args = 0	!Initialization
	integer				:: outunit=9, iostatus	!Used in File opening
	double precision       		:: tval, c, L	!These variable stores the three inputs
	double precision		:: alpha, beta, sigma, delta	!Variables for gaussian/cubic functions
	double precision		:: a=0.0d0, hh		!Used in calculating step size for the interval
	double precision		:: xx, xmct, xpct, yy	!Stores function values
	character(len=10)       	:: argu	!Reads command line input in string format
	common /Default/ L	!Any function (within this program) can access it
	common /Func2/ alpha, beta, sigma	!Used in gaussian function
	common /Func3/ delta	!Used in cubic function

	!If the number of inputs is less than 3, exit the program
	tot_args = command_argument_count();
	if(tot_args .lt. 3) then
	 print *, "Mismatch in total number of input arguments and total number of expected input arguments."
	 write (*,*) "For sine function, usage is: $./twave tval c L"
	 write (*,*) "For gaussian function, usage is: $./twave tval c L alpha beta sigma"
	 write (*,*) "For cubic function, usage is: $./twave tval c L delta"
	 write (*,*) "Refer to driver.cgi file for more information."
	 stop
    	end if

	!Command line arguments
	call get_command_argument(1,argu)
	read(argu,*) tval		!Converting the argument to double precision
	!print *, "First argument: ",tval;
	
	call get_command_argument(2,argu)
	read(argu,*) c		!Converting the argument to double precision
	!print *, "Second argument: ", c;

	call get_command_argument(3,argu)
	read(argu,*) L		!Converting the argument to double precision
	!print *, "Third argument: ", L;

	!If 6 command line arguments, then FUNCHOICE must be gaussian
	if(tot_args .eq. 6) then
	 call get_command_argument(4,argu)
	 read(argu,*) alpha	!Converting the argument to double precision
	 !print *, "Fourth argument (alpha) : ", alpha;
	
	 call get_command_argument(5,argu)
	 read(argu,*) beta	!Converting the argument to double precision
	 !print *, "Fifth argument (beta) : ", beta;
	
	 call get_command_argument(6,argu)
	 read(argu,*) sigma	!Converting the argument to double precision
	 !print *, "Sixth argument (sigma) : ", sigma;
	
	!If 4 command line arguments then FUNCHOICE must be cubic
	else if(tot_args .eq. 4) then	
	 call get_command_argument(4,argu)
	 read(argu,*) delta	!Converting the argument to double precision
	 !print *, "Fourth argument (delta) : ", delta;

	end if

	!Opening the file 'data.t'
	open(outunit, FILE="./results/data.t", STATUS="UNKNOWN", IOSTAT=iostatus)
	if(iostatus /= 0) then
	 print *, "Error in opening the 'data.t' file."
	 stop
	end if

	!Calculating the step size
	hh = (L-a)/dfloat(GRIDPOINTS-1)
	!print *, "hh",hh
	
	!Calculating the gridpoints, its shifted value, and the function value
	xx = a
	do ii = 1, GRIDPOINTS	!Looping for all GRDIPOINTS
	 xmct = xx - c*tval
	 xpct = xx + c*tval
	 !print *, "i = ", ii, "x = ", xx, "xmct = ", xmct, "xpct = ", xpct
	 yy = (funval(xmct,L)+funval(xpct,L))/2	!Calculating the function value of the shifted gridpoint
	 write (outunit, *)xx, yy	!Writing in the file
	 xx = xx + hh		!Calculating next gridpoint value
	end do
	
	close(UNIT = outunit, STATUS = 'keep')	!Closing the 'data.t' file
	!print *, "Please check 'data.t' file for the output."
	
	stop	
	end program twave	!Closing the program twave

!When FUNCHOICE=sine, funval calls this function. This function calculates 
!and returns sin(3*pi*x/L) value for any given input value x.
double precision function sine(xx)
	implicit none

	double precision		:: xx	!Input value
	double precision		:: yy	!Output value
	double precision		:: L	!Stores the period
	real, parameter			:: pi = 3.1415	!Pi value
	common /Default/ L	!Period L. Common variable

	yy = dsin(3*pi*xx/L)

	end function sine	!Closing the function sine


!When FUNCHOICE=gaussian, funval calls this function. This function calculates 
!and returns value yy for any given input value xx.
double precision function gaussian(xx)
	implicit none
	double precision		:: xx	!Input value
	double precision		:: yy	!Output value
	double precision		:: L	!Stores the period
	double precision		:: alpha, beta, sigma	!Additional parameter
	common /Default/ L	!Period L
	common /Func2/ alpha, beta, sigma	!Additional variables

	yy = alpha*exp(-((xx-beta)**2)/(2*(sigma**2)));
	
	end function gaussian	!Closing the function gaussian


!When FUNCHOICE=cubic, funval calls this function. This function calculates 
!and returns value yy for any given input value xx.
double precision function cubic(xx)
	implicit none
	double precision		:: xx	!Input value
	double precision		:: yy	!Output value
	double precision		:: L	!Stores the period
	double precision		:: delta!Additional parameter
	common /Default/ L	!Period L
	common /Func3/ delta	!Additional variables

	yy = xx*(xx-delta)*(xx-L);
	
	end function cubic	!Closing the function cubic
