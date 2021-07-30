#ifndef __radixsortH__
#define __radixsortH__
#include "ordenacaomacros.h"
void radixsort(Item *,int,int);

#ifdef __radixsortonly__
#define sort(v,l,r) radixsort(v,l,r)
#endif

#endif
