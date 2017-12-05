#
# File name: cpp.pl
# Date: 11/30/2017
# Author: Pradeep Singh
# Description: The program "cpp.pl" functions as a compiler pre-processor (CPP) in the follopwing ways:
#              it scans a text file indicated on the command line for special lines like the following
             
               #define target1 replace1
               #define target2 replace2
               .
               .
               .
 
#==========================================================================================
# Program starts here
#==========================================================================================

$numargs = @ARGV; # Total number of arguments

$filename = $ARGV[$size-1]; # filename = last input argument

# Checking for usage. We need 1 or 2 i/p arguments.
# If we are writing o/p to a file, we need just 1 i/p argument i.e. filename.
# If we are displaying o/p on command line, we need 2 i/p arguments
#                                           1. stdout   (1st argument)
#                                           2. filename (2nd argument)

if ($numargs < 1 or $numargs > 2) {
   print("Usage error encountered.");
   print("Either incorrect number of arguments are passed OR input arguments are passed incorrectly.");
   print("Usage: To print O/P in a $filename.cpp -- ./cpp.pl filename \n ");
   print("Usage: To print O/P on command line -- ./cpp.pl -stdout filename \n\n");
   exit;
}

# Check whether file exist or not
open(INFILE, $filename) or die("File $filename cannot be read: $! \n");

$new_line_char = "\n";
$line_no = 1;               # counter to count number of lines.
$search_string = "#define"; # string to be searched for building hash table.
my @lines_to_put = ();      # array to store changed lines in a new file.
my %hash_define;            # our hash table, that will contain keys and their associated values.

#=========================================================================================================
#
#========================================================================================================
# This loop reads the file contents and stores them in array.

while (<INFILE>) {                          # Checking if this line needs substitution with any of the keys
   foreach $entry (keys %hash_define) {     # If current line contains this entry then substitution is required
      if (/$entry/) {                       # Substituting all instances of this entry (key) with the hash value in current line
         s/$entry/$hash_define{$entry}/g;
       }
   }

   #Assuming that #define will be the first word of the line. The second word will be the
   #key and the remaining sentence (without newline character) is the value.

   if (/$search_string/) {
      chomp($curr_line = $_);              # Removes newline character
      @words = split(/ /,$curr_line);      # Splitting the words based on white space

      # Precaution! Do not process if:
      # (i) the line contains #define but its not the first word or
      # (ii) #define key value format is followed

      if ($words[0] ne $search_string or @words lt 3) {
         print("Improper use of #define is encountered in file '$filename' \n");
         print("line $line_no: $_ \n");
         print("Cannot store it in hash function. Moving forward! \n");
         print("Usage: \$ #define key value \n\n");
         push @lines_to_put, $_; #Inserting at the end in the array
      }
      else {    # Insert the key and value into the hash function
                # $hash_define{$words[1]} = $words[2];
         $curr_key = $words[1];  #Stroes the key
         $curr_value = join(" ", splice(@words, 2, @words));     # Stores the value of the key

         # Put key and its value in the hash function. Order is: #define key value
         $hash_define{$curr_key} = $curr_value;

         # If we have already put lines in lines_to_put array, recheck the array for
         # this key. It will reduce total number of string match searches because we
         # are comparing the lines only for a particular string (i.e. not for all keys
         # stored in hash_define hash).

         $line_count = 0;        # To track the index number of lines_to_put array
         foreach $output_line (@lines_to_put) {

            if (/$curr_key/){     # Substituting all instances of this entry (key)  with the hash value in current line
               (my $subs_line = $output_line) =~ s/$curr_key/$hash_define{$curr_key}/g;
               $lines_to_put[$line_count] = $subs_line;        #Updating the line in the array
            }
            $line_count++;  #Incrementing line count of the lines_to_put array
         }

         # Instead of the actual line, insert a blank line so that user can easily
         # see/compare the difference with the original file
         # push @lines_to_put, $new_line_char;     #Inserting new line in the array
      }

   }
# This line does not contain search string.
   # Insert this line in the lines_to_put array
   else {
      push @lines_to_put, $_; #Inserting at the end in the array
   }

   $line_no++;     #Incrementing the line count of the original file
 }

close(INFILE); #Closing the file

# Either store in the file or print on the console the output
if ($numargs eq 2){

    print("Printing output on the console \n");
    print(STDOUT "\n------------------------------------------------- \n\n");

    foreach $this_line (@lines_to_put) {
       print(STDOUT "$this_line");
    }
}
else {

   open(OUTFILE, '>', $filename.'.cpp') or die ("\nCannot open/create the file '$filename.cpp' to write the output: $! \n\n");
   print("Writing the output in '$filename.cpp' file.\n\n");

   foreach $this_line (@lines_to_put){
      print(OUTFILE "$this_line");
}

   close(OUTFILE); #Closing the file
