#include <stdio.h>
#include <math.h>
#include <setjmp.h>
#include "introsortquickheaplongjmp.h"
#include "ordenacaomacros.h"
#include "insertionsort.h"
#include "heapsort.h"
#include "separa.h"

int trapstop=0;
int trapsize=0;
jmp_buf env;
static void quicksortM3(Item *V,int l, int r,int rec)
{
  if (r-l<=32) return;

  if(rec==0)
  {
    trapstop=1;
    longjmp(env,1);
    return;
  }

  exch(V[(l+r)/2],V[r-1]);
  cmpexch(V[l],V[r-1]);
  cmpexch(V[l],V[r]);
  cmpexch(V[r-1],V[r]);


  int j=separa(V,l+1,r-1);
  quicksortM3(V,l,j-1,rec-1);
  quicksortM3(V,j+1,r,rec-1);
}

void introsortquickheaplongjmp(Item *V,int l,int r)
{
  trapsize=2*((int)log2((double)(r-l+1)));
  setjmp(env);
  if(trapstop==0)
    quicksortM3(V,l,r,trapsize);

  if(trapstop==1)
  {
    fprintf(stderr,"trap/");
    heapsort(V,l,r);
  }
  else
    insertionsort(V,l,r);
}
