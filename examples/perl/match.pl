#! /usr/bin/perl


# a Perl program "match.pl" it opens a FILE named on the program command line and looks for
# occurrences of the fixed string "SDSU"; it prints any lines from the
# file that contain this match

# usage:
#
#    $ ./match.pl filename
#

# follows -- hello6.pl
# next    -- search.pl

  $newline = "\n";
  $matchstr = "SDSU";

# if the last index of the ARGV array is not 0 -- it's not the
# right size for proper usage -- the program name itself does
# not enter into command line calcs in PERL... in particular,
# see the little test program "test.pl"
  if ( $#ARGV != 0 ) {
    print $newline;
    print("usage: match.pl filename\n");
    print "\n";
    exit;                                 # exit program
  }

  $filename = $ARGV[0];

  print(STDOUT "opening $filename...\n");

# here, "INFILE" is a filehandle of our choosing:
  open(INFILE, $filename) or die("Cannot read input file $filename: $!");

# assume the INFILE has "many" lines -- we don't know how
# many, so use a while() loop -- each iteration of the loop
# puts the next line of the file into $_ ...

  $ith = 1;
  $matches = 0;
  while (<INFILE>) {
# matching happens by default wrt $_
     if (/$matchstr/) {
       $matches++;
       $line = $_;
        print ("line $ith: $line");
     }
     $ith++;
  }
  close(INFILE);
  print "$matches lines matched $matchstr in $filename\n";
# that's all folks...
