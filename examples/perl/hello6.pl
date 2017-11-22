#! /usr/bin/perl

# a Perl program tat demonstrates the use of built-in split() to split
# a string scalar into an array of its component strings

# previous program, hello3.pl
# next program,     match.pl

# hello6.pl uses an array for a list of numbers...
# also, it computes the SUM of the provided numbers...

  $name = "Bud";
  print("OK, $name, let's do some math...\n");
  print("...give us a list of numbers to add, all on one line:\n");

# read the list of numbers from STDIN -- store them as one big
# long string in $_ -- where all the DEFAULT action happens (?!)
  $_ = <STDIN>;

# the LHS is an array -- but what's the INPUT to split()??
# (note, split()'s default delimiter is whitespace)
  @words = split();

# sum the component numbers using an iterative loop on the elements
# of the array -- "foreach element of the array, do commands..."
# -- how would you rewrite this loop as a standard -- C-like --
# for-loop ?? it's not hard, but this is still easier...
  $sum = 0.0;
  foreach $number (@words) { # for each _item_ in the array, do...
    $sum += $number;
    $sum2 .= $number;
  }

# recall, chomp() the newline off $_
  chomp($_);
  print("the (numeric) sum of $_ is:\n $sum\n");
  print("the (literal) sum of $_ is:\n $sum2\n");
