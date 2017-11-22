#! /usr/bin/perl

# a program "search.pl" that implements grep-like usage
# to make this program better, have it search in a LIST of files

# it searches for 2 specific (hard-coded) string(s), "sdsu" and "SDSU"
# in a list of files specified on the command line

# we start by getting the program input from the command line

# previous    -- match.pl
# next        -- grep.pl

  $newline="\n";
# if the ARGV array has less than 1 element (is empty)
# then improper program usage -- the program name DOES NOT
# enter into command line args calculations in PERL...
  if ( @ARGV < 1 ) {
    print $newline;
    print("usage: search.pl file-list\n");
    print("usage: for example,  ./search.pl sdsu-story *.pl\n");
    print $newline;
    exit;
  }

  $string1  = "sdsu";
  $string2  = "SDSU";
  $ifiles = 0;  # count of files matched
  foreach $file (@ARGV) {
    $iflag = 0;  # did we hit in this file???
    open(INFILE, $file) or die "search.pl: $!";
    print(STDOUT "----------------------------------------------------\n");
    print(STDOUT "matches in file $file:\n");
# my line counter
    $ic = 1;
#   search the file for matches on the input string using $_
    while ( <INFILE> ) {
      if ( /$string1/ || /$string2/ ) {
        print(STDOUT "line $ic: $_");
        $iflag = 1;
      }
      $ic++;
    }
    
# remember list of files where we had a hit in an ARRAY @files
    if ($iflag == 1) {
      $files[$ifiles++] = "$file";  #build array element-wise
    }
    close(INFILE);
  }

# print where we found the strings:
  if ($ifiles > 0) {
    print(STDOUT "----------------------------------------------------\n");
    print("Summary:: there were matches in the files:\n");
    foreach $hit (@files) {
      print("$hit ");
    }
    print("\n");
    exit;
  }
  print("no matches were found in these files...\n");
  exit;

