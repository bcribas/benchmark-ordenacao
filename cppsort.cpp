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
#include <stdlib.h>
#include <algorithm>
#include "ordenacaomacros.h"

using namespace std;

int compar(const void *a,const void *b)
{
  return less(*((Item*)a),*((Item*)b));
}

int main(void)
{
  int t;
  int r;
  r=scanf("%d",&t);
  Item *v=(Item*)malloc(t*sizeof(Item));
  for(int i=0;i<t;i++)
    r=scanf("%d",&v[i]);

  sort(v,&v[t]);

  for(int i=0;i<t;i++)
    r=printf("%d\n",v[i]);

  return 0;
}
