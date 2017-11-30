#! /usr/bin/perl
# hash.pl -- scan a names file with format:
#  lname1:fname1:string1             (so lastname:firstname:string...)
#  lname2:fname2:string2  ... etc.
#
# -- build hash tables (%jack and %jill) keyed by lnameN which stores stringN
#    as the corresponding value -- but only for those entries where fnameN is
#    "jack" or "jill". assumes use of lower-case letters throughout.

# check for correct number of input parameters
  $size = @ARGV;
  if ( $size != 1) {
    print("usage: $ hash.pl filename\n");
    exit 0;
  }
  $fname = $ARGV[0];   # 1st (only) command-line argument...

  if ( ! open(NAMES, "$fname") ) {
    print("hash.pl: could not open file: $fname\n");
    print("------------------------------------------\n");
    print("usage: % hash.pl file-name\n");
    exit -1;
  }
# get the names...
  while ( <NAMES> ) {
    chomp($line = $_);

# does this line have "jack"?
    if ( /jack/ ) {
      @words = split(/:/,$line);
# make sure we found a FIRST name == jack
      if ($words[1] eq "jack" ) {
# key for hash is lastname, value is string
        $jack{$words[0]} = $words[2];
    } }
# maybe it has "jill"...
    if ( /jill/ ) {
      @words = split(/:/,$line);
# make sure we found a first name == jill
      if ($words[1] eq "jill" ) {
# key for hash is lastname, value is string
        $jill{$words[0]} = $words[2];
  } } }
  close(NAMES);

# print the new lists...
  print "\n";

  print "the JACK hash: \n";
  foreach $i (keys %jack) {
    print("jack $i -- $jack{$i}\n");
  }
  print "\n";

  print "the JILL hash: \n";
  foreach $i (keys %jill) {
    print("jill $i -- $jill{$i}\n");
  }
  print "\n";

