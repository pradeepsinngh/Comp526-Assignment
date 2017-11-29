#! /usr/bin/perl
#
# File Name: report.pl
# Author: Pradeep Singh
# Date: 11/22/2017
# Description: The program "report.pl" takes a filename and a sequence of
#              strings through command line and the prints a summary of hits on
#              string searches in the file.
#
#
#
# Program Usage:
#              $ ./report.pl filename str1 [str2...]
#
#
#
#

$newline="\n";

if ( @ARGV < 3 ) {
  print $newline;
  print("usage: ./report.pl filename str1 str2 ...");
  print("usage: for example, ./report.pl programming perl fortran ...");
  print $newline;
  exit;
}

$filename = $ARGV[0];
$string1  = $ARGV[1];
$string2  = $ARGV[2];

print $newline;
print(STDOUT "opening $filename... \n");

open(INFILE, $filename) or die "report.pl: $!";

print(STDOUT "---------------------------------------------------\n");
print(STDOUT "matches from perl search: \n");


foreach $line[$i] ( <INFILE> ) {
  chomp($line = $_);
  @lines = split('\n',$filename);
  $line[$i] = $line[Si] + 1;
}

$icount = 0;
$outstring = "";

for ($i=0; $i < $numlines; $i++) {
  $_ = $lines[$i];
  if /$string1/ {
    $blah = "line" .$i.":";
    $outstring .=$blah.$_;
    $icount++;
  }
}


