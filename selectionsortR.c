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

void selectionsortR(Item *v,int l,int r)
{
  if(l>=r) return;

  int min=l;
  for(int j=l+1;j<=r;j++)
    if(less(v[j],v[min]))
      min=j;
  exch(v[l],v[min]);
  selectionsortR(v,l+1,r);

}
