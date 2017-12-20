#! /usr/bin/perl

# 12/18/17 -- 


print "Content-type: text/html; charset=iso-8859-1", "\n\n";

#parse the string and extrct useful parameters
%query = &cgiparse();

#If not enough inputs, terminate is 1
$terminate = 0;

#Read key and their values
$user_entry = $query{"command"};	#user's function choice

if(!$user_entry){
	$user_entry="No function selected!";
	$funcomment = "Please select either sine, gaussian, or cubic functions.\n";
	$funparam = "Discarded parameters (if provided any)!";
	$terminate = 1;	#Prompt user for function
}
else{
	#Parameters for Sine function
	if($user_entry=="sine"){
		print("Inside sine extraction! \n\n");
		$L = $query{"sineL"};
		$funparam .= "L = $L";
		if($L<=0 || $L>10){
			$funcomment = "The value of L (string length) should be in range of 0 and 10.\n";
			$terminate = 1;
		}
	}
	#Parameters for Gaussian function
	elsif($user_entry=="gaussian"){
		print("Inside gaussian extraction! \n\n")
		$L = $query{"gaussianL"};
		if($L<=0 || $L>10){
			$funcomment = "The value of L (string length) should be in range of 0 and 10.\n";
			$funparam .= "L = " . "$L" . ", ";
			$terminate = 1;
		}
		$alpha = $query{"paramAlpha"};
		$funparam .= "alpha = " . "$alpha" . ", ";

		$beta = $query{"paramBeta"};
		$funparam .= "beta = " . "$beta" . ", ";
		if($beta<=0 || $beta>$L){
			$funcomment .= "The value of beta should be in range of 0 and L (string length), where L is less than 10.\n";
			$terminate = 1;
		}

		$sigma = $query{"paramSigma"};
		$funparam .= "and " . "sigma = " . "$sigma";
		if($sigma<=0){
			$funcomment .= "The value of sigma should be greater than 0.\n";
			$termiante = 1;
		}
	}
	#parameters for Cubic function
	elsif($user_entry=="cubic"){
		print("Inside cubic exxtraction! \n");
		$L = $query{"cubicL"};
		$funparam .= "L = $L, ";
		if($L<=0 || $L>10){
			$funcomment = "The value of L (string length) should be in range of 0 and L.\n";
			$terminate = 1;
		}

		$delta = $query{"paramDelta"};
		$funparam .= "and delta = $delta";
		if($delta<=0 || $delta>$L){
			$funcomment .= "The value of delta should be in range of 0 and L (string length), where L is less than 10.\n";
		}
	}
	#We should not encounter this condition!
	else{
		print("Something is wrong with the parameters!");
		$terminate = 1;
	}	
}

$funchoice = $user_entry;
print($funparam);
print($funcomment);
print("\n\n");
#If parameters are not correct, tell user to correct them and exit
if($terminate == 1){
	#do substitution
	substitute($funchoice, $funparam, "Suggestions! <br>" . $funcomment, "");
	#print("Suggestions! \n");
	#print("$funcomment");
	exit(0);
}

#Remove all previous png files stored and wave.gif file.
#Assuming that if .gif file exists then .png files also exist
#at their supposed location.
if (-e "results/png_images/wave.gif"){
	system("rm ./results/wave.gif");
	system("rm ./results/png_images/*.png");
	#print("File removed! \n");
}

$user_entry = "cubic";
$epochs = 200;	#Total 200 png images will be created
$dir_path = "results/png_images/";	#Dir where all png files are stored
$c = 1;	#Default value
$tval = 0.0;	#Default value

#User function choice is sine.
if($user_entry eq "sine"){
	$L = 2*3.28;
	#$tincr = 0.05;
	$incr = (2*$L/$c)/$epochs;	#Increment size
	#$tval = 0.0;	#Initial value
	print("In sine function!\n");
	for ($i=0; $i<5; $i++) {
	   $pngname = $dir_path . "wave" . "$i" . ".png";
	   system("gfortran -DFUNCHOICE=sine -DEXTEND=0 -o ./results/twave twave.F90 funval.F90");
	   system("./results/twave $tval $c $L");
	   system("gnuplot gnu.batch.template");	#calling gnu.batch file to create plot
	   system("mv wave.png $pngname");
	   $filelist .= "$pngname ";
	   $tval += $incr;
	}
}

