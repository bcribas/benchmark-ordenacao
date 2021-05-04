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
#include <stdlib.h>
#include "ordenacaomacros.h"
#include "priority-queue.h"

static Item *pq;
static int N;

void PQinit(int maxN)
{
  pq=malloc(sizeof(Item)*maxN);
  N=0;
}

int PQempty()
{
  return N==0;
}

void PQinsert(Item v)
{
  pq[++N]=v;
  fixUp(pq,N);
}

Item PQdelmax()
{
  exch(pq[1],pq[N]);
  fixDown(pq,1,N-1);
  return pq[N--];
}

void fixUp(Item *pq, int k)
{
  while(k>1 && less(pq[k/2],pq[k]))
  {
    exch(pq[k],pq[k/2]);
    k=k/2;
  }
}

void fixDown(Item *pq, int k, int N)
{
  int j;
  while(2*k <= N)
  {
    j=2*k;
    if(j<N && less(pq[j],pq[j+1])) j++;
    if(!less(pq[k],pq[j])) break;
    exch(pq[k],pq[j]);
    k=j;
  }
}
