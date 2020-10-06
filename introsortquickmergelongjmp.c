/*
 * Copyright(C) 2020, Bruno César Ribas <bruno.ribas@unb.br>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2.1 of the GNU Lesser General Public License
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it would be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */
#include <stdio.h>
#include <math.h>
#include <setjmp.h>
#include "introsortquickmergelongjmp.h"
#include "ordenacaomacros.h"
#include "insertionsort.h"
#include "mergesort.h"
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

void introsortquickmergelongjmp(Item *V,int l,int r)
{
  trapsize=2*((int)log2((double)(r-l+1)));
  setjmp(env);
  if(trapstop==0)
    quicksortM3(V,l,r,trapsize);

  if(trapstop==1)
  {
    fprintf(stderr,"trap/");
    mergesort(V,l,r);
  }
  else
    insertionsort(V,l,r);
}
