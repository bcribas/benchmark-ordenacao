#ifndef __radixsort__
#define __radixsort__
#include "ordenacaomacros.h"
void radixsort(Item *,int,int);

#ifdef __radixsortonly__
#define sort(v,l,r) radixsort(v,l,r)
#endif

#endif