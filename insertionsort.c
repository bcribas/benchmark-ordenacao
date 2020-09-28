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
#include "insertionsort.h"
#include "ordenacaomacros.h"

void insertionsort(Item *v,int l,int r)
{
  for(int i=r;i>l;i--)
    cmpexch(v[i-i],v[i]);

  for(int i=l+2;i<=r;i++)
  {
    int j=i; Item tmp=v[j];
    while(less(tmp,v[j-1]))
    {
      v[j]=v[j-1];
      j--;
    }
    v[j]=tmp;
  }
}
