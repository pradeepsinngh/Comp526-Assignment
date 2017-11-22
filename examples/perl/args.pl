#! /usr/bin/perl
 
# a program "args.pl" that experiments with
# pattern matching in a program's command line arguments
# where we suppose,
#
#       o the 1st comand line argument is a search pattern
#       o remaining command line args are a list of files
#                                               to search
# note, the program does not perform the indicated searches,
# it's really just for exploring the entries that results
# in the built-in array @ARGV[] in the light of wild-carding
# on the command line...

# this stuff can be tricky -- if you say
#
#      ./args.pl pattern blah
#
# then no doubt the size of @ARGV is 2. and $ARGV[0] = "pattern",
# $ARGV[1] = "blah". but if you say
#
#      ./args.pl pattern *.pl blah
#
# then the size of @ARGV is 9 (depending on folder contents)
# -- and $ARGV[1]  = "args.pl", $ARGV[2] = "grep.pl"... etc...
# WHY???

# follows -- grep.pl

 $numargs = @ARGV;
 print("number of command line args: $numargs\n");

 if ($numargs < 2) {
   print("usage: \$ args.pl pattern filename[s]\n");
   exit;
 }

# process (print) the arguments to this program:

 $i = 0;
 foreach $argument (@ARGV) {
   print("arg $i: $argument\n");
   $i++;
 }
 
