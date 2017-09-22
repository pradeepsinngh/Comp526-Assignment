Last login: Thu Sep 21 13:14:58 on ttys000
Pradeeps-MacBook-Pro:~ pradeepsingh$ ssh -l singh ophelia2
singh@ophelia2's password: 
Last login: Thu Sep 21 13:12:58 2017 from 146.244.35.37
[singh@ophelia2 ~]$ cd assing2
-bash: cd: assing2: No such file or directory
[singh@ophelia2 ~]$ ls
assign1  assign2
[singh@ophelia2 ~]$ cd assign2
[singh@ophelia2 assign2]$ ls
arraycode.c  maxvals  maxvals.c
[singh@ophelia2 assign2]$ vi arraycode.c












/* arraycode.c -- J. Otto, 9/6/17 -- a helper code to be
   compiled along with a separate main() program files. this
   file provides to main() pointers to external arrays along
   with an integer variable containing the size of the arrays.
   -- see /examples/week3/maxval2.c.                           */

/* this OBJECT module can be compiled (along with
   maxval2) code by doing:

     $ gcc -o maxval2 maxval2.c arraycode.c
*/

// pre-compilation string substitution macro -- see class notes
// instances of "SZ" below get replaced by "6" pre-compile...
#define SZ1 6
#define SZ2 8

// these variables must be declared as "extern" when referenced
// in other files (eg., maxval2.c)

//names, sizes, and values may change -- these are not advertised,
//and so should not be referred to directly in main() codes.
float floatvals1[SZ1] = {-100.0, 13.0, 0.0, 3.14, 12.99, -2.5};
"arraycode.c" 33L, 1215C