#User function choice is gaussian.
elsif($user_entry eq "gaussian"){
	#Initial conditions
	$L = 10;
	$alpha = 2;
	$beta = 5;
	$sigma = 0.05;
	$incr = (2*$L/$c)/$epochs;
	print("In gaussain function! \n");
	for ($i=0; $i<$epochs; $i++) {
	   $pngname = $dir_path . "wave" . "$i" . ".png";
	   system("gfortran -DFUNCHOICE=gaussian -DEXTEND=1 -o ./results/twave twave.F90 funval.F90");
	   system("./results/twave $tval $c $L $alpha $beta $sigma");
	   system("gnuplot gnu.batch.template");	#calling gnu.batch file to create plot
	   system("mv wave.png $pngname");
	   $filelist .= "$pngname ";
	   $tval += $incr;
	}
}

#User function choice is cubic.
else{
	#Initial condition
	$L = 10;
	$delta = 5;
	$incr = (2*$L/$c)/$epochs;
	print("In cubic function! \n");
	for ($i=0; $i<$epochs; $i++) {
	   $pngname = $dir_path . "wave" . "$i" . ".png";
	   system("gfortran -DFUNCHOICE=cubic -DEXTEND=1 -o ./results/twave twave.F90 funval.F90");
	   system("./results/twave $tval $c $L $delta");
	   system("gnuplot gnu.batch.template");	#calling gnu.batch.template file to create plot
	   system("mv wave.png $pngname");
	   $filelist .= "$pngname ";
	   $tval += $incr;
	}
}

#Create .gif file
$loopparam = 5; #tell firefox how many times to iterate the gif animation
                #see "convert --help"
system("convert -delay 15 -loop $loopparam $filelist ./results/wave.gif");

#Write the findings in the results.html
#open(INFILE, "./results.html.template") 
#	or die("Make sure results.html.template file exists inside /waveqn/results/ folder. \n\n");

$fileContents = `cat results.html.template`;
#close(INFILE);	#Close the file

print ("$fileContents");
if($fileContents){
	print("\nfile content! \n\n");
}
else{
	print("No Filecontents \n\n");
}
exit(0);


# subroutine cgiparse() parses the contents of the cgi input into
# an associative array where the value of each name-value pair is stored
# using the name as the key.
#
# typical use:
#                %query = &cgiparse();
#                if (defined $query{'Name'} ) ....
#
# a string may be passed as a parameter for testing or if the cgi input
# has already been collected

  sub cgiparse {

      local ($data) = @_;

      # fetch the data for this request

      if ( defined $data ) {
           # we have data passed
      }
      elsif ( $ENV{'REQUEST_METHOD'} eq 'POST' ) {
	   # read it from standard input
           local ($len) = $ENV{'CONTENT_LENGTH'};
           if ( read (STDIN, $data, $len) != $len ) {
               die ("Error reading 'POST' data\n");
           }
      }
      else {
          # fetch from environment variable
          $data = $ENV{'QUERY_STRING'};
      }

      local (%qs) = ();        #resulting hash

      # the data is encoded as name1=val1&name2=val2 -- etc
      # first split on name/value pairs
      foreach $qs ( split ('&', $data) ) {
          # then split name and value
          local ($name, $val) = split ('=', $qs);
          # url decode and put in resultant hash array
          $name = &url_decode ($name);
          if (defined $qs{$name} ) {
              # multiple values -- append using \0 separator
              $qs{$name} .= "\0" . &url_decode ($val);
          }
          else {
              # store it
              $qs{$name} = &url_decode ($val);
          }
      }
      # and return it
      %qs;
  }


# subroutine url_decode() decodes url data

  sub url_decode {

      local ($s) = @_;

      # translate + to space, and %xx to the character code

      $s =~ tr/+/ /;
      $s =~ s/%([0-9A-F][0-9A-F])/pack("C",oct("0x$1"))/ge;
      $s;
  }


# substitute strings in result file
sub substitute {

	my ($funchoice, $funparam, $funcomment, $outputgif) = @_;	#Input parameters
	#$fileContents = `cat results.html.template`;

	print("$funchoice");
	print("$funparam");
	print("$funcomment");
	print("$outputgif");
	
	#Write the findings in the results.html
	open(INFILE, "results.html.template") or die("Make sure results.html.template file exists inside waveqn/ folder. \n\n");

	while (<INFILE>){
		s/FUNCHOICE/$funchoice/g;
		s/FUNPARAM/$funparam/g;
		s/FUNCOMMENT/$funcomment/g;
		s/OUTPUTGIF/$outputgif/g;
		print;
	}
	close(INFILE);
}
