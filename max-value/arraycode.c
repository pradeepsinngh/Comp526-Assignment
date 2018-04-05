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
