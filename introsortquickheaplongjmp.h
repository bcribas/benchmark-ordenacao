#ifndef __introsortquickheapLONGJMPH__
#define __introsortquickheapLONGJMPH__
#include "ordenacaomacros.h"

void introsortquickheaplongjmp(Item *V, int l, int r);

#ifdef __introsortquickheaplongjmponly__
#define sort(v,l,r) introsortquickheaplongjmp(v,l,r)
#endif

#endif
