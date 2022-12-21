#include "ordenacaomacros.h"
#include "insertionsort.h"
#include "mergesort.h"

void insertionsortmetades(Item *v,int l,int r)
{
  int meio=l+(r-l)/2;
  insertionsort(v,l,meio);
  insertionsort(v,meio+1,r);
  merge(v,l,meio,r);
}
