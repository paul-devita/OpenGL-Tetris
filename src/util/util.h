#ifndef _UTIL_H_
#define _UTIL_H_

typedef unsigned char ubyte;

/*
Returns the address of a statically allocated array containing the provided elements chronologically.
Not thread safe.
*/
float* util_asArray2f(float f1, float f2);

/*
Returns the address of a statically allocated array containing the provided elements chronologically.
Not thread safe.
*/
float* util_asArray3f(float f1, float f2, float f3);

/*
Returns the address of a statically allocated array containing the provided elements chronologically.
Not thread safe.
*/
float* util_asArray4f(float f1, float f2, float f3, float f4);

/*
Returns the address of a statically allocated array containing the provided elements chronologically.
Not thread safe.
*/
int* util_asArray2i(int i1, int i2);

/*
Returns the address of a statically allocated array containing the provided elements chronologically.
Not thread safe.
*/
int* util_asArray3i(int i1, int i2, int i3);

/*
Returns the address of a statically allocated array containing the provided elements chronologically.
Not thread safe.
*/
int* util_asArray4i(int i1, int i2, int i3);

#endif