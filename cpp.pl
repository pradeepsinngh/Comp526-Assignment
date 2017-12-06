#! /usr/bin/perl
#
# Date: 11/30/2017
# Author: Pradeep Singh
# Description: The program "cpp.pl" functions as a compiler pre-processor (CPP) in the follopwing ways:
#              it scans a text file indicated on the command line for special lines like the following
#              .
#              .
#              .

#==========================================================================================
# Program starts here
#==========================================================================================

$newline = "\n";
$counter = 1;                 # counter to count number of lines.
$size = @ARGV;                # Total number of arguments.
$filename = $ARGV[$size-1];   # filename = last input argument.
$search = "#define";          # string to be searched for building hash table.
my @output_lines = ();        # array to store changed lines in a new file.
my %hash_table;               # our hash table, that will contain keys and their associated values.

#============================================================================================
# Checking the number of program command line arguments. We need 1 or 2 i/p arguments.
#=============================================================================================
# If we are writing o/p to a file, we need just 1 i/p argument i.e. filename.
#
# If we are displaying o/p on command line, we need 2 i/p arguments
#                                           1. stdout   (1st argument)
#                                           2. filename (2nd argument)
#
# Also, give usage info and terminates in a case usage problem is detected.
#

if ($size < 1 or $size > 2) {   # if less than 1 or greater than 2 argu are passed, display this message
   print("\nUsage error encountered.\n");
   print("Either incorrect number of arguments are passed OR input arguments are passed incorrectly.\n\n");
   print("Usage: To print o/p in a file --> ./cpp.pl filename \n");
   print("Usage: To print o/p on command line --> ./cpp.pl -stdout filename \n\n");
   exit;
}

# Checking if entered file exists or not.
open(INFILE, $filename) or die("File $filename cannot be read: $! \n");

#=========================================================================================================
# Looping -- Read file contents
#========================================================================================================
# This loop reads the file contents and stores them in array.

while (<INFILE>) {                          # Checking if this line needs substitution with any of the keys
   foreach $entry (keys %hash_table) {      # If current line contains this entry then substitution is required
      if (/$entry/) {                       # Substituting all instances of this entry (key) with the hash value in current line
         s/$entry/$hash_table{$entry}/g;
       }
   }

   if (/$search/) {
      chomp($line = $_);                    # Removes newline character
      @words = split(/ /,$line);            # Splitting the current line in words using split function

# We don't want to do substiution for keys (with values) in lines which starts with "#define".
# Also, we don't want to store them for writing in a file or printing to STDOUT.
# So, we will ignore all those lines which starts with "#define".

      if ($words[0] ne $search or @words lt 3) {
         print("Improper use of #define is encountered in file '$filename' \n");
         print("line $counter: $_ \n");
         print("Cannot store it in hash function. Moving forward! \n");
         print("Usage: \$ #define key value \n\n");
         push @output_lines, $_; #Inserting at the end in the array
      }
      else {
         $key = $words[1];                                # store key
         $value = join(" ", splice(@words, 2, @words));   # Store the value for every key
         $hash_table{$key} = $value; # building hash table/ function, putting key and it's value in hash
         $line_count = 0;        # counter for output_lines array
         foreach $output_line (@output_lines) {

            if (/$key/){                     # If there is key in this line, substitute it with the hash value.
               (my $subs_line = $output_line) =~ s/$key/$hash_table{$key}/g;
               $output_lines[$line_count] = $subs_line;        # updating the line in the array
            }
            $line_count++;                                     # increment the line count in array
         }
      }
   }
   else {                         # If this lines doesn't have "#define" put it in the array, @output_lines
      push @output_lines, $_;
   }
   $counter++;                    # increment the line count in filenmae
 }

close(INFILE);                    # closing the file

#==============================================================================================
# Writing/ Printing the results/ output
#===============================================================================================
# Depending upon i/p argument provided by user, either we will write result to a file
# or we will print it to STDOUT.
#
# If i/p arguments was: $ cpp.pl filename
#                       --> We will write result to a file called "filename.cpp".
#
# But if the program is run with optional flag, as in: cpp.pl -stdout filename
#                                          --> Then, we will write results to STDOUT.
#===============================================================================================

if ($size eq 2){
    print(STDOUT "\n=========================================================\n");
    print("Writing the result to STDOUT: \n");
    print(STDOUT "=========================================================\n");

    foreach $this_line (@output_lines) {
       print(STDOUT "$this_line");
    }
}
else {

   open(OUTFILE, '>', $filename.'.cpp') or die ("\nCannot open the file '$filename.cpp' to write the output: $! \n\n");
   print("\nThe Result has been written in '$filename.cpp'.\n");
   print("You can open '$filename.cpp' to see the result.\n");
   print("Type following command to open the file: vi $filename.cpp\n\n");

   foreach $this_line (@output_lines){
      print(OUTFILE "$this_line");
   }
}

close(OUTFILE);     # close the file
