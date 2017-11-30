#! /usr/bin/perl

# a Perl program "substitute.pl".
# it opens a FILE named on the program command line and looks for
# occurrences of the fixed string "SDSU"; it echos lines from the
# file to STDOUT; if the line has a match, the match is substituted by
# the string "San Diego State University" -- but this program has a BUG.
# -- see substitute2.pl

# usage:
#
#    $ ./substitute.pl filename
#

# follows -- search.pl, grep.pl

  $newline = "\n";
  if ( $#ARGV != 0 ) {
    print $newline;
    print("usage: substitute.pl filename\n");
    print $newline;
    exit;
  }

  $filename = $ARGV[0];

  print(STDOUT "opening $filename...\n");

# here, "INFILE" is a filehandle of our choosing:
  open(INFILE, $filename) or die("Cannot read input file $filename: $!");

# assume the INFILE has "many" lines -- we don't know how
# many, so use a while() loop -- each iteration of the loop
# puts the next line of the file into $_ ...

  $target = "SDSU";
  $replacement = "San Diego State University";
  while (<INFILE>) {
# substitution happens by default wrt $_
     s/$target/$replacement/;
     print;
  }
# that's all folks...
