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

int separaCORMEM(Item *V,int l,int r)
{
  Item c=V[r];
  int j=l;
  for(int k=l;k<r;k++)
    if(less(V[k],c))
    {
      exch(V[k],V[j]);
      j++;
    }
  exch(V[j],V[r]);
  return j;
}

int separaSEDGEWICK(Item *V,int l,int r)
{
  int i=l-1, j=r; Item v=V[r];
  for(;;)
  {
    while(less(V[++i],v));
    while(less(v,V[--j])) if(j==l) break;
    if(i>=j) break;
    exch(V[i],V[j]);
  }
  exch(V[i],V[r])
  return i;
}
