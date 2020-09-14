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
#include "ordenacao.h"

static void insertionsortH(Item *v,int l,int r,int h)
{
  for(int i=l+h;i<=r;i++)
  {
    int j=i; Item tmp=v[j];
    while(j>=l+h && less(tmp,v[j-h]))
    {
      v[j]=v[j-h];
      j-=h;
    }
    v[j]=tmp;
  }
}

void shellsort(Item *v,int l,int r)
{
  int h;
  int t=(r-l)+1;
  for(h=1;h<=(t-1)/9;h=3*h+1);
  for(;h>0;h/=3)
    insertionsortH(v,0,t-1,h);
}
