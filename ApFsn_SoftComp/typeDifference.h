#include <stdint.h>
#include <stddef.h>

typedef char S1;           //-128 ~ 127
typedef short S2;          //-32768 ~ 32767
typedef int S4;            //-2147483648 ~ 2147483647
typedef unsigned char U1;  // 0 ~ 255
typedef unsigned short U2; // 0 ~ 65535
typedef unsigned int U4;   // 0 ~ 4294967295

// macro define
#define ON ((U1)1)
#define OFF ((U1)0)