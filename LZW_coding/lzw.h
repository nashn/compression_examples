// lzw.h

// select dictionary size
#if !defined(BITS)
#define BITS 12
#endif

#if BITS == 12

// critical sizes for lzw
// codes like this are preset
#define PRESET_CODE_MAX 256
// this code terminates input
#define END_OF_INPUT    256
// reinitialized the dictionary
#define NEW_DICTIONARY  257
// first code we can use
#define STARTING_CODE   258
// 2 ^ BITS
#define MAX_CODE        4096

#define UNUSED_CODE     4096
// a prime # > MAX_CODE * 1.2
#define DICTIONARY_SIZE 5021

// all of these should be unsigned
// can hold MAX_CODE
typedef unsigned short CodeType;
// can hold DICTIONARY_SIZE
typedef unsigned short IndexType;
// used for statistics only
typedef unsigned long CountType;

#define SIGNATURE "LZW12"

// requires a 32-bit context
#elif BITS == 16
// codes like this are preset
#define PRESET_CODE_MAX 256
// this code terminates input
#define END_OF_INPUT    256
// reinitialized the dictionary
#define NEW_DICTIONARY  257
// an invalid code
#define UNUSED_CODE     258
// first code we can use
#define STARTING_CODE   259
// 2 ^ BITS
#define MAX_CODE        65536
// a prime # > MAX_CODE * 1.2
#define DICTIONARY_SIZE 81901L

typedef unsigned short CodeType;
typedef unsigned long IndexType;
typedef unsigned long CountType;

#define SIGNATURE "LZW16"

#else
#error Undefined BITS value!
#endif