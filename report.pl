#! /usr/bin/perl
#
# File Name: report.pl
# Author: Pradeep Singh
# Date: 11/22/2017
# Description: The program "report.pl" takes a file and sequence of strings through command line
#              and then prints a summary of hits on string searches in the file.
#
#              Program begins with checking number of command line arguments; it gives usage information
#              and terminates in case a usage problem is detected, following which user is prompted with
#              error messgae.
#
#              First input argument is stored as "filename" and rest all are stored as "strings" to be searched
#              in a array. Then, program attempts to open the file (given as first argument) for reading and
#              reports and terminates if a problem is encountered.
#
#              Then file is searched line by line using for-loop for given string, this is done for all the string.
#              If string is matched in a line, then that line is stored along with line number and total number of matches.
#
#              Then, program prints a short report for each string passed through command line in following order:
#              the string name, the number of lines that contain the string, and each line (with it's line numbner)
#              containg the string.
#
#              Program is made executable using following command:
#                           $ chmod u+x report.pl
#
#              Program Usage:
#                           $ ./report.pl filename string1 string2 string3 ...
#
#===========================================================================
# Program starts here
#===========================================================================

# We begin with checking number of command line arguments.
# And, print the total number of arguments.

$newline= "\n";

$numargs = @ARGV;      #Total input arguments
print $newline;
print("Total number of arguments: $numargs\n");

# Check the number of program command line arguments.
# Give usage info and terminate in case a usage problem is detected.

$newline= "\n";
if ($numargs < 2) {     # if less than 2 arguments are passed, display this message
   print $newline;
   print("Program terminated. Usage problem is detected!\n");
   print("Check the number of arguments and pass them in following manner.\n");
   print("Usage: for example, ./report.pl filename string1 string2 string3 ...\n");
   print $newline;
   exit;
}

# Storing program command line arguments.
# First input argument is taken as "filename" and remaining are taken as search strings.

$i = 0;                         # line counter
my @strings_to_search = ();     # array to store string's

foreach $argument (@ARGV) {
   if ($i == 0){                # First input argument is filename
      $filename = $argument;    # Stroing the filename
      print("Filename: $filename \n");
   }
   else{                        # Remaining arguments are search strings
      push @strings_to_search, $argument;       #Stroing in an array
      print("Search string $i: $argument \n");
   }

   $i++;    # increment the counter
}

# Checking if entered file exists or not.
open(INFILE, $filename) or die("\n Cannot open the input file $filename: $! \n\n");

# Search the file for strings (line by line)

my @data_file = ();             # array to store lines of files
$curr_line_index = 0;           # variable to keep track of current a line in a file

while (<INFILE>) {

   $curr_line = $_;             # Stores current line
   push @data_file, $curr_line; # Inserting at the end in the array

# For loop to check whether this line contains the string or not.
# If line contains the string, push the line number in string array, else
# move to next line.

   foreach $search_string (@strings_to_search){
      if(index($curr_line, $search_string) != -1){
         push @{$search_string}, $curr_line_index;
      }
   }
$curr_line_index++;     # Incrementing line count
}

close(INFILE); # Close the file

# -------------------------------------------------------------------
# Printing the string search report in following format!
# --------------------------------------------------------------------
#
#       Summary of hits on string searches in the file:
#
#       String Name:
#       Number of lines that contain string
#       Each line (with it's line number) containg string
#
#       **************************************************
#       ........
#       ........
#       ........
#
#       **************************************************
#       ........
# --------------------------------------------------------------------

print("\nSummary of hits on string searches in the file: \n");
print(STDOUT "\n*********************************************************************************** \n");

foreach $string (@strings_to_search){
   print("Searched String: $string \n");    # print the string name
   $no_of_matches = @{$string};         # total number of matches for string
   print("Number of lines that contain string '$string' : $no_of_matches\n\n"); # print total number of matches for this string

# Printing the lines that contains string
   foreach $entry (@{$string}){
      $line_to_print = $data_file[$entry];
      print(STDOUT "line ${\($entry+1)}: $line_to_print");
   }

   print(STDOUT "\n************************************************************************************* \n");
}



