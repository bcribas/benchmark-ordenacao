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
#include "ordenacaomacros.h"
#include "quicksortM3insertion.h"
#include "insertionsort.h"
#include "separa.h"

static void quicksortM3(Item *V,int l, int r)
{
  if (r-l<=32) return;

  exch(V[(l+r)/2],V[r-1]);
  cmpexch(V[l],V[r-1]);
  cmpexch(V[l],V[r]);
  cmpexch(V[r-1],V[r]);


  int j=separa(V,l+1,r-1);
  quicksortM3(V,l,j-1);
  quicksortM3(V,j+1,r);
}

void quicksortM3insertion(Item *V,int l,int r)
{
  quicksortM3(V,l,r);
  insertionsort(V,l,r);
}
