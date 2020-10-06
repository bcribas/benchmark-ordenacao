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
#include "insertionsort.h"
#include "quicksortinsertion.h"
#include "separa.h"

static void quicksort(Item *V,int l, int r)
{
  if (r-l<=30) return;
  int j=separa(V,l,r);
  quicksort(V,l,j-1);
  quicksort(V,j+1,r);
}

void quicksortinsertion(Item *V,int l,int r)
{
  quicksort(V,l,r);
  insertionsort(V,l,r);
}
