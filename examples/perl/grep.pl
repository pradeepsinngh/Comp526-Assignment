#! /usr/bin/perl

# a program "grep.pl" that implements grep-like usage in a couple of ways...
# to make this program better, have it search in a LIST of files

# follows -- search.pl
# next    -- args.pl

# we start by getting the program input from the command line

  $newline="\n";
  if ( $#ARGV != 1 ) {
    print $newline;
    print("usage: grep.pl search-string filename\n");
    print("usage: for example,  grep.pl localhost /etc/hosts\n");
    print $newline;
    exit;
  }

  $string   = $ARGV[0];
  $filename = $ARGV[1];

  print $newline;
  print(STDOUT "opening $filename...\n");

  open(INFILE, $filename) or die "grep.pl: $!";

  print(STDOUT "----------------------------------------------------\n");
  print(STDOUT "matches from perl search:\n");

# my line counter
  $ic = 1;
# search the file for matches on the input string using $_
# printing any lines that contain a HIT
  while ( <INFILE> ) {
    if ( /$string/ ) {
      print(STDOUT "line $ic: $_");
    }
    $ic++;
  }

  close(INFILE);

# alternatively:
  print(STDOUT "----------------------------------------------------\n");
  print(STDOUT "matches from system grep:\n");

  $results = `grep $string $filename`;
  print(STDOUT "$results");
  print(STDOUT "----------------------------------------------------\n");

  print $newline;
 
