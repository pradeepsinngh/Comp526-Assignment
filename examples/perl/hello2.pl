#! /usr/bin/perl
 
# hello2.pl -- basic Perl "hello world" program... which shows
#              that Perl can be kind of strange... this program
#              adds "numbers" in 2 different ways...
#
# REMEMBER to make this file executable -- see hello.pl comments
#
#           $ chmod u+x hello2.pl

# next program: hello3.pl

 print("hello, world!\n");

# this also works...
 $hstr = "greetings, cruel world!\n";
 print("\n");
 print("$hstr");

# and so does this...
 $x = "3.0";
 $y = ".14159";
 $z = $x+$y;
 print("Pi = $z\n");

# and then since "everything" in Perl is a string (or, well see
# p.14 of Learning Perl, 4th ed., where it says, "Though you may
# think of numbers and strings as different things...") so we
# can "add" these together in a string context by using the
# string join operator "."
 $z = $x.$y;
 print("string-join Pi = $z\n");

 exit;    
