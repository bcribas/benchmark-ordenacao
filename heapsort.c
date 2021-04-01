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
#include "heapsort.h"
#include "ordenacaomacros.h"
#include "priority-queue.h"

void heapsort(Item *v, int l, int r)
{
	int k,N=r-l+1;
	Item *pq= v+l-1;
	for(k=N/2;k>=1;k--)
		fixDown(pq,k,N);
	while(N>1)
	{
		exch(pq[1],pq[N]);
		fixDown(pq,1,--N);
	}
}
