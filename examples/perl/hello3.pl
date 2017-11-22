#! /usr/bin/perl

# "hello3.pl" -- a Perl program that
# accepts user input... otherwise it's kind of like hello2.pl

# remember to make your Perl program executable by doing:
#             $ chmod u+x hello.pl

# previous program: hello2.pl
# next program:     hello6.pl

# greeting to the user -- all scalar variables begin with "$"
  $greeting1 = "Hello...";          # <-- notice the ";"
  $greeting2 = "\nPlease enter your name:\n";

# string join w/ "." operator
  $greeting = $greeting1 . $greeting2;

  print("$greeting");

# grab the user input -- more specifically the next line of the...
# ...file...associated with this file handle...
  $name = <STDIN>;

# chomp() off the newline char -- note, it modifies the input!
  chomp($name);

# prompt the user for some input
  print("OK $name, let's do some math...\n");
  print("...enter 2 numbers to add... first number:\n");

# streamlined coding...
  chomp($a = <STDIN>);

  print("...second number:\n");
  chomp($b = <STDIN>);

  print("OK, the sum of your 2 numbers is:\n");
  $c = $a + $b;
  print("$c\n");

  print("OK, the (string) join of your 2 strings is:\n");
  $c = $a . $b;

  print("$c\n");
