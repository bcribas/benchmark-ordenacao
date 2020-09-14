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

void selectionsort(Item *v,int l,int r)
{
  for(int i=l;i<r;i++)
  {
    int min=i;
    for(int j=i+1;j<=r;j++)
      if(less(v[j],v[min]))
        min=j;
    exch(v[i],v[min]);
  }

}
